#include "CrazyFace.h"
#include "ui_CrazyFace.h"


/**
 * @brief CrazyFace::CrazyFace contructor, sets up the game screen for CrazyFace
 * @param parent
 * @param c
 */
CrazyFace::CrazyFace(QWidget *parent, Client *c) :
    QDialog(parent),
    ui(new Ui::CrazyFace)
{
     ui->setupUi(this);
     client = c;
     drop = new Drop(this,client,"single");
     changeSuit = new ChangeSuit(this, client);
     chatBox = new Chat(this,client);


     QPixmap pixDeck(":/new/Images/Images/b1fv.png");
     QPixmap BackGround(":/new/Images/Images/grassroots.jpg");
     QPixmap pixDisplayCard(":/new/Images/Images/1.png");
     QPixmap pixDisplayKingTrebol(":/new/Images/Images/5.png");

     QPixmap scaledDeck = pixDeck.scaled ( 190, 240, Qt::IgnoreAspectRatio, Qt::FastTransformation );
     QPixmap scaledDisplayCard = pixDisplayCard.scaled ( 190, 240, Qt::IgnoreAspectRatio, Qt::FastTransformation );
     QPixmap scaledBackGround = BackGround.scaled ( 1280, 720, Qt::IgnoreAspectRatio, Qt::FastTransformation );

     QPixmap scaledCardAce = pixDisplayCard.scaled ( 70, 115, Qt::IgnoreAspectRatio, Qt::FastTransformation );
     QPixmap scaledCardKingTrebol = pixDisplayKingTrebol.scaled ( 70, 115, Qt::IgnoreAspectRatio, Qt::FastTransformation );

     QIcon ButtonIconDeck(scaledDeck);
     QIcon ButtonIconShownCard(scaledDisplayCard);

     ui->pushDeck->setIcon(scaledDeck);
     ui->pushDeck->setIconSize(scaledDeck.rect().size());

     ui->pushCardSchown->setIcon(scaledDisplayCard);
     ui->pushCardSchown->setIconSize(scaledDisplayCard.rect().size());

     ui->label_2->setPixmap(scaledCardAce);
     ui->label_3->setPixmap(scaledCardAce);
     ui->label_4->setPixmap(scaledCardKingTrebol);
     ui->label_30->setPixmap(scaledCardKingTrebol);

     ui->backgroundImage->setPixmap(scaledBackGround);
}

/**
 * @brief CrazyFace::~CrazyFace destructor
 */
CrazyFace::~CrazyFace()
{
    delete ui;
}

/**
 * @brief CrazyFace::on_pushDraw_clicked
 */
void CrazyFace::on_pushDraw_clicked()
{

}

/**
 * @brief CrazyFace::on_chat_clicked
 */
void CrazyFace::on_chat_clicked()
{
    if(chatBox->isHidden()){
        chatBox->show();
    }else{
        chatBox->hide();
    }
}

/**
 * @brief CrazyFace::on_pushDrop_clicked
 */
void CrazyFace::on_pushDrop_clicked()
{
    if(drop->isHidden()){
        drop->show();
    }else{
        drop->hide();
    }
}
