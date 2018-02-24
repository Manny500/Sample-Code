#ifndef CATANFACE_H
#define CATANFACE_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QColor>
#include <QDialog>
#include <QtWidgets>
#include <QtGui>
#include <QMouseEvent>
#include <QTcpSocket>
#include "Client.h"
#include "Chat.h"
#include "CatanChooseResource.h"

namespace Ui
{
class CatanFace;
}

class CatanFace : public QDialog
{
    Q_OBJECT

public:
    Ui::CatanFace *ui;
    explicit CatanFace(QWidget *parent = 0, Client *c = 0, int color = 0, QStringList* users = 0);
    ~CatanFace();
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *event);


    void setHex(float centerX, float centerY, float skale);
    void setGrid(float startX, float startY, float skale, int numRows, int numCols);
    void setRoad(float startX, float startY, float endX, float endY);
    void setRoad(float startX, float startY, float endX, float endY, QColor col);
    void setCity(float centerX, float centerY);
    void setSettlement(float centerX, float centerY);
    void setBrush(QColor col, QPen *pen);
    void setColor(QColor col);

    void drawCitySettlements(int X, int Y);
    void drawRoad(int X, int Y, int type);// type can be 1, 2, or 3, corresponding to the type of road
    void drawUpLeftRoad(int X, int Y);
    void drawUpRightRoad(int X, int Y);
    void drawUpDownRoad(int X, int Y);
    void updateStats(QString msg);
    void setConstructionType(int type);
    void setOppColor(int type);
    void setYourColor(int type);



signals:
    // void mouseClick(QGraphicsSceneMouseEvent *mouseEvent);
    void structMeth(int butX, int butY, int x, int y, int z);
    void robberCords(int x,int y, int z,int robx, int roby);
    void request(unsigned int constructionType);
    void sendOffer(QString a,QString b, QString c, QString d, QString e,QString f);
    void playable(int cardType);
    void endTurn();


