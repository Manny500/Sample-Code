#include "PieceBuilder.h"
#include "ui_PieceBuilder.h"

PieceBuilder::PieceBuilder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PieceBuilder)
{
    ui->setupUi(this);
}

PieceBuilder::~PieceBuilder()
{
    delete ui;
}

void PieceBuilder::paintEvent(QPaintEvent *event)
{
    ui->setupUi(this);
}

void PieceBuilder::paintRoad(float xStart, float yStart, float xEnd, float yEnd)
{
    QPainter painter(this);
    startX = xStart;
    startY = yStart;
    endX = xEnd;
    endY = yEnd;

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 3, Qt::DashDotLine, Qt::RoundCap));
}

void PieceBuilder::paintCity(float xCord, float yCord)
{
    xCenter = xCord;
    yCenter = yCord;
    startX = xCord;
    startY = yCord;
    endX = xCord;
    endY = yCord;


}

void PieceBuilder::paintSettlement(float xCord, float yCord)
{
    xCenter = xCord;
    yCenter = yCord;
    startX = xCord;
    startY = yCord;
    endX = xCord;
    endY = yCord;
}

void PieceBuilder::setX(float x)
{
    xCenter = x;
}
void PieceBuilder::setY(float y)
{
    yCenter = y;
}
