#include "Drop.h"
#include "ui_Drop.h"

Drop::Drop(QWidget *parent, Client *c, QString dropType) :
    QDialog(parent),
    ui(new Ui::Drop)
{
    ui->setupUi(this);
    client = c;
    dropSingleChosen = false;
    dropMultipleChosen = false;

    QPixmap pixBackground(":/new/Images/Images/grassroots.jpg");
    QPixmap pixEmpty(":/new/Images/Images/b1fv.png");

    QPixmap scaledBack = pixBackground.scaled ( 1061, 780, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledEmpty = pixEmpty.scaled ( 90, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation );

    ui->background->setPixmap(scaledBack);
    ui->label00->setPixmap(scaledEmpty);
    ui->label01->setPixmap(scaledEmpty);
    ui->label02->setPixmap(scaledEmpty);
    ui->label03->setPixmap(scaledEmpty);
    ui->label04->setPixmap(scaledEmpty);
    ui->label05->setPixmap(scaledEmpty);
    ui->label06->setPixmap(scaledEmpty);
    ui->label07->setPixmap(scaledEmpty);
    ui->label08->setPixmap(scaledEmpty);
    ui->label09->setPixmap(scaledEmpty);
    ui->label10->setPixmap(scaledEmpty);
    ui->label11->setPixmap(scaledEmpty);
    ui->label12->setPixmap(scaledEmpty);
    ui->label13->setPixmap(scaledEmpty);
    ui->label14->setPixmap(scaledEmpty);
    ui->label15->setPixmap(scaledEmpty);
    ui->label16->setPixmap(scaledEmpty);
    ui->label17->setPixmap(scaledEmpty);
    ui->label18->setPixmap(scaledEmpty);
    ui->label19->setPixmap(scaledEmpty);
    ui->label20->setPixmap(scaledEmpty);
    ui->label21->setPixmap(scaledEmpty);
    ui->label22->setPixmap(scaledEmpty);
    ui->label23->setPixmap(scaledEmpty);
    ui->label24->setPixmap(scaledEmpty);
    ui->label25->setPixmap(scaledEmpty);
    ui->label26->setPixmap(scaledEmpty);
    ui->label27->setPixmap(scaledEmpty);
    ui->label28->setPixmap(scaledEmpty);
    ui->label29->setPixmap(scaledEmpty);
    ui->label30->setPixmap(scaledEmpty);
    ui->label31->setPixmap(scaledEmpty);
    ui->label32->setPixmap(scaledEmpty);
    ui->label33->setPixmap(scaledEmpty);
    ui->label34->setPixmap(scaledEmpty);
    ui->label35->setPixmap(scaledEmpty);
    ui->label36->setPixmap(scaledEmpty);
    ui->label37->setPixmap(scaledEmpty);
    ui->label38->setPixmap(scaledEmpty);
    ui->label39->setPixmap(scaledEmpty);

    if(dropType == "single")
    {
        connect(ui->checkBox00, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox01, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox02, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox03, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox04, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox05, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox06, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox07, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox08, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox09, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox10, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox11, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox12, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox13, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox14, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox15, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox16, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox17, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox18, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox19, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox20, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox21, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox22, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox23, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox24, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox25, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox26, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox27, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox28, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox29, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox30, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox31, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox32, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox33, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox34, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox35, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox36, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox37, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox38, SIGNAL(clicked()),this,SLOT(singleCardSelected()));
        connect(ui->checkBox39, SIGNAL(clicked()),this,SLOT(singleCardSelected()));

    }
    else if(dropType == "multiple")
    {
        connect(ui->checkBox00, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox01, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox02, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox03, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox04, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox05, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox06, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox07, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox08, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox09, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox10, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox11, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox12, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox13, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox14, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox15, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox16, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox17, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox18, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox19, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox20, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox21, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox22, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox23, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox24, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox25, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox26, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox27, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox28, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox29, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox30, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox31, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox32, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox33, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox34, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox35, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox36, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox37, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox38, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
        connect(ui->checkBox39, SIGNAL(clicked()),this,SLOT(multipleCardSelected()));
    }

}

/**
 * @brief Drop::~Drop drop destructor
 */
Drop::~Drop()
{
    delete ui;
}

/**
 * @brief Drop::singleCardSelected
 */
void Drop::singleCardSelected(){
    if(dropSingleChosen == false){
        dropSingleChosen = true;
    }else{
        dropSingleChosen = false;
    }
}

/**
 * @brief Drop::multipleCardSelected
 */
void Drop::multipleCardSelected(){
    if(dropMultipleChosen == false){
        dropMultipleChosen = true;
    }
}

/**
 * @brief Drop::on_pushButtonConfim_clicked
 */
void Drop::on_pushButtonConfim_clicked()
{
    if(dropSingleChosen || dropMultipleChosen){
        this->hide();
    }
}
