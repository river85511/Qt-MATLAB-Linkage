#ifndef NEWBAR_H
#define NEWBAR_H

#include <QPointF>
#include <QBrush>
#include <QColor>
#include <QPen>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QMenu>
#include <QObject>

#include <QDebug>

#include "pinhole.h"
#include "anchor.h"
#include "newbardialogbox.h"

#define PI 3.14159265

class NewBar: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    NewBar(bool _showHideCoordinate, int _id, QGraphicsItem* parent = NULL);
    ~NewBar();

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void setMassCenter(QPointF _massCenter);
    void setRectWidth(double _rectWidth);
    void setRectAngle(double _rectAngle);
    void setRectColor(QColor _color);

    void setAngularVel(double _angularVel);
    void setAngularAcc(double _angularAcc);
    double getAngularVel();
    double getAngularAcc();

    void createDialogBox();
    void initializeBar();

    QPointF rotationMatrix(double _x, double _y, double _theta);
    QPointF rotationMatrix(QPointF _vect, double _theta);

    void setDontMove(bool trueOrFalse);

    QPointF getQtRectMassCenter();
    double getQtRectAngle();

    int id;
    bool isDrivingLink;

public slots:
    void changeRectWidth(double _rectWidth);
    void changeRectAngle(double _rectAngle);
    void changeRectMassCenter(QPointF _massCenter);
    void changeRectColor(QColor _color);

    void changeAngularVel(double  _angularVel);
    void changeAngularAcc(double  _angularAcc);

    QPointF getRectMassCenter();
    double getRectWidth();
    double getRectHeight();
    double getRectAngle();
    double getRectAngleRadians();
    QPointF getAbsPinPos(PinHole* hole);


    void collisionDetected(PinHole* hole, PinHole* collideItem);

    void showHideCoordinate(bool open);

    void setAsDrivingLink(bool _isDrivingLink);

signals:
    void createRJoint(PinHole* pinA, PinHole* pinB, QPointF jointCenter);
    void setDrivingLink(bool isDrivingLink, int id);

private:

    double rectWidth;
    double rectHeight;
    double rectAngle;
    QPointF massCenter;

    double angularVel;
    double angularAcc;

    QGraphicsEllipseItem* leftCircle;
    QGraphicsEllipseItem* rightCircle;
    double circleDiameter;
    double circleRadius;

    PinHole* leftHole;
    PinHole* rightHole;
    double holeDiameter;
    double holeRadius;

    QGraphicsEllipseItem* midCircle;
    double midCircleDiameter;
    double midCircleRadius;

    //xyaxis & marks
    QGraphicsLineItem* xaxis;
    QGraphicsLineItem* yaxis;
    double axisLength;

    QGraphicsTextItem* xMark;
    QGraphicsTextItem* yMark;
    QGraphicsTextItem* idMark;

    //show or hide coordinates
    bool showOrHide;

    QPointF offset;

    QColor color;
    int alpha;
    int alphaWhenHover;

    bool dontMove;
    int pJointConnectingId;

    NewBarDialogBox* dialog;
};

#endif // NEWBAR_H
