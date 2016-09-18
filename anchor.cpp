#include "anchor.h"

Anchor::Anchor(QGraphicsItem *parent): QGraphicsEllipseItem(parent),
    anchorDiameter(10.0), anchorRadius(anchorDiameter/2), anchorAngle(0.0), massCenter(anchorRadius, anchorRadius),
    holeDiameter(5.0), holeRadius(holeDiameter/2),
    circleColor(QColor(255,215,0,150)), triangleColor(QColor(153,0,0,150)), transparent(QColor(0,0,0,0)), alpha(150), alphaWhenHover(200),
    slashLineWidth(1.0), slashLineColor(QColor(0,0,0,200)),underLineWidth(1.0), underLineColor(QColor(0,0,0,255)),
    dontMove(false)
{
    initializeAnchor();

    this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable);

    setAcceptHoverEvents(true);
}

Anchor::~Anchor()
{
    qDebug() << "Anchor Deleted!";
}

void Anchor::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        createDialogBox();
    }
}

void Anchor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->modifiers() & Qt::ShiftModifier) && (event->button() == Qt::LeftButton) )
    {
//            qDebug() << "SHIFT PRESS";
    }
    else if((event->button() == Qt::LeftButton) && (dontMove == false) )
    {
        //qDebug() << "PRESS";
        offset = event->pos();
        pin->timer->start(10);
    }
}

void Anchor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->modifiers() & Qt::ShiftModifier) && (dontMove == true) )
    {
//            qDebug() << "SHIFT MOVED";
                QPointF p = mapToParent(event->pos() - offset);
                this->setTransformOriginPoint(0,0);
                setPos(p);
                QPointF newMassCenter =  this->pos() + rotationMatrix(anchorRadius, anchorRadius, anchorAngle);
                setAnchorMassCenter(newMassCenter);

                setDontMove(false);

    }
    else if( (event->buttons() & Qt::LeftButton) && (dontMove == false) )
    {

//        qDebug() << "MOVE";
            QPointF p = mapToParent(event->pos() - offset);
            this->setTransformOriginPoint(0,0);
            setPos(p);

            QPointF newMassCenter =  this->pos() + rotationMatrix(anchorRadius, anchorRadius, anchorAngle);
            setAnchorMassCenter(newMassCenter);

    }

}

void Anchor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        pin->timer->stop();
    }
}

void Anchor::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    circleColor.setAlpha(alphaWhenHover);
    setBrush(circleColor);

    triangleColor.setAlpha(alphaWhenHover);
    this->triangle->setBrush(triangleColor);
}

void Anchor::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    circleColor.setAlpha(alpha);
    setBrush(circleColor);

    triangleColor.setAlpha(alpha);
    this->triangle->setBrush(triangleColor);
}

void Anchor::setAnchorMassCenter(QPointF _massCenter)
{
    massCenter = _massCenter;
    QPointF origin;

    if(this->transformOriginPoint() == QPointF(0,0)){
        origin = massCenter - rotationMatrix(anchorRadius, anchorRadius, anchorAngle);
    }else{
        origin = QPointF(massCenter.x() - this->rect().width()/2, massCenter.y() - this->rect().height()/2);
    }
    this->setPos(origin);
}

void Anchor::setAnchorAngle(double _anchorAngle)
{
    anchorAngle = _anchorAngle;
    this->setRotation(anchorAngle);
}

void Anchor::createDialogBox()
{
//    qDebug() << "HI";

        dialog = new AnchorDialogBox(this);
        connect(dialog,SIGNAL(changeRectAngle(double)),this,SLOT(changeAnchorAngle(double)));
        connect(dialog,SIGNAL(changeMassCenter(QPointF)),this,SLOT(changeAnchorMassCenter(QPointF)));
        dialog->exec();
}

void Anchor::initializeAnchor()
{
    this->setRect(0,0,anchorDiameter,anchorDiameter);
    this->setTransformOriginPoint(anchorRadius, anchorRadius);
    this->setBrush(circleColor);
    this->setPen(transparent);

    tri << QPoint(5,5);
    tri << QPoint(0,15);
    tri << QPoint(10,15);

    triangle = new QGraphicsPolygonItem(tri,this);
    triangle->setBrush(triangleColor);
    triangle->setPen(transparent);

    pin = new PinHole(QString("middle"),this);
    pin->setRect(anchorRadius-holeRadius,anchorRadius-holeRadius,holeDiameter,holeDiameter);
    connect(pin,SIGNAL(isCollided(PinHole*,PinHole*)),this,SLOT(collisionDetected(PinHole*,PinHole*)));
    pin->setPen(transparent);
    pin->setBrush(Qt::white);

    drawGoundLine();
}

