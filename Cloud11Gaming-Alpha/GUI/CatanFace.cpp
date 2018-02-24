#include "CatanFace.h"
#include "ui_CatanFace.h"
#include <QPainter>
#include <QColor>
#include <QtWidgets>
#include <QtGui>
#include <QMediaPlayer>
#include <QDebug>

/**
 * @brief CatanFace::CatanFace constructor of CatanFace
 * @param parent
 */
CatanFace::CatanFace(QWidget *parent, Client *c, int color, QStringList* users) :
    QDialog(parent),
    ui(new Ui::CatanFace)

{
    client = c;
    chatBox = new Chat(this,client);

    ui->setupUi(this);
    chatBox->hide();

    //ui->player1->setStyleSheet("border:0;");
   // ui->player2->setStyleSheet("border:0;");
   // ui->player3->setStyleSheet("border:0;");
   // ui->player4->setStyleSheet("border:0;");

    ui->p1name->setText(users->at(0));
    ui->p2name->setText(users->at(1));
    ui->p3name->setText(users->at(2));
    ui->p4name->setText(users->at(3));

    //ui->tradeBox->setStyleSheet("border:0;");

  //  ui->buyRoads->setStyleSheet("border:0;");
   // ui->buyCities->setStyleSheet("border:0;");
  //  ui->buyDevelopment->setStyleSheet("border:0;");
  //  ui->buySettlementts->setStyleSheet("border:0;");

  //  ui->tradeBox->setStyleSheet("border:0;");
   // ui->playBox->setStyleSheet("border:0;");

    ui->map->setStyleSheet("border:0px");

    QPixmap pixCity(":/new/Images/Images/city.jpg");
    QPixmap pixSettlement(":/new/Images/Images/imgres-1.jpg");
    QPixmap pixRoad(":/new/Images/Images/images.png");
    QPixmap pixVictory(":/new/Images/Images/viCup.jpg");
    QPixmap pixDice(":/new/Images/Images/dice.png");

    QPixmap pixBackground(":/new/Images/Images/temp-board");
    QPixmap pixMap(":/new/Images/Images/11121691_1246341082092650_1437859704_n.jpg");
    QPixmap pixWool(":/new/Images/Images/images-1.jpg");
    QPixmap pixBrick(":/new/Images/Images/imgres-3.jpg");
    QPixmap pixOre(":/new/Images/Images/images-2.jpg");
    QPixmap pixGrain(":/new/Images/Images/imgres-2.jpg");
    QPixmap pixLumber(":/new/Images/Images/imgres-4.jpg");
    QPixmap pixSettings(":/new/Images/Images/settings.png");

    QPixmap pixRobber(":/new/Images/Images/robber.png");
    QPixmap scaledRobber = pixRobber.scaled(51, 51, Qt::IgnoreAspectRatio, Qt::FastTransformation );

    QPixmap scaledBack = pixBackground.scaled(1280, 720, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledC = pixCity.scaled ( 50, 50, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledS = pixSettlement.scaled ( 35, 35, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledR = pixRoad.scaled ( 30, 30, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledV = pixVictory.scaled ( 30, 30, Qt::IgnoreAspectRatio, Qt::FastTransformation );

    QPixmap scaledBuyCit = pixCity.scaled ( 51, 71, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledBuySet = pixSettlement.scaled ( 51, 71, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledBuyRoa = pixRoad.scaled ( 51, 71, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledBuyVic = pixVictory.scaled ( 51, 71, Qt::IgnoreAspectRatio, Qt::FastTransformation );

    QPixmap scaledW = pixWool.scaled ( 50, 50, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledB = pixBrick.scaled ( 50, 50, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledO = pixOre.scaled ( 50, 50, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledG = pixGrain.scaled ( 50, 50, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledL = pixLumber.scaled ( 50, 50, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    QPixmap scaledDice = pixDice.scaled(81, 61, Qt::IgnoreAspectRatio, Qt::FastTransformation );

    QPixmap scaledSettings = pixSettings.scaled ( 35, 35, Qt::IgnoreAspectRatio, Qt::FastTransformation );

    QIcon ButtonIconC(scaledC);
    QIcon ButtonIconS(scaledS);
    QIcon ButtonIconR(scaledR);
    QIcon ButtonIconV(scaledV);

    QIcon ButtonIconW(scaledW);
    QIcon ButtonIconB(scaledB);
    QIcon ButtonIconO(scaledO);
    QIcon ButtonIconG(scaledG);
    QIcon ButtonIconL(scaledL);
    QIcon ButtonIconDice(scaledDice);

    QIcon ButtonIconSettings(scaledSettings);

    QImage image(":/new/Images/Images/11165996_1246341065425985_626572504_n1.jpg");
    QGraphicsScene *scene = new QGraphicsScene();
    ui->map->setScene(scene);
    QPixmap scaledMap = (QPixmap::fromImage(image)).scaled ( 691, 615
                                                             , Qt::IgnoreAspectRatio, Qt::FastTransformation );
    scaledMap.fill(Qt::transparent);
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(scaledMap);

    scene->addItem(item);
    ui->map->setStyleSheet("background:transparent");
    resourceChooser = new CatanChooseResource(this);
    resourceChooser->hide();

    ui->background->setPixmap(scaledBack);
    ui->rollDice->setIcon(scaledDice);
    //ui->RollDice->setIconSize(scaledDice.rect().size());
    ui->robber->setIcon(scaledRobber);
    ui->robber->setIconSize(scaledRobber.rect().size());

//    ui->woolStatus->setPixmap(scaledW);
//    ui->brickStatus->setPixmap(scaledB);
//    ui->grainStatus->setPixmap(scaledG);
//    ui->oreStatus->setPixmap(scaledO);
//    ui->lumberStatus->setPixmap(scaledL);

//    ui->woolOffer->setPixmap(scaledW);
//    ui->BrickOffer->setPixmap(scaledB);
//    ui->grainOffer->setPixmap(scaledG);
//    ui->oreOffer->setPixmap(scaledO);
//    ui->lumberOffer->setPixmap(scaledL);

//    ui->roadCardBuy->setPixmap(scaledBuyRoa);
//    ui->cityCardBuy->setPixmap(scaledBuyCit);
//    ui->settleCardBuy->setPixmap(scaledBuySet);
//    ui->devCardBuy->setPixmap(scaledBuyVic);

    //QBrush tb(Qt::transparent); // Transparent brush, solid pattern
    //ui->pushEndTurn->setFlat(true);

    //initializing drawing related variables
    canPlaceRoad = false;
    canPlaceSettlement = false;
    canPlaceCity = false;
    buttonLock = false;
    canRob = false;
    countRoadPt = 0;


    offset = 287.0;//how far left the coordinates must move
 //   offset = 0;
    yRoadOffset = 5.0;
    playerNum = 0, dice = 0;

    oppPlayerFillColor = Qt::red;
    oppPlayerLineColor = Qt::darkRed;

    yourFillColor = Qt::red;
    yourLineColor = Qt::red;

    setYourColor(color);


    roadScale = 9.0;
    roadType = 0;

    canPlaceConstruction = 0;
    isAffordable = 0;
    returnConstruction = 0;

    currentPlayer = false;

    QString fonttemplate = tr("<font color='%1'>%2</font>");
    ui->label->setText( fonttemplate.arg( "white", client->getUserName()) );

    root3 = (float)sqrt(3);

    connect(this, SIGNAL(request(uint)), client, SLOT(clientRequest(uint)));
    connect(client, SIGNAL(messageForCatan(QString)) , this, SLOT(decipher(QString)));
    connect(this,SIGNAL(structMeth(int,int,int,int,int)),client, SLOT(clientStructMeth(int,int,int,int,int)));
    connect(ui->rollDice, SIGNAL(clicked()), client, SLOT(rollDice()));
    connect(this, SIGNAL(robberCords(int,int,int,int,int)), client, SLOT(robberCordsSend(int,int,int,int,int)));
    connect(this,SIGNAL(sendOffer(QString,QString,QString,QString,QString,QString)), client, SLOT(sendOffer(QString,QString,QString,QString,QString,QString)));
    connect(this,SIGNAL(playable(int)),client, SLOT(sendPlayable(int)));
    connect(resourceChooser, SIGNAL(resourceChosen(int,int)), client, SLOT(resourceChosen(int,int)));
    connect(this,SIGNAL(endTurn()),client,SLOT(endTurn()));
}

/**
 * @brief CatanFace::~CatanFace destructor for CatanFace
 */
CatanFace::~CatanFace()
{
    delete ui;
}



void CatanFace::setYourColor(int color){
    if(color == 0){
        yourFillColor = Qt::red;// initializing
        yourLineColor = Qt::darkRed;
    }else if(color == 1){
        yourFillColor = Qt::yellow;// initializing
        yourLineColor = Qt::darkYellow;
    }else if (color == 2){
        yourFillColor = Qt::green;// initializing
        yourLineColor = Qt::darkGreen;
    }else if(color == 3){
        yourFillColor = Qt::blue;// initializing
        yourLineColor = Qt::darkBlue;
    }
}
/**
 * @brief CatanFace::mousePressEvent what happens when the mouse is pressed
 * @param e
 */
void CatanFace::mousePressEvent(QMouseEvent *e)
{
    QPointF pt = ui->map->mapToScene(e->pos());
    //send point to game here.
    qDebug() << pt.x() << " " << pt.y();

}

/**
 * @brief CatanFace::on_chat_clicked when chat is clicked, open chat box
 */
void CatanFace::on_chat_clicked()
{

    if(chatBox->isHidden())
    {
        chatBox->show();
    }else{

        chatBox->hide();
    }
}

/**
 * @brief CatanFace::setHex turns the current polygon shape into a hexagon
 * @param centerX
 * @param centerY
 * @param skale
 */
void CatanFace::setHex(float centerX, float centerY, float skale)
{
    QPolygonF temp;



    temp << QPointF(centerX+skale, centerY+(skale*root3))
         << QPointF(centerX+(skale*2), centerY)
         << QPointF(centerX+skale, centerY-(skale*root3))
         << QPointF(centerX-skale, centerY-(skale*root3))
         << QPoint(centerX-(skale*2), centerY)
         << QPoint(centerX-skale, centerY+(skale*root3));
    shape = temp;

}

/**
 * @brief CatanFace::setGrid intended to draw a grid of hexagons if needed, still in progress
 * @param startX
 * @param startY
 * @param skale
 * @param numRows
 * @param numCols
 */
void CatanFace::setGrid(float startX, float startY, float skale, int numRows, int numCols)
{
    QPen *pen = new QPen(playerLineColor);


    for(float i = startX; i< numCols; i++)
    {
        for(float j = startY; j< numRows; j++)
        {
            if((int)i%2==0)
            {
                setHex(i,j,skale);
            }else
            {
                setHex(i,j+skale,skale);
            }
            ui->map->scene()->addPolygon(shape,*pen,QBrush(playerFillColor, Qt::SolidPattern));
            shape.clear();
        }
    }

}

/**
 * @brief CatanFace::setCity turns the current polygon shape into a square, representing a city in CatanFace
 * @param centerX
 * @param centerY
 */
void CatanFace::setCity(float centerX, float centerY)
{
    QPolygonF temp;

    temp << QPointF(centerX+10, centerY+10)
         << QPointF(centerX+10, centerY-10)
         << QPointF(centerX-10, centerY-10)
         << QPointF(centerX-10, centerY+10);
    shape = temp;

}

/**
 * @brief CatanFace::setSettlement turns the current polygon shape into a triangle, representing a settlement in CatanFace
 * @param centerX
 * @param centerY
 */
void CatanFace::setSettlement(float centerX, float centerY)
{
    QPolygonF temp;
    temp << QPointF(centerX+10, centerY+10)
         << QPointF(centerX-10, centerY+10)
         << QPointF(centerX, centerY-10);
    shape = temp;
}

/**
 * @brief CatanFace::setRoad draws a line from point a to point b, representing a road in CatanFace
 * @param startX
 * @param startY
 * @param endX
 * @param endY
 */
void CatanFace::setRoad(float startX, float startY, float endX, float endY)
{
    QPen *pen = new QPen(playerFillColor);
    road = new QLineF(startX,startY,endX,endY);
    pen->setWidthF(4.0);
    ui->map->scene()->addLine(*road, *pen);
}
/**
 * @brief CatanFace::setRoad same as other set road but with a color parameter
 * @param startX
 * @param startY
 * @param endX
 * @param endY
 * @param col
 */
void CatanFace::setRoad(float startX, float startY, float endX, float endY, QColor col)
{
    QPen *pen = new QPen(col);
    road = new QLineF(startX,startY,endX,endY);
    pen->setWidthF(10.0);
    ui->map->scene()->addLine(*road, *pen);
}

/**
 * @brief CatanFace::setBrush changes the brush color of the pen parameter
 * @param col
 * @param pen
 */
void CatanFace::setBrush(QColor col, QPen *pen)
{
    pen->setBrush(col);
}

/**
 * @brief CatanFace::paintEvent will automatically paint the polygon shape when it is changed
 * @param event
 */
void CatanFace::paintEvent(QPaintEvent *event)
{
    QPen *pen = new QPen(playerLineColor);
    pen->setWidthF(3.0);
    ui->map->scene()->addPolygon(shape,*pen,QBrush(playerFillColor, Qt::SolidPattern));
    shape.clear();
}

/**
 * @brief CatanFace::setColor sets the current player color
 * @param col
 */
void CatanFace::setColor(QColor col)
{
    playerFillColor = col;
}

/**
 * @brief CatanFace::on_pushBS_clicked when the buysettlemennt button is pressed, canPlacesettlement is set to true
 */
void CatanFace::on_pushBS_clicked()
{
    constructionType = 1;
    emit request(1);

}

/**
 * @brief CatanFace::on_pushBC_clicked when the buycity button is pressed, canPlaceCity is set to true
 */
void CatanFace::on_pushBC_clicked()
{
    constructionType = 2;
    emit request(2);
}

/**
 * @brief CatanFace::on_pushBR_clicked when the buyroad button is clicked, canPlaceRoad is set to true
 */
void CatanFace::on_pushBR_clicked()
{
    constructionType = 0;
    emit request(0);
}

void CatanFace::on_pushBD_clicked()
{
    constructionType = 3;
    emit request(3);
}




/**
 * @brief CatanFace::on_pushEndTurn_clicked when the end turn button is pressed, the current player as well as the player color is changed
 */
void CatanFace::on_pushEndTurn_clicked()
{
    currentPlayer = false;
    emit endTurn();

}

//------------------------------------------------------slot ----------------------------------------------------

void CatanFace::drawCitySettlements(int X, int Y){
    if(canPlaceSettlement)
    {
        qDebug() << " enters settlement method";
        qDebug() << X << Y;
        setSettlement((float)X-offset, (float)Y);
        canPlaceSettlement = false;
    }
    else if(canPlaceCity)
    {
        qDebug() << " enters city method";
        setCity((float)X-offset, (float)Y);
        canPlaceCity = false, canPlaceSettlement = false;
    }
}
void CatanFace::updateStats(QString msg){
    QStringList statList= msg.split(",");
    qDebug() << statList;

    ui->p1road->setText( statList.at(0));
    ui->p1knight->setText(statList.at(1));
    ui->p1victory->setText(statList.at(2));
    ui->p2road->setText( statList.at(3));
    ui->p2knight->setText(statList.at(4));
    ui->p2victory->setText(statList.at(5));
    ui->p3road->setText( statList.at(6));
    ui->p3knight->setText(statList.at(7));
    ui->p3victory->setText(statList.at(8));
    ui->p4road->setText( statList.at(9));
    ui->p4knight->setText(statList.at(10));
    ui->p4victory->setText(statList.at(11));

    ui->brickResource->setText(statList.at(12));
    ui->woolResource->setText(statList.at(13));
    ui->oreResource->setText(statList.at(14));
    ui->grainResource->setText(statList.at(15));
    ui->lumberResource->setText(statList.at(16));
    ui->label_2->setText(statList.at(17));
    ui->label_4->setText(statList.at(18));
    ui->label_3->setText(statList.at(19));
    ui->label_5->setText(statList.at(20));
    ui->label_22->setText(statList.at(21));

}

void CatanFace::decipher(QString stats){
    QString taskCode = stats.mid(0,6);
    QString msg = stats.remove(0,13);
    qDebug() << taskCode;


    if(taskCode == "cstats"){
        updateStats(msg);
    }
    else if(taskCode == "rodice"){
        currentPlayer = true;

        QStringList dataFollowing = msg.split(".");
        QString diceVal = dataFollowing.at(0);
        ui->rolls->setText(diceVal);
        qDebug() << diceVal;

        if(diceVal == "7"){
            canRob = true;
        }else{
            canRob = false;
        }

        QString stats = dataFollowing.at(1);
        stats.remove("cstats<catan>");
        updateStats(stats);
    }
    else if(taskCode == "reques"){

        qDebug() << "affordable" << msg;
        isAffordable = msg.split(".").at(0).toInt();
        returnConstruction = msg.split(".").at(1).toInt();

        if(msg.split(".").at(2).contains("cstats<catan>")){
            QString temp = msg.split(".").at(2);
            temp.remove("cstats<catan");
            updateStats(temp);
        }
        qDebug() << isAffordable;
    }


    // need to add stuff regarding updating maps. need to take into consideration the button x and button y values. do this through deciphering values from the msg string
    else if(taskCode == "struct"){
        QStringList dataFollowingStruct = msg.split(".");
        qDebug() << "place Construction" << msg;

        canPlaceConstruction = dataFollowingStruct.at(0).toInt();
        int butX = dataFollowingStruct.at(1).toInt();
        int butY = dataFollowingStruct.at(2).toInt();
        constructionType = dataFollowingStruct.at(3).toInt();
        roadType = dataFollowingStruct.at(4).toInt();
        int oppPlayerIndex = dataFollowingStruct.at(5).toInt();


        setOppColor(oppPlayerIndex);

        if(yourFillColor == oppPlayerFillColor){currentPlayer = true;}
        if(currentPlayer == true){
            playerFillColor = yourFillColor;
            playerLineColor = yourLineColor;
        }else{
            playerFillColor = oppPlayerFillColor;
            playerLineColor = oppPlayerLineColor;
        }


        qDebug() << currentPlayer;


        qDebug() << "first param can place construction : " << canPlaceConstruction;
        qDebug() << canPlaceConstruction << isAffordable;

        if(canPlaceConstruction == 1 && isAffordable == 1){

            qDebug() << "entered condition" << constructionType;
            setConstructionType(constructionType);

            qDebug() << canPlaceRoad << canPlaceCity << canPlaceSettlement;
            qDebug() << butX << butY;

            drawRoad(butX, butY ,roadType);
            drawCitySettlements(butX, butY);

            if(currentPlayer == true){
                QString statsPart = dataFollowingStruct.at(6);
                qDebug() << statsPart;

                statsPart.remove("cstats<catan>");
                qDebug() << statsPart;
                updateStats(statsPart);
            }

            qDebug() << currentPlayer;
            canPlaceConstruction = 0;
            isAffordable= 0;

        }


    }
    else if(taskCode == "enturn"){
        qDebug() << "end turn";
        canRob = false;
        currentPlayer = false;
    }
    else if(taskCode == "canrob"){
        canRob = true;

        if(currentPlayer == true){
            msg.remove("cstats<catan>");
            updateStats(msg);
        }
    }else if(taskCode == "robcod"){
        qDebug() << "wassuuupppp";
        QStringList dataFollowing = msg.split(".");
        QString x = dataFollowing.at(0);
        QString y = dataFollowing.at(1);
        QString stats = dataFollowing.at(2);

        if(currentPlayer == true){
            stats.remove("cstats<catan>");
            qDebug() << "statssssss";
            updateStats(stats);
        }else{
            ui->robber->move(x.toInt(),y.toInt());
        }
    }
    else if(taskCode == "yoturn"){
        currentPlayer = true;
        msg.remove("cstats<catan>");
        updateStats(msg);
    }
}
void CatanFace::setConstructionType(int type){
    if(type == 0){canPlaceRoad = true;}
    else if(type == 1){canPlaceSettlement = true;}
    else if(type == 2){canPlaceCity = true;}
}


void CatanFace::setOppColor(int oppPlayerIndex){
    if(oppPlayerIndex == 0){
        oppPlayerFillColor = Qt::red;
        oppPlayerLineColor = Qt:: darkRed;
    }else if(oppPlayerIndex == 1){
        oppPlayerFillColor = Qt::yellow;
        oppPlayerLineColor = Qt:: darkYellow;
    }else if(oppPlayerIndex == 2){
        oppPlayerFillColor = Qt::green;
        oppPlayerLineColor = Qt:: darkGreen;
    }else if(oppPlayerIndex == 3){
        oppPlayerFillColor = Qt::blue;
        oppPlayerLineColor = Qt:: darkBlue;
    }
}


/**

 * @brief CatanFace::on_pushButton_122_clicked can make settlement or city

 */

void CatanFace::on_pushButton_1_clicked()

{ buttonClicked = ui->pushButton_1;


    emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-2,0);


}


/**

 * @brief CatanFace::on_pushButton_123_clicked settlement or city

 */

void CatanFace::on_pushButton_2_clicked()

{ buttonClicked = ui->pushButton_2;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-2,0);



}


/**

 * @brief CatanFace::on_pushButton_124_clicked settlement or city

 */

void CatanFace::on_pushButton_3_clicked()

{ buttonClicked = ui->pushButton_3;   emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-2,0);


}


/**

 * @brief CatanFace::on_pushButton_130_clicked settlement or city

 */

void CatanFace::on_pushButton_4_clicked()

{ buttonClicked = ui->pushButton_4;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,-1,0);

}


/**

 * @brief CatanFace::on_pushButton_131_clicked settlement or city

 */

void CatanFace::on_pushButton_5_clicked()

{ buttonClicked = ui->pushButton_5;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-1,0);


}


/**

 * @brief CatanFace::on_pushButton_129_clicked settlement or city

 */

void CatanFace::on_pushButton_6_clicked()

{ buttonClicked = ui->pushButton_6;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-1,0);


}


/**

 * @brief CatanFace::on_pushButton_10_clicked

 */

void CatanFace::on_pushButton_7_clicked()

{ buttonClicked = ui->pushButton_7;   emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-1,0);


}


/**

 * @brief CatanFace::on_pushButton_12_clicked

 */

void CatanFace::on_pushButton_8_clicked()

{ buttonClicked = ui->pushButton_8;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,0,0);


}


/**

 * @brief CatanFace::on_pushButton_17_clicked

 */

void CatanFace::on_pushButton_9_clicked()

{ buttonClicked = ui->pushButton_9;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,0,0);


}


/**

 * @brief CatanFace::on_pushButton_23_clicked

 */

void CatanFace::on_pushButton_10_clicked()

{ buttonClicked = ui->pushButton_10;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,0,0);


}


/**

 * @brief CatanFace::on_pushButton_84_clicked

 */

void CatanFace::on_pushButton_11_clicked()

{ buttonClicked = ui->pushButton_11;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,0,0);


}


/**

 * @brief CatanFace::on_pushButton_86_clicked

 */

void CatanFace::on_pushButton_12_clicked()

{ buttonClicked = ui->pushButton_12;   emit structMeth(buttonClicked->x(),buttonClicked->y(),2,0,0);


}


/**

 * @brief CatanFace::on_pushButton_39_clicked

 */

void CatanFace::on_pushButton_13_clicked()

{ buttonClicked = ui->pushButton_13;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-3,1,0);


}


