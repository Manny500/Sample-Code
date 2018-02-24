#ifndef CATANCHOOSERESOURCE_H
#define CATANCHOOSERESOURCE_H

#include <QDialog>

namespace Ui {
class CatanChooseResource;
}

class CatanChooseResource : public QDialog
{
    Q_OBJECT

public:
    explicit CatanChooseResource(QWidget *parent = 0);
    ~CatanChooseResource();
    void playableType(int type);

signals:
    void resourceChosen(int type, int card);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CatanChooseResource *ui;
    int catanchoosertype;
};

#endif // CATANCHOOSERESOURCE_H
