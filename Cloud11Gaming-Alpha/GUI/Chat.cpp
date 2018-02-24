#include "Chat.h"
#include "ui_Chat.h"

Chat::Chat(QWidget *parent, Client *c) :
    QDialog(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    client = c;
    ui->history->setFocusPolicy(Qt::NoFocus);


    connect(ui->send, SIGNAL(clicked()), this, SLOT(send()));
    connect(this, SIGNAL(textToSend(QString)), client, SLOT(sendMessage(QString)));
    connect(client, SIGNAL(chatMessage(QString)), this, SLOT(updateChat(QString)));
    qDebug() << "Chat with fellow players";
}

Chat::~Chat()
{
    delete ui;
}

/**
 * @brief Chat::send sends the text
 */
void Chat::send()
{
    QString text = ui->msgLine->text();
    if(text == NULL)
        return;
    qDebug() << " Text Received: " << text;
    ui->msgLine->clear();
    emit textToSend(text);
}

/**
 * @brief Chat::updateChat updates the chat
 * @param text
 */
void Chat::updateChat(QString text)
{
    ui->history->append(text);
}