/**

 * @brief CatanFace::on_pushButton_40_clicked

 */

void CatanFace::on_pushButton_14_clicked()

{ buttonClicked = ui->pushButton_14;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,1,0);


}


/**

 * @brief CatanFace::on_pushButton_24_clicked

 */

void CatanFace::on_pushButton_15_clicked()

{ buttonClicked = ui->pushButton_15;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,1,0);


}


/**

 * @brief CatanFace::on_pushButton_30_clicked

 */

void CatanFace::on_pushButton_16_clicked()

{ buttonClicked = ui->pushButton_16;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,1,0);


}


/**

 * @brief CatanFace::on_pushButton_36_clicked

 */

void CatanFace::on_pushButton_17_clicked()

{ buttonClicked = ui->pushButton_17;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,1,0);


}


/**

 * @brief CatanFace::on_pushButton_97_clicked

 */

void CatanFace::on_pushButton_18_clicked()

{ buttonClicked = ui->pushButton_18;   emit structMeth(buttonClicked->x(),buttonClicked->y(),2,1,0);


}


/**

 * @brief CatanFace::on_pushButton_112_clicked

 */

void CatanFace::on_pushButton_19_clicked()

{ buttonClicked = ui->pushButton_19;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-3,2,0);


}


/**

 * @brief CatanFace::on_pushButton_113_clicked

 */

