#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QDialog>
#include <QString>
#include "Client.h"
#include "CloudGaming.h"
#include "CloudGaming.h"


namespace Ui {
class SplashScreen;
}

class SplashScreen : public QDialog
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget *parent = 0);
    ~SplashScreen();

    void defaultConnectSettings();


private slots:
    void close();
    void customSettings();


private:
    Ui::SplashScreen *ui;
    QString playerName;
    qint16 portNumber;
    QString ipAddress;
};

#endif // SPLASHSCREEN_H
