#ifndef CRAZYFACE_H
#define CRAZYFACE_H

#include <QDialog>
#include "Client.h"
#include "Chat.h"
#include "Drop.h"
#include "ui_Drop.h"
#include "ChangeSuit.h"
#include "ui_ChangeSuit.h"

namespace Ui {
class CrazyFace;
}

class CrazyFace : public QDialog
{
    Q_OBJECT

public:
    explicit CrazyFace(QWidget *parent = 0, Client *c = 0);
    ~CrazyFace();
    Ui::CrazyFace *ui;

private slots:
    void on_pushDraw_clicked();

    void on_chat_clicked();

    void on_pushDrop_clicked();

private:

    Client *client;
    Chat *chatBox;
    Drop *drop;
    ChangeSuit *changeSuit;
};

#endif // CRAZYFACE_H
