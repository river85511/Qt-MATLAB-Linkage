#include "globalcoordinate.h"

GlobalCoordinate::GlobalCoordinate(QGraphicsItem *parent): QGraphicsEllipseItem(parent),
    axisWidth(1.0), transparent(QColor(0,0,0,0)),
    originFontSize(3.5), xyFontSize(3)
{
    setRect(0,0,0,0);

    xaxis = new QGraphicsLineItem(this);
    xaxis->setLine(0,0,50,0);
    xaxis->setPen(QPen(Qt::green,axisWidth));
    yaxis = new QGraphicsLineItem(this);
    yaxis->setLine(0,0,0,-50);
    yaxis->setPen(QPen(Qt::red,axisWidth));

    xhead << QPoint(50,1);
    xhead << QPoint(53,0);
    xhead << QPoint(50,-1);
    xarrow = new QGraphicsPolygonItem(xhead,xaxis);
    xarrow->setBrush(Qt::green);
    xarrow->setPen(transparent);

    yhead << QPoint(1,-50);
    yhead << QPoint(0,-53);
    yhead << QPoint(-1,-50);
    yarrow = new QGraphicsPolygonItem(yhead,yaxis);
    yarrow->setBrush(Qt::red);
    yarrow->setPen(transparent);

    originMark = new QGraphicsTextItem("O",this);
    originMark->setPos(-10,-3);
    QFont originMarkFont("O",originFontSize,QFont::Bold,true);
    originMark->setFont(originMarkFont);

    xMark = new QGraphicsTextItem("x",this);
    xMark->setPos(50,-7);
    QFont xMarkFont("x",xyFontSize,QFont::Bold,true);
    xMark->setFont(xMarkFont);

    yMark = new QGraphicsTextItem("y",this);
    yMark->setPos(-6,-64);
    QFont yMarkFont("y",xyFontSize,QFont::Bold,true);
    yMark->setFont(yMarkFont);

    idMark = new QGraphicsTextItem("0",this);
    idMark->setPos(-1,-1);
    QFont idMarkFont("0",6,QFont::Bold);
    idMark->setFont(idMarkFont);
}
