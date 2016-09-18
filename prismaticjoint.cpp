#include "prismaticjoint.h"

PrismaticJoint::PrismaticJoint(Slide *_slide, QGraphicsItem *parent): QGraphicsRectItem(parent),
    slide(_slide), pJointConnectingItem(NULL),
    arrowXpos(-5.0), arrowYpos(25.0),arrowWidth(40.0), arrowHeight(1.5),
    color(Qt::red), transparent(QColor(0,0,0,0))
{
    qDebug() << "P Joint Created";

    drawArrow();
    setColor(color);

}

PrismaticJoint::~PrismaticJoint()
{
    qDebug() << "P Joint Deleted!";
}

void PrismaticJoint::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << QString("Slide %1 translate on %2").arg(slide->id).arg(pJointConnectingItem->id);
    qDebug() << pJointConnectingItem->getRectMassCenter();
    qDebug() << getLocalVectorToTranslationAxis();
    return;
}

void PrismaticJoint::drawArrow()
{
    this->setParentItem(slide);
    this->setRect(arrowXpos,arrowYpos,arrowWidth,arrowHeight);

    leftArrowShape.append(QPoint(0,2));
    leftArrowShape.append(QPoint(0,-2));
    leftArrowShape.append(QPoint(-5,0));

    rightArrowShape.append(QPoint(0,2));
    rightArrowShape.append(QPoint(0,-2));
    rightArrowShape.append(QPoint(5,0));

    leftArrow = new QGraphicsPolygonItem(this);
    leftArrow->setPolygon(leftArrowShape);
    leftArrow->setPos(arrowXpos, arrowYpos + arrowHeight/2);

    rightArrow = new QGraphicsPolygonItem(this);
    rightArrow->setPolygon(rightArrowShape);
    rightArrow->setPos(arrowWidth + arrowXpos, arrowYpos + arrowHeight/2);

    return;
}

void PrismaticJoint::setColor(QColor _color)
{
    this->setBrush(_color);
    this->setPen(transparent);

    leftArrow->setBrush(_color);
    leftArrow->setPen(transparent);

    rightArrow->setBrush(_color);
    rightArrow->setPen(transparent);

    return;
}

void PrismaticJoint::setPJointConnectingItem(NewBar *_pJointConnectingItem)
{
    pJointConnectingItem = _pJointConnectingItem;
    return;
}

QPointF PrismaticJoint::getLocalVectorToTranslationAxis()
{
    QPointF item2ToItem1 = slide->getRectMassCenter() - pJointConnectingItem->getRectMassCenter();
    QPointF localVector = inverseRotaionMatrix(item2ToItem1, pJointConnectingItem->getRectAngle());

    return localVector;

}

QPointF PrismaticJoint::inverseRotaionMatrix(QPointF _vect, double _theta)
{
    double x =  cos(_theta * PI/ 180.0)* _vect.x() + sin(_theta *PI/ 180.0)* _vect.y();
    double y = -sin(_theta * PI/ 180.0)* _vect.x() + cos(_theta *PI/ 180.0)* _vect.y();

    return QPointF(x,y);
}

void PrismaticJoint::changePJointConnectingItem(NewBar *_pJointConnectingItem)
{
//    pJointConnectingItem = _pJointConnectingItem;
    setPJointConnectingItem(_pJointConnectingItem);
//    qDebug() << _pJointConnectingItem->getRectMassCenter();
    return;
}
