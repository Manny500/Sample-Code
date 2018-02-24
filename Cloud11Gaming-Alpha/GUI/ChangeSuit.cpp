#include "ChangeSuit.h"
#include "ui_ChangeSuit.h"

ChangeSuit::ChangeSuit(QWidget *parent, Client *c) :
    QDialog(parent),
    ui(new Ui::ChangeSuit)
{
    ui->setupUi(this);
    suitOptionMade = false;
    client = c;

    QPixmap pixBackground(":/new/Images/Images/FlowerPower.jpg");
    QPixmap pixHeart(":/new/Images/Images/Heart.jpg");
    QPixmap pixSpade(":/new/Images/Images/Spade.jpg");
    QPixmap pixDimond(":/new/Images/Images/Diamond.jpg");
    QPixmap pixClub(":/new/Images/Images/Club.jpg");

    QPixmap scaledBack = pixBackground.scaled ( 483, 318, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledHe = pixHeart.scaled ( 90, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledSp = pixSpade.scaled ( 90, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledDi = pixDimond.scaled ( 90, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledCl = pixClub.scaled ( 90, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation );

    ui->background->setPixmap(scaledBack);
    ui->spadePic->setPixmap(scaledHe);
    ui->heartPic->setPixmap(scaledDi);
    ui->clubPic->setPixmap(scaledSp);
    ui->diamondPic->setPixmap(scaledCl);


    connect(ui->clubs, SIGNAL(clicked()), this, SLOT(choiceMade()));
    connect(ui->spades, SIGNAL(clicked()), this, SLOT(choiceMade()));
    connect(ui->diamonds, SIGNAL(clicked()), this, SLOT(choiceMade()));
    connect(ui->hearts, SIGNAL(clicked()), this, SLOT(choiceMade()));

}

/**
 * @brief ChangeSuit::~ChangeSuit destructor
 */
ChangeSuit::~ChangeSuit()
{
    delete ui;
}

/**
 * @brief ChangeSuit::on_choose_clicked
 */
void ChangeSuit::on_choose_clicked()
{

}

/**
 * @brief ChangeSuit::choiceMade
 */
void ChangeSuit::choiceMade(){
    if(suitOptionMade == false){
         suitOptionMade = true;
    }
}