void CatanFace::on_pushButton_20_clicked()

{ buttonClicked = ui->pushButton_20;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,2,0);

}


/**

 * @brief CatanFace::on_pushButton_94_clicked

 */

void CatanFace::on_pushButton_21_clicked()

{ buttonClicked = ui->pushButton_21;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,2,0);

}


/**

 * @brief CatanFace::on_pushButton_95_clicked

 */

void CatanFace::on_pushButton_22_clicked()

{ buttonClicked = ui->pushButton_22;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,2,0);


}


/**

 * @brief CatanFace::on_pushButton_41_clicked

 */

void CatanFace::on_pushButton_23_clicked()

{ buttonClicked = ui->pushButton_23;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,2,0);


}


/**

 * @brief CatanFace::on_pushButton_42_clicked

 */

void CatanFace::on_pushButton_24_clicked()

{ buttonClicked = ui->pushButton_24;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-3,3,0);

}


/**

 * @brief CatanFace::on_pushButton_43_clicked

 */

void CatanFace::on_pushButton_25_clicked()

{ buttonClicked = ui->pushButton_25;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,3,0);


}


/**

 * @brief CatanFace::on_pushButton_44_clicked

 */

void CatanFace::on_pushButton_26_clicked()

{ buttonClicked = ui->pushButton_26;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,3,0);


}