private slots:

    void decipher(QString q);
    void on_chat_clicked();
    //void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

    void on_pushBS_clicked();
    void on_pushBC_clicked();
    void on_pushBR_clicked();
    void on_pushBD_clicked();

    void on_pushEndTurn_clicked();

    //these buttons are where cities and settlements go
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();
    void on_pushButton_29_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_42_clicked();
    void on_pushButton_43_clicked();
    void on_pushButton_44_clicked();
    void on_pushButton_45_clicked();
    void on_pushButton_46_clicked();
    void on_pushButton_47_clicked();
    void on_pushButton_48_clicked();
    void on_pushButton_49_clicked();
    void on_pushButton_50_clicked();
    void on_pushButton_51_clicked();
    void on_pushButton_52_clicked();
    void on_pushButton_53_clicked();
    void on_pushButton_54_clicked();
    //city and settlement button end

    void on_upRightRoad_clicked();
    void on_upRightRoad_2_clicked();
    void on_upRightRoad_3_clicked();
    void on_upRightRoad_7_clicked();
    void on_upRightRoad_6_clicked();
    void on_upRightRoad_5_clicked();
    void on_upRightRoad_4_clicked();
    void on_upRightRoad_8_clicked();
    void on_upRightRoad_9_clicked();
    void on_upRightRoad_10_clicked();
    void on_upRightRoad_11_clicked();
    void on_upRightRoad_12_clicked();
    void on_upRightRoad_17_clicked();
    void on_upRightRoad_16_clicked();
    void on_upRightRoad_15_clicked();
    void on_upRightRoad_13_clicked();
    void on_upRightRoad_14_clicked();
    void on_upRightRoad_24_clicked();
    void on_upRightRoad_22_clicked();
    void on_upRightRoad_20_clicked();
    void on_upRightRoad_18_clicked();
    void on_upRightRoad_19_clicked();
    void on_upRightRoad_21_clicked();
    void on_upRightRoad_23_clicked();
    void on_upLeftRoad_clicked();
    void on_upLeftRoad_2_clicked();
    void on_upLeftRoad_3_clicked();
    void on_upLeftRoad_4_clicked();
    void on_upLeftRoad_5_clicked();
    void on_upLeftRoad_6_clicked();
    void on_upLeftRoad_7_clicked();
    void on_upLeftRoad_13_clicked();
    void on_upLeftRoad_15_clicked();
    void on_upLeftRoad_14_clicked();
    void on_upLeftRoad_16_clicked();
    void on_upLeftRoad_8_clicked();
    void on_upLeftRoad_23_clicked();
    void on_upLeftRoad_12_clicked();
    void on_upLeftRoad_11_clicked();
    void on_upLeftRoad_9_clicked();
    void on_upLeftRoad_10_clicked();
    void on_upLeftRoad_24_clicked();
    void on_upLeftRoad_17_clicked();
    void on_upLeftRoad_22_clicked();
    void on_upLeftRoad_21_clicked();
    void on_upLeftRoad_18_clicked();
    void on_upLeftRoad_19_clicked();
    void on_upLeftRoad_20_clicked();
    void on_upDownRoad_2_clicked();
    void on_upDownRoad_3_clicked();
    void on_upDownRoad_4_clicked();
    void on_upDownRoad_5_clicked();
    void on_upDownRoad_10_clicked();
    void on_upDownRoad_9_clicked();
    void on_upDownRoad_8_clicked();
    void on_upDownRoad_7_clicked();
    void on_upDownRoad_6_clicked();
    void on_upDownRoad_clicked();
    void on_upDownRoad_11_clicked();
    void on_upDownRoad_12_clicked();
    void on_upDownRoad_13_clicked();
    void on_upDownRoad_14_clicked();
    void on_upDownRoad_15_clicked();
    void on_upDownRoad_20_clicked();
    void on_upDownRoad_19_clicked();
    void on_upDownRoad_18_clicked();
    void on_upDownRoad_17_clicked();
    void on_upDownRoad_16_clicked();
    void on_upDownRoad_21_clicked();
    void on_upDownRoad_22_clicked();
    void on_upDownRoad_23_clicked();
    void on_upDownRoad_24_clicked();

    void on_robber_clicked();

    void on_rob_1_clicked();
    void on_rob_2_clicked();
    void on_rob_3_clicked();
    void on_rob_4_clicked();
    void on_rob_5_clicked();
    void on_rob_6_clicked();
    void on_rob_7_clicked();
    void on_rob_8_clicked();
    void on_rob_9_clicked();
    void on_rob_10_clicked();
    void on_rob_11_clicked();
    void on_rob_12_clicked();
    void on_rob_13_clicked();
    void on_rob_14_clicked();
    void on_rob_15_clicked();
    void on_rob_16_clicked();
    void on_rob_17_clicked();
    void on_rob_18_clicked();
    void on_rob_19_clicked();



    void on_p2_clicked();

    void on_p1_clicked();

    void on_p5_clicked();

    void on_p4_clicked();

    void on_offer_clicked();

    void on_knight_2_clicked();

    void on_yearplenty_clicked();

    void on_roadbuilding_clicked();

    void on_monopoly_2_clicked();

    void on_victory_clicked();

private:

    QPushButton* buttonClicked;

    int width;
    int height;
    int countRoadPt;
    int playerNum, dice;
    int roadType;

    int returnConstruction;
    int isAffordable;
    int canPlaceConstruction;
    int constructionType;

    float pointX, pointY;
    float offset;
    float yRoadOffset, roadScale;
    float root3;

    QString str;
    QPolygonF shape;
    QLineF *road;
    QPointF pointme;
    QColor playerFillColor, playerLineColor;
    QColor oppPlayerFillColor, oppPlayerLineColor;
    QColor yourFillColor, yourLineColor;

    bool canPlaceSettlement;
    bool canPlaceRoad;
    bool canPlaceCity;
    bool currentPlayer;

    bool buttonLock, canRob;
    Client *client;
    Chat *chatBox;
    CatanChooseResource *resourceChooser;

    QString ore;
    QString lumber;
    QString brick;
    QString wool;
    QString player;
    QString grain;




};

#endif // CatanFace_H
