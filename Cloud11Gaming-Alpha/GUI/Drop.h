#ifndef DROP_H
#define DROP_H

#include <QDialog>
#include "Client.h"
namespace Ui {
class Drop;
}

class Drop : public QDialog
{
    Q_OBJECT

public:
    explicit Drop(QWidget *parent = 0, Client *client = 0, QString dropType = "single");
    ~Drop();

signals:

private slots:

    void singleCardSelected();
    void multipleCardSelected();
    void on_pushButtonConfim_clicked();

private:
    Ui::Drop *ui;
    Client *client;
    bool dropSingleChosen;
    bool dropMultipleChosen;
};

#endif // DROP_H