/**

 * @brief CatanFace::on_pushButton_45_clicked

 */

void CatanFace::on_pushButton_27_clicked()

{ buttonClicked = ui->pushButton_27;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,3,0);

}


/**

 * @brief CatanFace::on_pushButton_46_clicked

 */

void CatanFace::on_pushButton_28_clicked()

{ buttonClicked = ui->pushButton_28;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-3,1);

}


/**

 * @brief CatanFace::on_pushButton_118_clicked

 */

void CatanFace::on_pushButton_29_clicked()

{ buttonClicked = ui->pushButton_29;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-3,1);

}


/**

 * @brief CatanFace::on_pushButton_47_clicked

 */

void CatanFace::on_pushButton_30_clicked()

{ buttonClicked = ui->pushButton_30;   emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-3,1);


}


/**

 * @brief CatanFace::on_pushButton_116_clicked

 */

void CatanFace::on_pushButton_31_clicked()

{ buttonClicked = ui->pushButton_31;   emit structMeth(buttonClicked->x(),buttonClicked->y(),3,-3,1);


}


/**

 * @brief CatanFace::on_pushButton_48_clicked

 */

void CatanFace::on_pushButton_32_clicked()

{ buttonClicked = ui->pushButton_32;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,-2,1);


}


/**

 * @brief CatanFace::on_pushButton_114_clicked

 */

