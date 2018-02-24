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


#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>
#include <QString>
#include <QTcpSocket>
#include "QTcpSocket"
#include "../Utilities/Utility.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0, QString uName = "player1");
    ~Client();
    int getState();

   // void connectToHost(QString ipAddress, qint16 portNumber);
    QStringList getUsers();
    QTcpSocket* getClientSocket();
    void setUserName(QString playerName);
    QString getUserName();
signals:
    void stateChanged(QAbstractSocket::SocketState);
    void echoMessage(QString buffer);
    void chatMessage(QString text);
    void messageForCatan(QString msg);


    // --------------------CATAN CLIENT SIDE METHODS ---------- //



public slots:
    void clientChange(QAbstractSocket::SocketState state);
    void connectToHost(QString address, qint16 port);
    void startTransfer();
    void echo();
    void sendMessage(QString input);
    void gameChoice(QString input);
    void moveToGame(QString game);
    void robberCordsSend(int x, int y, int z, int robx, int roby);
    void sendOffer(QString a, QString b, QString c, QString d, QString e, QString f);
    void clientRequest(uint constructionType);
    void clientStructMeth(int butX, int butY, int x,int y,int z);
    void sendPlayable(int type);
    void rollDice();
    void resourceChosen(int type, int card);
    void endTurn();


    // ---------------------CATAN CLIENT SIDE METHODS ---------- //






private:
    QTcpSocket* clientSocket;
    QString username;
    QString gamePlaying;
};
#endif // CLIENT_H
