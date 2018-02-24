/** <Window to choose IP port number and username to connect to the server>
* Copyright (C) <2015-04-17>  <Manuel Tenorio>

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "CloudGaming.h"
#include "ui_CloudGaming.h"
#include "CatanFace.h"
#include "ui_CatanFace.h"
#include "CrazyFace.h"
#include "ui_CrazyFace.h"
#include <QTcpSocket>
#include <QListWidget>
#include <QListWidgetItem>
#include "qdebug.h"

/**
 * @brief CloudGaming::CloudGaming constructor for cloud gaming, essentially sets up the game and connects everything
 * @param parent
 * @param ip
 * @param port
 * @param userName
 */
CloudGaming::CloudGaming(QWidget *parent, QString ip, qint16 port, QString userName) :
    QDialog(parent),
    ui(new Ui::CloudGaming)
{

    ui->setupUi(this);
    client = new Client(this,userName);
    client->connectToHost(ip,port);

    connect(this, SIGNAL(newMessage(QString)), client, SLOT(sendMessage(QString)));
    connect(client, SIGNAL(stateChanged(QAbstractSocket::SocketState)),this, SLOT(updateStatus(QAbstractSocket::SocketState)));
    connect(client, SIGNAL(echoMessage(QString)),this, SLOT(incomingMessage(QString)));
    connect(this, SIGNAL(gameChoiceMade(QString)), client, SLOT(gameChoice(QString)));
    connect(this, SIGNAL(playGame(QString)), client, SLOT(moveToGame(QString)));

    ui->gameInterface->setCurrentIndex(1);

    ui->playCatan->setEnabled(false);
    ui->playCrazy->setEnabled(false);

    QPixmap pixBackground(":/new/Images/Images/homer.jpg");
    QPixmap scaledBack = pixBackground.scaled(396, 556, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    ui->backRight->setPixmap(scaledBack);

    QPixmap pixCat(":/new/Images/Images/fuschia.png");
    QPixmap scaledCat = pixCat.scaled(805, 556, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    ui->catanBackground->setPixmap(scaledCat);

    QPixmap pixCra(":/new/Images/Images/homer.jpg");
    QPixmap scaledCra = pixCra.scaled(805, 556, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    ui->crazyBackground->setPixmap(scaledCra);


    catanPlayers = new QStringList();

}

/**
 * @brief CloudGaming::~CloudGaming destructor
 */
CloudGaming::~CloudGaming()
{
    delete ui;
    delete client;
}

/**
 * @brief CloudGaming::connectTo Connects to the host with the address and the port number.
 * @param address
 * @param portNumber
 */
void CloudGaming::connectTo(QString address, qint16 portNumber)
{
    qDebug() << "Got a client at : " << &client;
    client->connectToHost(address,portNumber);
}

/**
 * @brief CloudGaming::incomingMessage The incoming message from the server comes here.
 * @param msg
 */
void CloudGaming::incomingMessage(QString msg)
{
    qDebug() <<"Incoming Message From Server";
    qDebug() << msg;

    QStringList users = msg.split(",");
    QString first = users.first();

    qDebug() << first;
    if(first == "onlineplayers"){
        qDebug() << "Server confirms list of online players";
        showOnlinePlayers(users);
    }
    else if(first == "catanplayers"){
        qDebug() << "Server confirms list of catan players";
        showCatanPlayers(users);
    }
    else if(first == "crazyplayers"){
        qDebug() << "Server confirms list of crazy players";
        showCrazyPlayers(users);
    }
    else if(first.mid(1,9) == "playcatan" || first.mid(1,23) == "playcatancstats<catan>0"){
        qDebug() << users.first();
        int color = first.mid(0,1).toInt();

        qDebug() << "player names : " << catanPlayers;

        CatanFace *catanUI = new CatanFace(this,client,color,catanPlayers);
        catanUI->show();
        if(first.mid(1,23) == "playcatancstats<catan>0"){
            users.removeFirst();
            qDebug() << users << "diamond";

            /* left panel */
            catanUI->ui->p1road->setText( users.at(0));
            catanUI->ui->p1knight->setText(users.at(1));
            catanUI->ui->p1victory->setText(users.at(2));
            catanUI->ui->p2road->setText( users.at(3));
            catanUI->ui->p2knight->setText(users.at(4));
            catanUI->ui->p2victory->setText(users.at(5));
            catanUI->ui->p3road->setText( users.at(6));
            catanUI->ui->p3knight->setText(users.at(7));
            catanUI->ui->p3victory->setText(users.at(8));
            catanUI->ui->p4road->setText( users.at(9));
            catanUI->ui->p4knight->setText(users.at(10));
            catanUI->ui->p4victory->setText(users.at(11));

            catanUI->ui->brickResource->setText(users.at(12));
            catanUI->ui->woolResource->setText(users.at(13));
            catanUI->ui->oreResource->setText(users.at(14));
            catanUI->ui->grainResource->setText(users.at(15));
            catanUI->ui->lumberResource->setText(users.at(16));
            catanUI->ui->label_2->setText(users.at(17));
            catanUI->ui->label_4->setText(users.at(18));
            catanUI->ui->label_3->setText(users.at(19));
            catanUI->ui->label_5->setText(users.at(20));
            catanUI->ui->label_22->setText("0");

        }
        ui->gameInterface->close();
        this->hide();
    }
  }


/**
 * @brief CloudGaming::showOnlinePlayers shows which players are currently online
 * @param users
 */
void CloudGaming::showOnlinePlayers(QStringList users)
{

    qDebug() << users;
    ui->online->clear();
    users.removeAt(0);
    qDebug() << users << " these are the users";
    foreach(QString user, users){
        ui->online->addItem(new QListWidgetItem(user));
    }
}

/**
 * @brief CloudGaming::showCatanPlayers shows which players have joined the catan game
 * @param users
 */
void CloudGaming::showCatanPlayers(QStringList users)
{

    qDebug() << users;
    ui->listWidget->clear();
    users.removeAt(0);
    foreach(QString user, users){
        ui->listWidget->addItem(new QListWidgetItem(user));
        if(users.size() == 4){
            ui->playCatan->setEnabled(true);
            catanPlayers->append(users.at(0));
            catanPlayers->append(users.at(1));
            catanPlayers->append(users.at(2));
            catanPlayers->append(users.at(3));
            qDebug() << users;
        }else{
            ui->playCatan->setEnabled(false);
        }

    }
    qDebug() << users;
}

/**
 * @brief CloudGaming::showCrazyPlayers shows which players have joined the crazy game
 * @param users
 */
void CloudGaming::showCrazyPlayers(QStringList users)
{

    qDebug() << users;
    ui->listWidget_2->clear();
    users.removeAt(0);
    foreach(QString user, users){
        ui->listWidget_2->addItem(new QListWidgetItem(user));
    }
    if(users.size() >= 2 && users.size() < 10){
        ui->playCrazy->setEnabled(true);
    }
    else{
        ui->playCrazy->setEnabled(false);
    }
}

/**
 * @brief CloudGaming::startClose start close method. emits closing().. and starts to close the ui.

 */
void CloudGaming::startClose()
{
    emit closing();
    this->close();
}

/**
 * @brief CloudGaming::updateStatus update the status of the socket.
 * @param state
 */
void CloudGaming::updateStatus(QAbstractSocket::SocketState state)
{
    switch(state){
    case QAbstractSocket::UnconnectedState :
    {
        qDebug() << " Warning not connected to server";
        error_message.exec();
        this->close();
        break;
    }
    case QAbstractSocket::ConnectingState :
    {
        qDebug() << " Connecting to server";
        break;
    }
    case QAbstractSocket::ConnectedState :
    {
        qDebug() << " Connected to server";
        break;
    }
    case QAbstractSocket::HostLookupState :
    {
        qDebug() << " Search for host ";
        break;
    }
    case QAbstractSocket::BoundState:
    {
        qDebug() << " Bound to port ";
        break;
    }
    case QAbstractSocket::ListeningState:
    {
        qDebug() <<"Listening to port";
        break;
    }
    case QAbstractSocket::ClosingState:
    {
        qDebug() << "Warning connection closing";

        break;
    }
   }
}

/**
 * @brief CloudGaming::getMessage get the messages here from the ui. this method should be expanded when we add additional functionality such as the use of catan buttons.
 */
void CloudGaming::getMessage()
{
    QString message = "Random Text";
    if(message == NULL) return;

    qDebug() << message << "Get Text Here As Message From Line";
    emit newMessage(message);
}

/**
 * @brief CloudGaming::getPlayerName get the player name on this gui
 * @return
 */
QString CloudGaming::getPlayerName()
{
    return playerName;
}

/**
 * @brief CloudGaming::getServerAddress get the server address of the server
 * @return
 */
QString CloudGaming::getServerAddress()
{
    return serverAddress;
}

/**
 * @brief CloudGaming::getPortNumber get the port number you are connecting to
 * @return
 */
qint16 CloudGaming::getPortNumber()
{
    return portNumber;
}

/**
 * @brief CloudGaming::on_joinCatan_clicked what to do when catan is clicked
 */
void CloudGaming::on_joinCatan_clicked()
{
   ui->gameInterface->setCurrentIndex(2);
   QString gameToPlay = "catang<";
   emit gameChoiceMade(gameToPlay);
}

/**
 * @brief CloudGaming::on_joinCrazy_clicked what to do when crazy is clicked
 */
void CloudGaming::on_joinCrazy_clicked()
{
    ui->gameInterface->setCurrentIndex(3);
    QString gameToPlay = "crazyg<";
    emit gameChoiceMade(gameToPlay);
}

/**
 * @brief CloudGaming::on_playCatan_clicked what to do when play catan is clicked
 */
void CloudGaming::on_playCatan_clicked()
{
    ui->gameInterface->hide();
    emit playGame("pcatan<");

}

/**
 * @brief CloudGaming::on_playCrazy_clicked what to do when play crazy is clicked
 */
void CloudGaming::on_playCrazy_clicked()
{
    ui->gameInterface->hide();
    emit playGame("pcrazy<");
}