void CatanFace::on_pushButton_33_clicked()

{ buttonClicked = ui->pushButton_33;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-2,1);


}


/**

 * @brief CatanFace::on_pushButton_49_clicked

 */

void CatanFace::on_pushButton_34_clicked()

{ buttonClicked = ui->pushButton_34;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-2,1);


}


/**

 * @brief CatanFace::on_pushButton_117_clicked

 */

void CatanFace::on_pushButton_35_clicked()

{ buttonClicked = ui->pushButton_35;   emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-2,1);


}


/**

 * @brief CatanFace::on_pushButton_50_clicked

 */

void CatanFace::on_pushButton_36_clicked()

{ buttonClicked = ui->pushButton_36;   emit structMeth(buttonClicked->x(),buttonClicked->y(),3,-2,1);


}


/**

 * @brief CatanFace::on_pushButton_115_clicked

 */

void CatanFace::on_pushButton_37_clicked()

{ buttonClicked = ui->pushButton_37;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,-1,1);


}


/**

 * @brief CatanFace::on_pushButton_51_clicked

 */

void CatanFace::on_pushButton_38_clicked()

{ buttonClicked = ui->pushButton_38;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,-1,1);

}


/**

 * @brief CatanFace::on_pushButton_119_clicked

 */

void CatanFace::on_pushButton_39_clicked()

{ buttonClicked = ui->pushButton_39;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-1,1);


}


/**

 * @brief CatanFace::on_pushButton_52_clicked

 */

void CatanFace::on_pushButton_40_clicked()

{ buttonClicked = ui->pushButton_40;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-1,1);


}


/**

 * @brief CatanFace::on_pushButton_121_clicked

 */

void CatanFace::on_pushButton_41_clicked()

{ buttonClicked = ui->pushButton_41;   emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-1,1);


}


