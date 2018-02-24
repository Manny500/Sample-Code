#include "Server.h"
#include <QTcpSocket>
#include <QRegExp>

Server::Server(QObject *parent) : QObject(parent){
    Utility::debugEnable();
    catanGameBeingPlayed = false;
    crazyGameBeingPlayed = false;
    allCatanUsers = "catanplayers";
    allUsers = "onlineplayers";

}

// destructor of the server. just closes the server.
Server::~Server(){
    server.close();
}

// int start method for the server. conencts the newConnection signal to the acceptConnection slot. newConnection is emitted when there the QTcpServer server connects to a connection.
int Server::start(){
    connect(&server, SIGNAL(newConnection()),this, SLOT(acceptConnection()));
    // connects the signal end connection to the slot sendUserList.
    connect(this, SIGNAL(endConnection()), this , SLOT(sendUserList()));
    // server listens at the any address and the port number of 2500.
    server.listen(QHostAddress::Any, 2500);
    qDebug() << "Server is Listening on port" << 2500;
    // emits listening signal
    emit listening();
    qDebug() << "Emitted connected signal";
    Utility::debug("started");
    // server is listening
    return server.isListening() ? 1: 0;
}

// int stop that closes the server. and returns wheather the server is listening or not.
int Server::stop(){
    server.close();
    return server.isListening() ? 0 : 1;
}
// accept connection method that connects to the next connection. looks for the new pending connections.
void Server::acceptConnection(){
    currClient = server.nextPendingConnection();

    // calls new connection method. This method just adds the socket to the Qlist of all clients.
    qDebug() << " New connection connected";
    newConnection(currClient);
    // connects the new currClient's signal readyRead() to the slot here called startRead();
    connect(currClient, SIGNAL(readyRead()), this, SLOT(startRead()));

}

// new connection method adds the new client to the Qlist of sockets called clients and to the Qmap of clients and usernames.
void Server::newConnection(QTcpSocket *socket){
    clients.append(socket);
    qDebug() << clientCount();
}

