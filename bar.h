#ifndef BAR_H
#define BAR_H

#include <cmath>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

#include <QBrush>
#include <QColor>
#include <QPointF>
#include <QObject>
#include <QGraphicsEllipseItem>

#include <QDebug>

#include "bardialogbox.h"

#define PI 3.14159265

class Bar: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Bar(QGraphicsItem *parent = NULL);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void createDialogBox();

public slots:
    void changeAngle(float angle);
    void changeMassCenter(QPointF mc);
    void changeLength(float length);

private:
    QPointF offset;
    QColor* color;
    BarDialogBox* dialog;
    QGraphicsEllipseItem* origin;

};

#endif // BAR_H
