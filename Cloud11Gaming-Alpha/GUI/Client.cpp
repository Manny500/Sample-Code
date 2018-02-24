/** <Implementation of a QTCPSocket to provide a connection with codes to the server>
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

	
#include "Client.h"
#include <QRegExp>


/**
 * @brief Client::Client create the backend of a client for a baisc chat interaction
 * @param parent parent object, default null
 */
Client::Client(QObject *parent, QString uName) : QObject(parent)
{
    Utility::debugEnable();

    clientSocket = new QTcpSocket(this);
    username = uName;

    qDebug() << "Creating New QTcp Socket" << &clientSocket;
    connect(clientSocket, SIGNAL(connected()), this, SLOT(startTransfer()));
    connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(clientChange(QAbstractSocket::SocketState)));
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(echo()));
}

/**
 * @brief Client::~Client destructor
 */
Client::~Client()
{
    if(clientSocket->isOpen()){
        clientSocket->close();
    }
}

/**
 * @brief Client::clientChange when the client is changedthe state changed signal is emitted that in turn acts as a signal to the updateStatus in the CloudGaming class.
 * @param state
 */
void Client::clientChange(QAbstractSocket::SocketState state)
{
    emit stateChanged(state);
}

/**
 * @brief Client::echo when data is available for the client tcp socket. That data is read into a buffer array. At the \ of this the echoMessage signal is emitted. This is turn calls the incomingMessage method in the CloudGaming class.
 */
void Client::echo()
{
   QByteArray buffer = clientSocket->readAll();
    qDebug() << buffer;
    Utility::debug(buffer);
    QString g = QString::fromLocal8Bit(buffer);
    if(g.contains("says:")){
        emit chatMessage(g);
    }else if(g.contains("playcatancstats<catan>0")){
        emit echoMessage(g);
    }else if(g.contains("<catan>")){
        emit messageForCatan(g);
    } else{
        qDebug() << g;
        emit echoMessage(g);
    }
}
/**
 * @brief Client::connectToHost connects the particular socket to the server ip and port number.
 * @param ipAddress
 * @param portNumber
 */
void Client::connectToHost(QString ipAddress , qint16 portNumber)
{
    qDebug() << "Starting connection" << ipAddress << portNumber;
    QHostAddress address(ipAddress);
    qDebug() << "Host Address Accepted";
    clientSocket->connectToHost(address,2500);
    qDebug() << clientSocket->state();
}

/**
 * @brief Client::startTransfer this is when the client is first connected to the server. at this moment the first message is written to the clientSocket. This method has the format newcon<USERNAME>.
 */
void Client::startTransfer()
{
    qDebug() << clientSocket->state();
    qDebug() << "Connected to the server";
    QString createMessage = "newcon<";
    createMessage.append(username);
    createMessage.append(">");
    qDebug() << createMessage << " message about to send to server";
    clientSocket->write(createMessage.toLocal8Bit());
    Utility::debug("Talking");
}

/**
 * @brief Client::sendMessage this is when the client sends a chat message. This is a slot for the newMessage method. This method is seny in yhr following format. chatmg<USERNAME>message.
 * @param input
 */
void Client::sendMessage(QString input)
{
    qDebug() << "Transmitting:" << input;
    if(gamePlaying == "crazyg<"){

        QString message = "chatcr<";
        message.append(username);
        message.append(">");
        message.append(input);
        clientSocket->write(message.toLocal8Bit());

    }else if(gamePlaying == "catang<"){
        QString message = "chatca<";
        message.append(username);
        message.append(">");
        message.append(input);
        clientSocket->write(message.toLocal8Bit());
    }
}

/**
 * @brief Client::gameChoice choosing the game with the current user
 * @param input
 */
void Client::gameChoice(QString input)
{
    qDebug() << "Game Choice : " << input ;
    gamePlaying = input;

    QString createMessage = input;
    createMessage.append(username);
    createMessage.append(">");
    clientSocket->write(createMessage.toLocal8Bit());
    qDebug() << createMessage << " Decision to join a particular game made";
    Utility::debug("Joined Game");
}

/**
 * @brief Client::moveToGame switching the game
 * @param game
 */
void Client::moveToGame(QString game)
{
    qDebug() << game;
    game.append(username);
    game.append(">");
    clientSocket->write(game.toLocal8Bit());
    qDebug() << "play game command send";
    Utility::debug("Lets play lads!!!");
}

/**
 * @brief Client::getState this gets the state of the socket
 * @return
 */
int Client::getState()
{
    return clientSocket->state();
}

/**
 * @brief Client::setUserName this gets the username
 * @param playerName
 */
void Client::setUserName(QString playerName)
{
    this->username = playerName;
}

/**
 * @brief Client::getClientSocket gets client socket
 * @return
 */
QTcpSocket* Client::getClientSocket()
{
    return clientSocket;
}


// -----------------------------------------------------------------CATAN METHODS -------------------------------------------------------------------/


void Client::rollDice(){
    QString msg = "rodice<";
    msg.append("catan>");
    clientSocket->write(msg.toLocal8Bit());

    qDebug() << msg;
}

void Client::robberCordsSend(int x, int y, int z, int robx, int roby){

    QString msg = "robcod<catan>";
    msg.append(QString::number(x));
    msg.append(",");
    msg.append(QString::number(y));
    msg.append(",");
    msg.append(QString::number(robx));
    msg.append(",");
    msg.append(QString::number(roby));

    clientSocket->write(msg.toLocal8Bit());
}


void Client::clientRequest(uint constructionType){
    QString message = "reques<";
    message.append(username);
    message.append(">");
    message.append(QString::number(constructionType));
    clientSocket->write(message.toLocal8Bit());
}

void Client::clientStructMeth(int butX, int butY, int x, int y, int z){
    QString message = "struct<";
    message.append(username);
    message.append(">");
    message.append(QString::number(butX));
    message.append(",");
    message.append(QString::number(butY));
    message.append(",");
    message.append(QString::number(x));
    message.append(",");
    message.append(QString::number(y));
    message.append(",");
    message.append(QString::number(z));
    qDebug() << message;
    clientSocket->write(message.toLocal8Bit());
}

void Client::sendOffer(QString a, QString b, QString c, QString d, QString e, QString f){
    QString message = "soffer<";
    message.append(username);
    message.append(">");
    message.append(a);
    message.append(",");
    message.append(b);
    message.append(",");
    message.append(c);
    message.append(",");
    message.append(d);
    message.append(",");
    message.append(e);
    message.append(",");
    message.append(f);
    qDebug() << message;
    clientSocket->write(message.toLocal8Bit());
}
\

void Client::sendPlayable(int type){
    QString message = "playab<catan>";
    message.append(QString::number(type));
    qDebug() << message;
    clientSocket->write(message.toLocal8Bit());
}

void Client::resourceChosen(int type,int card){
    QString message = "resour<catan>";
    message.append(QString::number(type));
    message.append(",");
    message.append(QString::number(card));
    qDebug() << message;
    clientSocket->write(message.toLocal8Bit());
}


void Client::endTurn(){
    QString message = "enturn<catan>";
    qDebug() << message;
    clientSocket->write(message.toLocal8Bit());
}

QString Client::getUserName(){
    return username;
}
