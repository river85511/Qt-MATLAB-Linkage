#ifndef GLOBALCOORDINATE_H
#define GLOBALCOORDINATE_H

#include <QPointF>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QObject>
#include <QPen>

#include <QDebug>
#include <QString>
#include <QFont>

class GlobalCoordinate: public QGraphicsEllipseItem
{
public:
    GlobalCoordinate(QGraphicsItem *parent = NULL);

private:
    QGraphicsLineItem* xaxis;
    QGraphicsLineItem* yaxis;

    double axisWidth;

    QPolygonF xhead;
    QPolygonF yhead;

    QGraphicsPolygonItem* xarrow;
    QGraphicsPolygonItem* yarrow;

    QColor transparent;

    QGraphicsTextItem* originMark;
    QGraphicsTextItem* xMark;
    QGraphicsTextItem* yMark;
    QGraphicsTextItem* idMark;

    double originFontSize;
    double xyFontSize;

};

#endif // GLOBALCOORDINATE_H