/**

 * @brief CatanFace::on_pushButton_53_clicked

 */

void CatanFace::on_pushButton_42_clicked()

{ buttonClicked = ui->pushButton_42;   emit structMeth(buttonClicked->x(),buttonClicked->y(),3,-1,1);


}


/**

 * @brief CatanFace::on_pushButton_54_clicked

 */

void CatanFace::on_pushButton_43_clicked()

{ buttonClicked = ui->pushButton_43;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,0,1);


}


/**

 * @brief CatanFace::on_pushButton_55_clicked

 */

void CatanFace::on_pushButton_44_clicked()

{ buttonClicked = ui->pushButton_44;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,0,1);


}


/**

 * @brief CatanFace::on_pushButton_120_clicked

 */

void CatanFace::on_pushButton_45_clicked()

{ buttonClicked = ui->pushButton_45;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,0,1);


}


/**

 * @brief CatanFace::on_pushButton_125_clicked

 */

void CatanFace::on_pushButton_46_clicked()

{ buttonClicked = ui->pushButton_46;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,0,1);

}


/**

 * @brief CatanFace::on_pushButton_56_clicked

 */

void CatanFace::on_pushButton_47_clicked()

{ buttonClicked = ui->pushButton_47;   emit structMeth(buttonClicked->x(),buttonClicked->y(),2,0,1);

}


/**

 * @brief CatanFace::on_pushButton_126_clicked

 */

void CatanFace::on_pushButton_48_clicked()

{ buttonClicked = ui->pushButton_48;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,1,1);

}


/**

 * @brief CatanFace::on_pushButton_57_clicked

 */

void CatanFace::on_pushButton_49_clicked()

{ buttonClicked = ui->pushButton_49;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,1,1);

}


/**

 * @brief CatanFace::on_pushButton_127_clicked

 */

void CatanFace::on_pushButton_50_clicked()

{ buttonClicked = ui->pushButton_50;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,1,1);

}


/**

 * @brief CatanFace::on_pushButton_58_clicked

 */

void CatanFace::on_pushButton_51_clicked()

{ buttonClicked = ui->pushButton_51;   emit structMeth(buttonClicked->x(),buttonClicked->y(),1,1,1);

}


/**

 * @brief CatanFace::on_pushButton_128_clicked

 */

void CatanFace::on_pushButton_52_clicked()

{ buttonClicked = ui->pushButton_52;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,2,1);

}


/**

 * @brief CatanFace::on_pushButton_88_clicked

 */

void CatanFace::on_pushButton_53_clicked()

{ buttonClicked = ui->pushButton_53;   emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,2,1);

}


/**

 * @brief CatanFace::on_pushButton_92_clicked

 */

void CatanFace::on_pushButton_54_clicked()

{ buttonClicked = ui->pushButton_54;   emit structMeth(buttonClicked->x(),buttonClicked->y(),0,2,1);

}
//--------------------------------------------------------end of city and settlement buttons
//-------------------------------------------------------below this are road buttons----------------------------------------------------------------------------------



// -------------------------------------draw Roads --------------- +  roadScale*root3-------------------------------///////////////////


void CatanFace::drawUpLeftRoad(int X, int Y)
{
    if(canPlaceRoad)
    {
        pointX = X;
        pointY = Y;
        setRoad(pointX-offset - roadScale*root3, pointY+ roadScale+yRoadOffset,pointX - offset +  roadScale*root3, pointY- roadScale+yRoadOffset);
        canPlaceRoad = false;
    }
}

void CatanFace::drawUpDownRoad(int X, int Y)
{
    if(canPlaceRoad)
    {
        pointX = X;
        pointY = Y;
        setRoad(pointX-offset, pointY+ 10 + roadScale+yRoadOffset,pointX - offset, pointY- 10 -roadScale+yRoadOffset);
        canPlaceRoad = false;
    }
}

void CatanFace::drawUpRightRoad(int X, int Y)
{
    if(canPlaceRoad)
    {
        pointX = X;
        pointY = Y;
        setRoad(pointX-offset -  roadScale*root3, pointY- roadScale +yRoadOffset,pointX - offset +  roadScale*root3, pointY + roadScale+yRoadOffset);
        canPlaceRoad = false;
    }
}

void CatanFace::drawRoad(int X, int Y, int type)
{
    if(type==4)
    {
        drawUpRightRoad(X,Y);

    }else if(type==2)
    {
        drawUpLeftRoad(X,Y);
    }else if(type==3)
    {
        drawUpDownRoad(X,Y);
    }
}

