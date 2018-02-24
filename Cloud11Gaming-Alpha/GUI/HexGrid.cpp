#include "HexGrid.h"
#include "ui_HexGrid.h"

#include <QtGui>
#include <QGraphicsView>
#include <QGraphicsPolygonItem>
#include <qobject.h>
#include <qpainter.h>
#include <qbitmap.h>
#include <qfontmetrics.h>
#include <math.h>
#include "Hexagon.h"

HexGrid::HexGrid()
{
    ui->setupUi(this);

}
HexGrid::HexGrid(float startX, float startY, int rows, int columns, float skal)
{
    xStart = startX;
    yStart = startY;
    numRows = rows;
    numCols = columns;
    skale = skal;
}

HexGrid::~HexGrid()
{
    delete ui;
}

void HexGrid::paintEvent(QPaintEvent *event)
{
    ui->setupUi(this);

    QPainter painter(this);
    float root3 = (float)sqrt(3);

    Hexagon *hex = (new Hexagon(100.0,100.0,20.0));
    //grid.push_back(hex);

    //adding the hexagons to the vector
    for(int x = xStart; x<=numCols; x+=(3*skale))
    {
        for(int y = yStart; y<=numRows; y++)
        {
            if(x%2==0)//even
            {
                *grid << (new Hexagon((float)x,(float)y,skale));

            }else//odd
            {
                *grid << new Hexagon((float)x,(float)y+skale*root3,skale);

            }
            numHexes++;
        }
    }//end of loop

    for(int i = 0; i<numHexes; i++)
    {
        if(i%2==0)
            painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
        if(i%3==0)
            painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        if(i%5==0)
            painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));


        //painter.drawConvexPolygon(hex->getShape());

        painter.drawConvexPolygon((grid)->at(i)->getShape());


    }
}//end of paintEvent
