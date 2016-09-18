#ifndef ANCHOR_H
#define ANCHOR_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

#include <QTimer>
#include <QList>
#include <typeinfo>

#include <QPen>
#include <QBrush>
#include <QColor>
#include <QPointF>
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsLineItem>

#include <QDebug>

#include "anchordialogbox.h"
#include "pinhole.h"
#include "newbar.h"

#define PI 3.14159265

class Anchor: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Anchor(QGraphicsItem *parent = NULL);
    ~Anchor();

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void setAnchorMassCenter(QPointF _massCenter);
    void setAnchorAngle(double _anchorAngle);

    void createDialogBox();
    void initializeAnchor();
    void drawGoundLine();

    QPointF rotationMatrix(double _x, double _y, double _theta);
    QPointF rotationMatrix(QPointF _vect, double _theta);

    void setDontMove(bool trueOrFalse);


    QPointF getQtMassCenter();
    double getQtAnchorAngle();

public slots:
    void changeAnchorAngle(double _anchorAngle);
    void changeAnchorMassCenter(QPointF _massCenter);

    QPointF getAnchorMassCenter();
    double getAnchorRadius();
    double getAnchorDiameter();
    double getAnchorAngle();
    QPointF getAbsPinPos(PinHole* hole);

    void collisionDetected(PinHole* hole, PinHole* collideItem);

signals:
    void createRJoint(PinHole* pinA, PinHole* pinB, QPointF jointCenter);

private:

    double anchorDiameter;
    double anchorRadius;
    double anchorAngle;
    QPointF massCenter;

    PinHole* pin;
    double holeDiameter;
    double holeRadius;

    QPolygonF tri;
    QGraphicsPolygonItem* triangle;

    QPointF offset;
    QColor circleColor;
    QColor triangleColor;
    QColor transparent;
    int alpha;
    int alphaWhenHover;

    double slashLineWidth;
    QColor slashLineColor;
    double underLineWidth;
    QColor underLineColor;

    bool dontMove;

    AnchorDialogBox* dialog;
};

#endif // ANCHOR_H
