#ifndef PIECEBUILDER_H
#define PIECEBUILDER_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsPolygonItem>
#include <qcolor.h>
#include <qpixmap.h>
#include <algorithm>
#include <qpainter.h>

namespace Ui {
class PieceBuilder;
}

class PieceBuilder : public QWidget
{
    Q_OBJECT

public:
    explicit PieceBuilder(QWidget *parent = 0);
    ~PieceBuilder();

private:
    Ui::PieceBuilder *ui;
    QPushButton *pushButton;
    QColor col;
    float xCenter, yCenter;
    float startX, startY, endX, endY;

    QPolygonF shape;


protected:
    void paintEvent(QPaintEvent *event);
    void paintRoad(float xStart, float yStart, float xEnd, float yEnd);
    void paintCity(float xCord, float yCord);
    void paintSettlement(float xCord, float yCord);
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
};

#endif // PIECEBUILDER_H
