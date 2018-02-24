#ifndef HEXGRID_H
#define HEXGRID_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsPolygonItem>
#include <qcolor.h>
#include <qpixmap.h>
#include <algorithm>
#include <qpainter.h>
#include "Hexagon.h"

namespace Ui {
class HexGrid;
}

class HexGrid : public QWidget
{
    Q_OBJECT

public:
    HexGrid();
    HexGrid(float startX, float startY, int rows, int columns, float skal);
    ~HexGrid();

    Ui::HexGrid *ui;
    QVector<Hexagon*> *grid;
    float xStart;
    float yStart;
    float skale;
    int numRows;
    int numCols;
    int numHexes;


    void paintEvent(QPaintEvent *event);


private:

protected:

};

#endif // HEXGRID_H