// -----------------------------------------------------------------------------------------------//////////////////
/**

 * @brief CatanFace::on_upRightRoad_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-2,2);

}


/**

 * @brief CatanFace::on_upRightRoad_2_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_2_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_2; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-2,2);


}


/**

 * @brief CatanFace::on_upRightRoad_3_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_3_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_3; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-2,2);



}


/**

 * @brief CatanFace::on_upRightRoad_3_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_4_clicked()

{


    roadType = 2;

    buttonClicked = ui->upRightRoad_4; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,-1,2);


}


/**

 * @brief CatanFace::on_upRightRoad_6_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_5_clicked()

{


    roadType = 2;

    buttonClicked = ui->upRightRoad_5; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-1,2);

}


/**

 * @brief CatanFace::on_upRightRoad_6_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_6_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_6; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-1,2);

}


/**

 * @brief CatanFace::on_upRightRoad_4_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_7_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_7; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-1,2);

}


/**

 * @brief CatanFace::on_upRightRoad_8_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_8_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_8; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,0,2);

}


/**

 * @brief CatanFace::on_upRightRoad_9_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_9_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_9; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,0,2);

}


/**

 * @brief CatanFace::on_upRightRoad_10_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_10_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_10; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,0,2);

}


/**

 * @brief CatanFace::on_upRightRoad_11_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_11_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_11; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,0,2);

}


/**

 * @brief CatanFace::on_upRightRoad_11_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_12_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_12; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,0,2);

}


/**

 * @brief CatanFace::on_upRightRoad_12_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_13_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_13; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,1,2);

}


/**

 * @brief CatanFace::on_upRightRoad_16_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_14_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_14; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,1,2);

}


/**

 * @brief CatanFace::on_upRightRoad_15_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_15_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_15; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,1,2);

}


/**

 * @brief CatanFace::on_upRightRoad_13_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_16_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_16; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,1,2);

}


/**

 * @brief CatanFace::on_upRightRoad_14_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_17_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_17; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,1,2);

}


/**

 * @brief CatanFace::on_upRightRoad_24_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_18_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_18; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,2,2);

}


/**

 * @brief CatanFace::on_upRightRoad_22_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_19_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_19; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,2,2);

}


/**

 * @brief CatanFace::on_upRightRoad_20_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_20_clicked()

{

    roadType = 2;

    buttonClicked = ui->upRightRoad_20; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,2,2);

}


/**

 * @brief CatanFace::on_upRightRoad_18_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_21_clicked()

{


    roadType = 2;

    buttonClicked = ui->upRightRoad_21; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,2,2);


}


/**

 * @brief CatanFace::on_upRightRoad_19_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_22_clicked()

{


    roadType = 2;

    buttonClicked = ui->upRightRoad_22; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,3,2);


}


/**

 * @brief CatanFace::on_upRightRoad_21_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_23_clicked()

{


    roadType = 2;

    buttonClicked = ui->upRightRoad_23; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,3,2);


}


/**

 * @brief CatanFace::on_upRightRoad_23_clicked creates a road from right node to left node going up if boughtroad is true

 */

void CatanFace::on_upRightRoad_24_clicked()

{


    roadType = 2;

    buttonClicked = ui->upRightRoad_24; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,3,2);


}

//-------------------------------------------------------now upleftRoads-------------------------------------------------------------------------


/**

 * @brief CatanFace::on_upLeftRoad_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_clicked()

{


    roadType = 4;

    buttonClicked = ui->upLeftRoad; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-3,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_2_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_2_clicked()

{



    roadType = 4;

    buttonClicked = ui->upRightRoad_2; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-3,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_3_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_3_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_3; emit structMeth(buttonClicked->x(),buttonClicked->y(),3,-3,4);

}


/**

 * @brief CatanFace::on_upLeftRoad_4_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_4_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_4; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-2,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_5_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_5_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_5; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-2,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_6_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_6_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_6; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-2,4);

}


/**

 * @brief CatanFace::on_upLeftRoad_7_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_7_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_7; emit structMeth(buttonClicked->x(),buttonClicked->y(),3,-2,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_13_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_8_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_8; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,-1,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_15_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_9_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_9; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-1,4);

}


/**

 * @brief CatanFace::on_upLeftRoad_14_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_10_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_10; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-1,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_16_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_11_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_11; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-1,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_8_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_12_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_12; emit structMeth(buttonClicked->x(),buttonClicked->y(),3,-1,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_23_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_13_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_13; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,0,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_12_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_14_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_14; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,0,4);

}


/**

 * @brief CatanFace::on_upLeftRoad_11_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_15_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_15; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,0,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_9_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_16_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_16; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,0,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_10_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_17_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_17; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,0,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_24_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_18_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_18; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,1,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_17_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_19_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_19; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,1,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_22_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_20_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_20; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,1,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_21_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_21_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_21; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,1,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_18_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_22_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_22; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,2,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_19_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_23_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_23; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,2,4);


}


/**

 * @brief CatanFace::on_upLeftRoad_20_clicked creates a road from left node to right node going up if boughtroad is true

 */

void CatanFace::on_upLeftRoad_24_clicked()

{



    roadType = 4;

    buttonClicked = ui->upLeftRoad_24; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,2,4);


}

//------------------------------------------------------------now upDownRoads-----------------------------------------------------------------------------------------


/**

 * @brief CatanFace::on_upDownRoad_2_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_clicked()

{



    roadType = 3;

    buttonClicked = ui->upDownRoad; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,-2,3);

}


/**

 * @brief CatanFace::on_upDownRoad_3_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_2_clicked()

{



    roadType = 3;

    buttonClicked = ui->upDownRoad_2; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-2,3);


}


/**

 * @brief CatanFace::on_upDownRoad_4_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_3_clicked()

{



    roadType = 3;

    buttonClicked = ui->upDownRoad_3; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-2,3);


}


/**

 * @brief CatanFace::on_upDownRoad_5_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_4_clicked()

{



    roadType = 3;

    buttonClicked = ui->upDownRoad_4; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-2,3);



}


/**

 * @brief CatanFace::on_upDownRoad_10_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_5_clicked()

{



    roadType = 3;

    buttonClicked = ui->upDownRoad_5; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,-1,3);


}


/**

 * @brief CatanFace::on_upDownRoad_9_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_6_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_6; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,-1,3);

}


/**

 * @brief CatanFace::on_upDownRoad_8_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_7_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_7; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,-1,3);

}


/**

 * @brief CatanFace::on_upDownRoad_7_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_8_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_8; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,-1,3);

}


/**

 * @brief CatanFace::on_upDownRoad_6_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_9_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_9; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,-1,3);


}


/**

 * @brief CatanFace::on_upDownRoad_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_10_clicked()

{


    roadType = 3;

    buttonClicked = ui->upDownRoad_10; emit structMeth(buttonClicked->x(),buttonClicked->y(),-3,0,3);


}


/**

 * @brief CatanFace::on_upDownRoad_11_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_11_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_11; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,0,3);

}


/**

 * @brief CatanFace::on_upDownRoad_12_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_12_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_12; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,0,3);

}


/**

 * @brief CatanFace::on_upDownRoad_13_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_13_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_13; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,0,3);

}


/**

 * @brief CatanFace::on_upDownRoad_14_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_14_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_14; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,0,3);

}


/**

 * @brief CatanFace::on_upDownRoad_15_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_15_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_15; emit structMeth(buttonClicked->x(),buttonClicked->y(),2,0,3);

}


/**

 * @brief CatanFace::on_upDownRoad_20_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_16_clicked()

{


    roadType = 3;

    buttonClicked = ui->upDownRoad_16; emit structMeth(buttonClicked->x(),buttonClicked->y(),-3,1,3);

}


/**

 * @brief CatanFace::on_upDownRoad_19_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_17_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_17; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,1,3);

}


/**

 * @brief CatanFace::on_upDownRoad_18_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_18_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_18; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,1,3);

}


/**

 * @brief CatanFace::on_upDownRoad_17_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_19_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_19; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,1,3);

}


/**

 * @brief CatanFace::on_upDownRoad_16_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_20_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_20; emit structMeth(buttonClicked->x(),buttonClicked->y(),1,1,3);

}


/**

 * @brief CatanFace::on_upDownRoad_21_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_21_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_21; emit structMeth(buttonClicked->x(),buttonClicked->y(),-3,2,3);

}


/**

 * @brief CatanFace::on_upDownRoad_22_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_22_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_22; emit structMeth(buttonClicked->x(),buttonClicked->y(),-2,2,3);

}


/**

 * @brief CatanFace::on_upDownRoad_23_clicked creates a road  from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_23_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_23; emit structMeth(buttonClicked->x(),buttonClicked->y(),-1,2,3);

}


/**

 * @brief CatanFace::on_upDownRoad_24_clicked creates a road from down node to up node going up if boughtroad is true

 */

