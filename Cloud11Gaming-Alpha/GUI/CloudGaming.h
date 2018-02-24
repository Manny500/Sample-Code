#ifndef CLOUDGAMING_H
#define CLOUDGAMING_H

#include <QDialog>
#include <QMessageBox>
#include "Client.h"


namespace Ui {
class CloudGaming;
}

class CloudGaming : public QDialog
{
    Q_OBJECT

public:
    explicit CloudGaming(QWidget *parent = 0, QString ip = "127.0.0.1", qint16 port = 2500 , QString userName = "Me");
    ~CloudGaming();
    QString getPlayerName();
    QString getServerAddress();
    qint16 getPortNumber();
    void connectTo(QString address, qint16 portNumber);
    void showOnlinePlayers(QStringList playerList);
    void showCrazyPlayers(QStringList playerList);
    void showCatanPlayers(QStringList playerList);

signals:
    void newMessage(QString message);
    void closing();
    void gameChoiceMade(QString choice);
    void playGame(QString game);

private slots:
    void getMessage();
    void updateStatus(QAbstractSocket::SocketState state);
    void incomingMessage(QString msg);
    void startClose();
    void on_joinCatan_clicked();
    void on_joinCrazy_clicked();
    void on_playCatan_clicked();
    void on_playCrazy_clicked();

private:
    QString playerName;
    QString serverAddress;
    QString gameToPlay;

    qint16 portNumber;
    Ui::CloudGaming *ui;
    Client *client;
    QMessageBox error_message;

    QStringList* catanPlayers;

};

#endif // CLOUDGAMING_H