// start read method is called when the readyRead method is emitted. readyRead is called when there is data at the any of the sockets in the client list. This message will mo
void Server::startRead(){

    qDebug() << "There is something to be read";
    // buffer to hold the data that will be read in.

    //char *buffer[1024] = {0};
    char* buffer;
    // for all the clients in the list it looks for the client with any data available.

    for(int i = 0; i < clients.size(); i++){
        currClient = clients.at(i);
        if(currClient->bytesAvailable() > 0){
            qDebug() << "Data available at one of the clients";
            break ;
        }
    }
    Utility::debug("Reading");


    // read the data from that client socket into the buffer.
    QByteArray datain = currClient->readAll();
    buffer = datain.data();
    qDebug() << QString::fromLocal8Bit(buffer);


    userName = Utility::username(buffer);
    taskCode = Utility::opcode(buffer);
    message = Utility::immediate(buffer);

    qDebug() << " task : " << taskCode;
    qDebug() << " username : " << userName;

    // if the taskcode is newcon then this is a new client connected. Therefore, we need to include it in the list of client sockets and also in the usermap
    qDebug() << taskCode;
    if(taskCode == "newcon"){
            users[currClient] = userName;
            qDebug() << "someone has joined the group";
            qDebug() << clientCount();
           // sendUserList();
            allUsers.append(",");
            allUsers.append(userName);
            broadcast(allUsers, "onlineplayers");
        }
        else if(taskCode == "catang"){
            catanUsers[currClient] = userName;

            catanClients.append(currClient);
            allCatanUsers.append(",");
            allCatanUsers.append(userName);

            //sendCatanUserList();
            broadcast(allCatanUsers, "catanplayers");
        }
        else if(taskCode == "crazyg"){
             crazyUsers[currClient] = userName;
             crazyClients.append(currClient);
             sendCrazyUserList();
             broadcast(allCrazyUsers, "crazyplayers");
        }
        else if(taskCode == "chatca"){
            qDebug() << "Message in from" << userName << message;
            broadcastChat("catan",message, userName);
        }
        else if(taskCode == "chatcr"){
            qDebug() << "Message in from" << userName << message;
            broadcastChat("crazy",message,userName);
        }
        else if(taskCode == "pcatan"){
            qDebug() << " Play catan command to be sent to everyone";
            catanGame = new Catan();
            catanGame->staticSettings();
            catanGame->startProgress();
            catanGame->buildGlossary();
            catanGame->setActualPlayers(4);

            catanGame->buildPlayerGroups();
            setCatanPlayers();
            catanGame->buildComponentStacks();
            catanGame->buildPhysicalSpaces();
            catanGame->startGame();

            qDebug() << allCatanUsers;
            currPlayerIndex = 0;
            broadcastPlayGame("playcatan", "server");
            QString stats = QString::fromStdString(catanGame->refreshStats());
            qDebug() << stats ;
            broadcastStats(stats);
        }
        else if(taskCode == "reques"){

            int affordVal = catanGame->affordable(message.toUInt());
            qDebug() << "Afford Value :"  << affordVal;

            if(affordVal == 1 && message == "3"){
                catanGame->buyDevelopment();
                broadcastStats(QString::fromStdString(catanGame->refreshStats()));

            }else{

            constructionType = message.toUInt();
            QString a = "reques<catan>";
            a.append(QString::number(catanGame->affordable(message.toUInt())));

            a.append(".");
            a.append(message);
            a.append(".");
            currClient->write(a.toLocal8Bit());

            broadcastCatanMoves(a);

            }

          }

        else if(taskCode == "struct"){
            QStringList a = message.split(",");
            QString butX = a.at(0);
            QString butY = a.at(1);
            int x = a.at(2).toInt();
            int y = a.at(3).toInt();
            int z = a.at(4).toInt();

            qDebug() << x  << y  << z;

            QString b = QString::number(catanGame->placeConstruction(x,y,z,constructionType));

            QString message = "struct<catan>";             
            message.append(b);
            message.append(".");
            message.append(butX);
            message.append(".");
            message.append(butY);
            message.append(".");
            message.append(QString::number(constructionType));
            message.append(".");
            message.append(QString::number(z));
            message.append(".");
            message.append(QString::number(catanGame->progressControl->timeTracker->turn));
            message.append(".");

            for(int i = 0;i < 4; i++){
                catanClients.at(i)->write(message.toLocal8Bit());
                QString debugMsg = "Drawing to all";
                qDebug() << "drawing to all";

                debugMsg.append(message);
                Utility::debug(debugMsg);
            }
            broadcastStats(QString::fromStdString(catanGame->refreshStats()));
        }

        else if(taskCode == "rodice"){
            unsigned int rollValue = catanGame->rollDice();
            QString msg = "rodice<catan>";
            msg.append(QString::number(rollValue));
            msg.append(".");
            currClient->write(msg.toLocal8Bit());
            broadcastStats(QString::fromStdString(catanGame->refreshStats()));
            qDebug() << msg;
        }

        else if(taskCode == "robcod"){
            QStringList cords = message.split(",");

            int x = cords.at(0).toInt();
            int y = cords.at(1).toInt();

            qDebug() << "robcod is carried out";
            catanGame->moveRobber(x,y);

            QString robberMessage = "robcod<catan>";
            robberMessage.append(cords.at(2));
            robberMessage.append(".");
            robberMessage.append(cords.at(3));
            robberMessage.append(".");

            qDebug() << robberMessage;
            for(int i = 0; i < 4; i++){
                catanClients.at(i)->write(robberMessage.toLocal8Bit());
            }
            broadcastStats(QString::fromStdString(catanGame->refreshStats()));
        }

        else if(taskCode == "soffer"){
            QStringList resources = message.split(",");
            catanGame->bulkSendResources(catanGame->progressControl->timeTracker->turn,resources.at(5).toUInt(),resources.at(0).toUInt(),resources.at(1).toUInt(),
                                         resources.at(2).toUInt(),resources.at(3).toUInt(),resources.at(4).toUInt());

            broadcastStats(QString::fromStdString(catanGame->refreshStats()));
        }
        else if(taskCode == "playab"){
            int type = message.toInt();
            if(type == 0){
                if(catanGame->playKnight() == 1){
                    QString msg = "canrob<catan>";
                    currClient->write(msg.toLocal8Bit());
                    broadcastStats(QString::fromStdString(catanGame->refreshStats()));
                }
            }else if(type == 2){
                if(catanGame->playRoadBuilding() == 1){
                    broadcastStats(QString::fromStdString(catanGame->refreshStats()));
                }
            }else if(type == 4){
                if(catanGame->playVictoryPoint() == 1){
                    broadcastStats(QString::fromStdString(catanGame->refreshStats()));
                }
            }
        }
        else if(taskCode == "resour"){
            int type = message.split(",").at(0).toInt();
            int card = message.split(",").at(1).toInt();
            if(card == 0){
                catanGame->playYOP(type);
                broadcastStats(QString::fromStdString(catanGame->refreshStats()));
            }
            else if(card == 1){
                catanGame->playMonopoly(type);
                broadcastStats(QString::fromStdString(catanGame->refreshStats()));
           }
    }

        else if(taskCode == "enturn"){
            currClient->write("enturn<catan>");
            catanGame->endTurn();
            currPlayer = catanGame->accessOverride->playerAccess;
            currPlayerIndex = catanGame->progressControl->timeTracker->turn;
            currClient = catanClients.at(currPlayerIndex);

            currClient->write("yoturn<catan>");
            broadcastStats(QString::fromStdString(catanGame->refreshStats()));
        }
        qDebug() << buffer;
        Utility::debug(userName);
        Utility::debug(taskCode);
        Utility::debug(message);
    }



