#include "CatanChooseResource.h"
#include "ui_CatanChooseResource.h"

CatanChooseResource::CatanChooseResource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CatanChooseResource)
{
    ui->setupUi(this);
    catanchoosertype = 0;
}

CatanChooseResource::~CatanChooseResource()
{
    delete ui;
}

void CatanChooseResource::on_pushButton_clicked()
{
    if(ui->radioButtonBrick->isChecked()){ emit resourceChosen(0,catanchoosertype); }
    else if(ui->radioButtonGrain->isChecked()){emit resourceChosen(3,catanchoosertype);}
    else if(ui->radioButtonLumber->isChecked()){emit resourceChosen(4,catanchoosertype);}
    else if(ui->radioButtonOre->isChecked()){emit resourceChosen(2,catanchoosertype);}
    else if(ui->radioButtonWool->isChecked()){emit resourceChosen(1,catanchoosertype);}
}


void CatanChooseResource::playableType(int type){
    catanchoosertype = type;
}
