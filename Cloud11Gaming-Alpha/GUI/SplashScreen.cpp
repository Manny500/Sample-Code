#include "SplashScreen.h"
#include "ui_SplashScreen.h"

/**
 * @brief SplashScreen::SplashScreen constructor, essentially opens up the game screens to be played
 * @param parent
 */
SplashScreen::SplashScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    defaultConnectSettings();
    connect(ui->exit, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->enter, SIGNAL(clicked()),this, SLOT(customSettings()));

    QPixmap pixBackground(":/new/Images/Images/FlowerPower.jpg");
    QPixmap scaledBack = pixBackground.scaled(773, 441, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    ui->backGround->setPixmap(scaledBack);

}

/**
 * @brief SplashScreen::~SplashScreen destructor
 */
SplashScreen::~SplashScreen()
{
    delete ui;
}

void SplashScreen::defaultConnectSettings()
{
    playerName = "Me";
    ipAddress = "127.0.0.1";
    portNumber = 2500;
    ui->name->clear();
    ui->address->clear();
    ui->port->clear();
    ui->name->setText(playerName);
    ui->port->setText(QString::number(portNumber));
    ui->address->setText(ipAddress);
}

/**
 * @brief SplashScreen::customSettings sets up the custom settings for the SplashScreen
 */
void SplashScreen::customSettings()
{
    playerName = ui->name->text();
    ipAddress = ui->address->text();
    portNumber = ui->port->text().toUInt();

    qDebug() << playerName;

    CloudGaming *cloudy = new CloudGaming(this,ipAddress,portNumber,playerName);
    cloudy->show();
    this->hide();
}

/**
 * @brief SplashScreen::close closes the screen
 */
void SplashScreen::close()
{
    this->close();
}



