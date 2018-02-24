#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QTcpSocket>
#include "Client.h"

namespace Ui {
class Chat;
}

class Chat : public QDialog
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = 0, Client *c = 0);
    ~Chat();

signals:
    void textToSend(QString text);

private slots:
    void send();
    void updateChat(QString text);

private:
    Ui::Chat *ui;
    Client* client;

};

#endif // CHAT_H
