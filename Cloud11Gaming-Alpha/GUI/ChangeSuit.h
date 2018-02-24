#ifndef CHANGESUIT_H
#define CHANGESUIT_H

#include <QDialog>
#include "Client.h"

namespace Ui {
class ChangeSuit;
}

class ChangeSuit : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeSuit(QWidget *parent = 0, Client *c = 0);
    ~ChangeSuit();

private slots:
    void choiceMade();
    void on_choose_clicked();

private:
    Ui::ChangeSuit *ui;
    Client *client;
    bool suitOptionMade;
};

#endif // CHANGESUIT_H