void CatanFace::on_upDownRoad_24_clicked()

{

    roadType = 3;

    buttonClicked = ui->upDownRoad_24; emit structMeth(buttonClicked->x(),buttonClicked->y(),0,2,3);


}
//--------------------------------------------------Other buttons-------------------------------------------------------------------------------------
void CatanFace::on_robber_clicked()
{

}



void CatanFace::on_rob_1_clicked()
{
    if(canRob){
        qDebug() << "clicked";
        ui->robber->move(ui->rob_1->x(),ui->rob_1->y());
        emit robberCords(0,-2,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_2_clicked()
{
    if(canRob){
        ui->robber->move(ui->rob_2->x(),ui->rob_2->y());
        emit robberCords(1,-2,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_3_clicked()
{
    if(canRob){
        ui->robber->move(ui->rob_3->x(),ui->rob_3->y());
        emit robberCords(2,-2,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_4_clicked()
{
    if(canRob){
        ui->robber->move(ui->rob_4->x(),ui->rob_4->y());
        emit robberCords(-1,-1,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_5_clicked()
{
    if(canRob){
        ui->robber->move(ui->rob_5->x(),ui->rob_5->y());
        emit robberCords(0,-1,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_6_clicked()
{
    if(canRob){
        ui->robber->move(ui->rob_6->x(),ui->rob_6->y());
        emit robberCords(1,-1,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_7_clicked()
{
    if(canRob){
        ui->robber->move(ui->rob_7->x(),ui->rob_7->y());
        emit robberCords(2,-1,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_8_clicked()
{
    if(canRob){
        ui->robber->move(ui->rob_8->x(),ui->rob_8->y());
        emit robberCords(-2,0,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_9_clicked()
{
    if(canRob)
    {
        ui->robber->move(ui->rob_9->x(),ui->rob_9->y());
        emit robberCords(-1,0,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_10_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_10->x(),ui->rob_10->y());
        emit robberCords(0,0,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_11_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_11->x(),ui->rob_11->y());
        emit robberCords(1,0,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_12_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_12->x(),ui->rob_12->y());
        emit robberCords(2,0,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_13_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_13->x(),ui->rob_13->y());
        emit robberCords(-2,1,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_14_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_14->x(),ui->rob_14->y());
        emit robberCords(-1,1,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_15_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_15->x(),ui->rob_15->y());
        emit robberCords(0,1,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_16_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_16->x(),ui->rob_16->y());
        emit robberCords(1,1,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_17_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_17->x(),ui->rob_17->y());
        emit robberCords(-2,2,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_18_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_18->x(),ui->rob_18->y());
        emit robberCords(1,-2,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}
void CatanFace::on_rob_19_clicked()
{
    if(canRob == true){
        ui->robber->move(ui->rob_19->x(),ui->rob_19->y());
        emit robberCords(0,2,9,ui->robber->x(), ui->robber->y());
        canRob = false;
    }
}



void CatanFace::on_p2_clicked()
{
    player = "0";
    wool = ui->wool->text();
    grain = ui->grain->text();
    lumber = ui->lumber->text();
    ore = ui->ore->text();
    brick = ui->brick->text();
}

void CatanFace::on_p1_clicked()
{
    player = "1";
    wool = ui->wool->text();
    grain = ui->grain->text();
    lumber = ui->lumber->text();
    ore = ui->ore->text();
    brick = ui->brick->text();
}

void CatanFace::on_p5_clicked()
{
    player = "2";
    wool = ui->wool->text();
    grain = ui->grain->text();
    lumber = ui->lumber->text();
    ore = ui->ore->text();
    brick = ui->brick->text();
}

void CatanFace::on_p4_clicked()
{
    player = "3";
    wool = ui->wool->text();
    grain = ui->grain->text();
    lumber = ui->lumber->text();
    ore = ui->ore->text();
    brick = ui->brick->text();
}

void CatanFace::on_offer_clicked()
{
    emit sendOffer(brick,wool,ore,grain,lumber,player);
}



void CatanFace::on_knight_2_clicked()
{
    emit playable(0);
}

void CatanFace::on_yearplenty_clicked()
{
    if(resourceChooser->isHidden()){
        resourceChooser->show();
    }
    resourceChooser->playableType(0);

}

void CatanFace::on_roadbuilding_clicked()
{
    emit playable(2);
}

void CatanFace::on_monopoly_2_clicked()
{
    if(resourceChooser->isHidden()){
        resourceChooser->show();
    }
    resourceChooser->playableType(1);
}

void CatanFace::on_victory_clicked()
{
    emit playable(4);
}

