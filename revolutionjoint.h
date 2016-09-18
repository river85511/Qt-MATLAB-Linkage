#ifndef REVOLUTIONJOINT_H
#define REVOLUTIONJOINT_H


#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QPen>

#include <QList>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>

#include <QDebug>

#include "newbar.h"
#include "slide.h"
#include "anchor.h"

#include "pinhole.h"


class RevolutionJoint:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    RevolutionJoint(PinHole* _pinA, PinHole* _pinB, QGraphicsItem* parent = NULL);

    void initializeRevolutionJoint();
    void stopPinTimer();
    void setPinIsJointed(bool trueOrFalse);
    void setBarDontMove(bool trueOrFalse);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);


    double jointDiameter;
    double jointRadius;

    QGraphicsEllipseItem *innerCircle;
    double innerCircleDiameter;
    double innerCircleRadius;

    void setCenter(QPointF _jointCenter);

    QPointF getJointCenter();

    QTimer* timer;

    PinHole* pinA;
    PinHole* pinB;

public slots:
    void removeJoint();
    void checkCollision();

private:
    QPointF jointCenter;

//    PinHole* pinA;
//    PinHole* pinB;

};

#endif // REVOLUTIONJOINT_H
