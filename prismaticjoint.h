#ifndef PRISMATICJOINT_H
#define PRISMATICJOINT_H

#include <QPointF>
#include <QPoint>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QDebug>

#include "slide.h"
#include "newbar.h"

#define PI 3.14159265

class PrismaticJoint: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    PrismaticJoint(Slide* _slide, QGraphicsItem *parent = NULL);
    ~PrismaticJoint();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

    void drawArrow();
    void setColor(QColor _color);

    void setPJointConnectingItem(NewBar* _pJointConnectingItem);
    QPointF getLocalVectorToTranslationAxis();
    QPointF inverseRotaionMatrix(QPointF _vect, double _theta);

    Slide* slide;
    NewBar* pJointConnectingItem;

public slots:
    void changePJointConnectingItem(NewBar* _pJointConnectingItem);

private:
//    Slide* slide;
//    int pJointConnectingId;

//    NewBar* pJointConnectingItem;

    double arrowXpos;
    double arrowYpos;
    double arrowWidth;
    double arrowHeight;

    QColor color;
    QColor transparent;

    QPolygonF leftArrowShape;
    QPolygonF rightArrowShape;
    QGraphicsPolygonItem *leftArrow;
    QGraphicsPolygonItem *rightArrow;

};

#endif // PRISMATICJOINT_H
