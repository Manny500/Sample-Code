/** <Implementing a server for clients to chat and play games>
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


#ifndef __Server_H__
#define __Server_H__

#include <QtCore/QString>
#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>
#include "../Utilities/Utility.h"
#include "../Games/Crazy/Crazy-Game/Crazy.h"
#include "../Games/Catan/Catan-Game/Catan.h"


class Server : public QObject
{
    Q_OBJECT

    public:
        Server(QObject *parent=0);
        ~Server();

        int start();
        int stop();
        int clientCount();

        void countUpdate();

        QString getTask();
        QString getMessage();
        QString getUsername();

        void sendUserList();
        void sendCatanUserList();
        void sendCrazyUserList();

    signals:
        void listening();

    private slots:
        void acceptConnection();
        void startRead();

    private:
        QTcpServer server;
        QTcpSocket* currClient;

        QList<QTcpSocket*> clients;
        QList<QTcpSocket*> catanClients;
        QList<QTcpSocket*> crazyClients;

        QMap<QTcpSocket*,QString> catanUsers;
        QMap<QTcpSocket*,QString> crazyUsers;
        QMap<QTcpSocket*,QString> users;

        QString taskCode;
        QString message;
        QString userName;

        QString allUsers;
        QString allCatanUsers;
        QString allCrazyUsers;


        Crazy *crazyGame;
        Catan *catanGame;
        bool catanGameBeingPlayed;
        bool crazyGameBeingPlayed;

        void broadcast(QString msg, QString uname);
        void broadcastChat(QString game, QString msg, QString uname);
        void broadcastPlayGame(QString msg, QString uname);
//        void broadcastGameMoves(QString game, QString msg, QString uname);
        void broadcastCatanMoves(QString msg);
        void broadcastStats(QString stats);

        void newConnection(QTcpSocket *socket);
        void toClients(QString message, QString username);
        void endConnection(QTcpSocket* socket, QString userName);
        void setCatanPlayers();
        void setCrazyPlayers();

        Player *currPlayer;
        unsigned int currPlayerIndex;
        unsigned int constructionType;
};

#endif

