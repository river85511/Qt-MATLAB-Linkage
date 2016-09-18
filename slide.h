#ifndef SLIDE_H
#define SLIDE_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

#include <QBrush>
#include <QColor>
#include <QPointF>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>

#include <QDebug>

#include "anchor.h"
#include "pinhole.h"
#include "slidedialogbox.h"

class Slide: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Slide(bool _showHideCoordinate, int _id, QGraphicsItem *parent = NULL);
    ~Slide();

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void createDialogBox();
    void initializeSlide();

    QPointF rotationMatrix(double _x, double _y, double _theta);
    QPointF rotationMatrix(QPointF _vect, double _theta);

    void setDontMove(bool trueOrFalse);

    void setMassCenter(QPointF _massCenter);
    void setRectWidth(double _rectWidth);
    void setRectAngle(double _rectAngle);
    void setRectColor(QColor _color);

//    QPointF getRectMassCenter();
//    double getRectWidth();
//    double getRectHeight();
//    double getRectAngle();

    int id;
    bool isDrivingLink;

public slots:
    void changeRectAngle(double _rectAngle);
    void changeRectMassCenter(QPointF _massCenter);
    void changeRectColor(QColor _color);
    void changePJointConnectingId(int _pJointConnectingId);

    QPointF getRectMassCenter();
    double getRectWidth();
    double getRectHeight();
    double getRectAngle();
    double getRectAngleRadians();
    QPointF getAbsPinPos(PinHole* hole);

    QPointF getQtRectMassCenter();
    double getQtRectAngle();

    void getIdListFromDisplay(std::list<int> _idList);
    void collisionDetected(PinHole* hole, PinHole* collideItem);

    void showHideCoordinate(bool open);

signals:
    void createRJoint(PinHole* pinA, PinHole* pinB, QPointF jointCenter);

    void passConnectingIdToDisplay(int _pJointConnectingId);
    void passSlideIdToDialog(int _id);
    void passIdListToDialog(std::list<int> _idList);

    void returnMassCenter();
    void returnRectAngle();

private:

    double rectWidth;
    double rectHeight;
    double rectAngle;
    QPointF massCenter;

    QGraphicsEllipseItem* midCircle;
    double circleDiameter;
    double circleRadius;

    PinHole* midHole;
    double holeDiameter;
    double holeRadius;

    QPointF offset;

    QColor color;
    int alpha;
    int alphaWhenHover;

    //xyaxis & marks
    QGraphicsLineItem* xaxis;
    QGraphicsLineItem* yaxis;
    double axisLength;

    QGraphicsTextItem* xMark;
    QGraphicsTextItem* yMark;
    QGraphicsTextItem* idMark;

    //show or hide coordinates
    bool showOrHide;

    bool dontMove;
    int pJointConnectingId;


    std::list<int> idList;
    SlideDialogBox* dialog;

};

#endif // SLIDE_H