void Server::setCatanPlayers(){
    QStringList catanTemp = allCatanUsers.split(",");
    catanTemp.removeFirst();
    qDebug() << catanTemp;
    for(unsigned int i = 0; i < 4; i++){
        qDebug()  << i << "counter";
        qDebug() << catanTemp.at(i);
       catanGame->setPlayerName(i,catanTemp.at(i).toStdString());
    }
}

void Server::setCrazyPlayers(){
    QStringList crazyTemp = allCrazyUsers.split(",");
    qDebug() << crazyTemp;
    int size = crazyUsers.size();
    for(int i = 0; i < size; i++){
        crazyGame->setPlayerID(i,crazyTemp.at(i).toStdString(),i);
    }
}

void Server::broadcast(QString msg, QString uname){
    QString message = uname;
    message.append(" ");
    message.append(msg);
    qDebug() << message;
    qDebug() << allUsers;
    for(int i=0;i<clients.size();i++){
        currClient = clients.at(i);
        currClient->write(msg.toLocal8Bit());
    }
    QString debugMsg = "Broadcast";
    debugMsg.append(message);
    Utility::debug(debugMsg);
}

void Server::broadcastChat(QString game, QString msg, QString uname){
    QString message = uname;
    message.append(" says:");
    message.append(msg);

    if(game == "catan"){
        for(int i=0;i<catanClients.size();i++){
            currClient = catanClients.at(i);
            currClient->write(message.toLocal8Bit());
        }
    }
    else if(game == "crazy"){
       for(int i=0;i<crazyClients.size();i++){
           currClient = crazyClients.at(i);
           currClient->write(message.toLocal8Bit());
        }
    }
    QString debugMsg = "Broadcast";
    debugMsg.append(message);
    Utility::debug(debugMsg);
}

void Server::broadcastPlayGame(QString msg, QString uname){
    if(msg == "playcatan"){
       QString message = "playcatan";
       qDebug() << msg;
       for(int i=0;i<catanClients.size();i++){
          message.prepend(QString::number(i));
          currClient = catanClients.at(i);
          currClient->write(message.toLocal8Bit());
          message.remove(QString::number(i));
          qDebug() << message;
        }
        QString debugMsg = "Broadcast";
        debugMsg.append(message);
        Utility::debug(debugMsg);

    }
    else if(msg == "playcrazy"){
        QString message = "<";
        message.append(uname);
        message.append(">");
        message.append(",");
        message.append(msg);

        for(int i=0;i<crazyClients.size();i++){
            currClient = crazyClients.at(i);
            currClient->write(message.toLocal8Bit());
        }
        QString debugMsg = "Broadcast";
        debugMsg.append(message);
        Utility::debug(debugMsg);
    }
}

void Server::endConnection(QTcpSocket *socket, QString userLeft){

    qDebug() << "Removed : " << clients.removeAll(socket);
    QString msg = userLeft;
    msg.append(" has left");
    QString debugMsg = "End connection";
    debugMsg.append(userLeft);
    Utility::debug(debugMsg);
}

QString Server::getTask(){
    return taskCode;
}

QString Server::getMessage(){
    return message;
}

QString Server::getUsername(){
    return userName;
}

void Server::sendUserList()
{
    QStringList userList;
    allUsers = "onlineplayers,";
    foreach(QString user, users.values())
        userList << user;
    allUsers.append(userList.join(","));
}

void Server::sendCatanUserList(){
    QStringList userList1;
    allCatanUsers = "catanplayers,";
    foreach(QString user, catanUsers.values())
        userList1 << user;
    allCatanUsers.append(userList1.join(","));
    qDebug() << userList1 << "qwerty";
}

void Server::sendCrazyUserList()
{
    QStringList userList2;
    allCrazyUsers = "crazyplayers,";
    foreach(QString user, crazyUsers.values())
        userList2 << user;
    allCrazyUsers.append(userList2.join(","));
}

int Server::clientCount(){
    return clients.size();
}




// ------------------------------ BROADCAST CATAN MOVES ----------------------------------------------------------------------- //

void Server::broadcastCatanMoves(QString msg){

    for(int i = 0 ; i < 4; i++ ){
        catanClients.at(i)->write(msg.toLocal8Bit());
        QString debugMsg = "Construction buy affordable";
        debugMsg.append(msg);
        Utility::debug(debugMsg);
    }
}

void Server::broadcastStats(QString stats){
    QString statString = "cstats<";
    statString.append("catan");
    statString.append(">");
    statString.append(stats);
    qDebug() << statString;
    catanClients.at(currPlayerIndex)->write(statString.toLocal8Bit());
    QString debugMsg = "Broadcast stats";
    debugMsg.append(statString);
    Utility::debug(debugMsg);
}