void Anchor::drawGoundLine()
{
    QGraphicsLineItem* underLine = new QGraphicsLineItem(this);
    underLine->setLine(-0.25,14.5,10.25,14.5);
    underLine->setPen(QPen(slashLineColor,underLineWidth));

    for(int i = 0; i<6; i++){
        QGraphicsLineItem* slashLine = new QGraphicsLineItem(this);
        slashLine->setLine(i*2, 15, 1+i*2, 17);
        slashLine->setPen(QPen(slashLineColor,slashLineWidth));
    }

}

QPointF Anchor::rotationMatrix(double _x, double _y, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _x - sin(_theta *PI/ 180.0)* _y;
    double y = sin(_theta * PI/ 180.0)* _x + cos(_theta *PI/ 180.0)* _y;

    return QPointF(x,y);
}

QPointF Anchor::rotationMatrix(QPointF _vect, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _vect.x() - sin(_theta *PI/ 180.0)* _vect.y();
    double y = sin(_theta * PI/ 180.0)* _vect.x() + cos(_theta *PI/ 180.0)* _vect.y();

    return QPointF(x,y);
}

void Anchor::setDontMove(bool trueOrFalse)
{
    dontMove = trueOrFalse;
}

QPointF Anchor::getAnchorMassCenter()
{
    QPointF _massCenter = massCenter;
    _massCenter.setY( - _massCenter.y());
//    qDebug() << _massCenter;

    return _massCenter;
}

double Anchor::getAnchorRadius()
{
    return anchorRadius;
}

double Anchor::getAnchorDiameter()
{
    return anchorDiameter;
}

double Anchor::getAnchorAngle()
{
    double _anchorAngle = anchorAngle;
    _anchorAngle = - _anchorAngle;
//    qDebug() << _rectAngle;

    return _anchorAngle;
}

QPointF Anchor::getAbsPinPos(PinHole *hole)
{
    QPointF vect = hole->rect().center() - this->rect().center();
    vect = this->rotationMatrix(vect,this->getAnchorAngle());

    return this->getAnchorMassCenter() + vect;
}

QPointF Anchor::getQtMassCenter()
{
    return massCenter;
}

double Anchor::getQtAnchorAngle()
{
    return anchorAngle;
}

void Anchor::changeAnchorAngle(double _anchorAngle)
{
    setAnchorAngle(_anchorAngle);
    disconnect(dialog,SIGNAL(changeRectAngle(double)),this,SLOT(changeAnchorAngle(double)));
}

void Anchor::changeAnchorMassCenter(QPointF _massCenter)
{
//    qDebug() << _massCenter;
    setAnchorMassCenter(_massCenter);
    disconnect(dialog,SIGNAL(changeMassCenter(QPointF)),this,SLOT(changeAnchorMassCenter(QPointF)));
}

void Anchor::collisionDetected(PinHole *hole, PinHole *collideItem)
{
    QPointF Bar1MassCenter;
    if( typeid(*(collideItem->parentItem())) == typeid(Anchor) ){
        Bar1MassCenter = static_cast<Anchor*>(collideItem->parentItem())->getQtMassCenter();
    }else{
        Bar1MassCenter = static_cast<NewBar*>(collideItem->parentItem())->getQtRectMassCenter();
    }

    double Bar1_angle = static_cast<NewBar*>(collideItem->parentItem())->getQtRectAngle();
    QPointF Bar1_vect = collideItem->rect().center() - static_cast<NewBar *>(collideItem->parentItem())->rect().center();
    Bar1_vect = rotationMatrix(Bar1_vect,Bar1_angle);

    double Bar2_angle = static_cast<Anchor*>(hole->parentItem())->getQtAnchorAngle();
    QPointF Bar2_vect = hole->rect().center() - static_cast<Anchor *>(hole->parentItem())->rect().center();
    Bar2_vect = rotationMatrix(Bar2_vect,Bar2_angle);

    QPointF newMassCenter = Bar1MassCenter + Bar1_vect - Bar2_vect;
    this->setAnchorMassCenter(newMassCenter);

    if( (hole->isJointed == false) && (collideItem->isJointed == false)){
        QPointF jointCenter = Bar1MassCenter + Bar1_vect;
        emit createRJoint(hole, collideItem, jointCenter);
    }

    setDontMove(true);
    return;

}
