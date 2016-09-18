#include "slide.h"

Slide::Slide(bool _showHideCoordinate, int _id,QGraphicsItem *parent): QGraphicsRectItem(parent),
    rectWidth(30.0), rectHeight(20.0), rectAngle(0.0), massCenter(rectWidth/2, rectHeight/2),
    circleDiameter(10), circleRadius(circleDiameter/2.0),
    holeDiameter(5.0), holeRadius(holeDiameter/2),
    color(QColor(160,160,160,75)), alpha(125), alphaWhenHover(200),
    axisLength(20.0), id(_id),
    dontMove(false), pJointConnectingId(0),
    showOrHide(_showHideCoordinate)
{
    initializeSlide();

    this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable);

    setAcceptHoverEvents(true);

}

Slide::~Slide()
{
    qDebug() << "Slide Deleted!";
}

void Slide::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        createDialogBox();
        return;
    }
}

void Slide::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

        if((event->modifiers() & Qt::ShiftModifier) && (event->button() == Qt::LeftButton) )
        {
    //            qDebug() << "SHIFT PRESS";
                  return;
        }
        else if((event->button() == Qt::LeftButton) && (dontMove == false) )
        {
    //        qDebug() << "PRESS";
            offset = event->pos();
            midHole->timer->start(10);
            return;
        }
}

void Slide::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->modifiers() & Qt::ShiftModifier) && (dontMove == true) )
    {
//            qDebug() << "SHIFT MOVED";
                QPointF p = mapToParent(event->pos() - offset);
                this->setTransformOriginPoint(0,0);
                setPos(p);

                QPointF newMassCenter =  this->pos() + rotationMatrix(rectWidth/2, rectHeight/2, rectAngle);
                setMassCenter(newMassCenter);

                setDontMove(false);
                return;

    }
    else if( (event->buttons() & Qt::LeftButton) && (dontMove == false) )
    {

//        qDebug() << "MOVE";
            QPointF p = mapToParent(event->pos() - offset);
            this->setTransformOriginPoint(0,0);
            setPos(p);

            QPointF newMassCenter =  this->pos() + rotationMatrix(rectWidth/2, rectHeight/2, rectAngle);
            setMassCenter(newMassCenter);
            return;
    }
}

void Slide::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        midHole->timer->stop();
        return;
    }
}

void Slide::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    color.setAlpha(alphaWhenHover);
    this->setBrush(color);
    midCircle->setBrush(color);

    return;
}

void Slide::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    color.setAlpha(alpha);
    this->setBrush(color);
    midCircle->setBrush(color);

    return;
}

void Slide::createDialogBox()
{
    dialog = new SlideDialogBox(this,pJointConnectingId);
    connect(this,SIGNAL(passSlideIdToDialog(int)),dialog,SLOT(getSlideId(int)));
    emit passSlideIdToDialog(id);
    connect(this,SIGNAL(passIdListToDialog(std::list<int>)),dialog,SLOT(getIdListFromSlide(std::list<int>)));
    emit passIdListToDialog(idList);


    connect(dialog,SIGNAL(changeMassCenter(QPointF)),this,SLOT(changeRectMassCenter(QPointF)));
    connect(dialog,SIGNAL(changeRectAngle(double)),this,SLOT(changeRectAngle(double)));
    connect(dialog,SIGNAL(changePJointConnectingId(int)),this,SLOT(changePJointConnectingId(int)));
    connect(dialog,SIGNAL(changeRectColor(QColor)),this,SLOT(changeRectColor(QColor)));
    dialog->exec();

    return;
}

void Slide::initializeSlide()
{
    midCircle = new QGraphicsEllipseItem(this);

    midHole = new PinHole(QString("middle"),this);
    connect(midHole,SIGNAL(isCollided(PinHole*,PinHole*)),this,SLOT(collisionDetected(PinHole*,PinHole*)));

    /* initialize xyaxis & marks */
    xaxis = new QGraphicsLineItem(this);
    yaxis = new QGraphicsLineItem(this);
    xaxis->setVisible(showOrHide);
    yaxis->setVisible(showOrHide);

    xMark = new QGraphicsTextItem("ξ",this);
    QFont xMarkFont("ξ",4,QFont::Bold);
    xMark->setFont(xMarkFont);
    yMark = new QGraphicsTextItem("η",this);
    QFont yMarkFont("η",4,QFont::Bold);
    yMark->setFont(yMarkFont);
    xMark->setVisible(showOrHide);
    yMark->setVisible(showOrHide);

    idMark = new QGraphicsTextItem(QString::number(id),this);
    QFont idMarkFont(QString::number(id),6,QFont::Bold);
    idMark->setFont(idMarkFont);

    setRectWidth(rectWidth);
    setRectColor(color);

    return;
}

QPointF Slide::rotationMatrix(double _x, double _y, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _x - sin(_theta *PI/ 180.0)* _y;
    double y = sin(_theta * PI/ 180.0)* _x + cos(_theta *PI/ 180.0)* _y;

    return QPointF(x,y);
}

QPointF Slide::rotationMatrix(QPointF _vect, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _vect.x() - sin(_theta *PI/ 180.0)* _vect.y();
    double y = sin(_theta * PI/ 180.0)* _vect.x() + cos(_theta *PI/ 180.0)* _vect.y();

    return QPointF(x,y);
}

void Slide::setDontMove(bool trueOrFalse)
{
    dontMove = trueOrFalse;
    return;
}

void Slide::setMassCenter(QPointF _massCenter)
{
    massCenter = _massCenter;
    QPointF origin;

    if(this->transformOriginPoint() == QPointF(0,0))
        origin = massCenter - rotationMatrix(rectWidth/2, rectHeight/2, rectAngle);
    else
        origin = QPointF(massCenter.x() - this->rect().width()/2, _massCenter.y() - this->rect().height()/2);

    this->setPos(origin);
    return;
}

void Slide::setRectWidth(double _rectWidth)
{
    rectWidth = _rectWidth;
    this->setRect(0,0,rectWidth,rectHeight);
    this->setTransformOriginPoint(rectWidth/2, rectHeight/2);

    midCircle->setRect(rectWidth/2 - circleRadius, rectHeight/2 - circleRadius, circleDiameter, circleDiameter);

    midHole->setRect(rectWidth/2 - holeRadius, rectHeight/2 - holeRadius, holeDiameter, holeDiameter);

    /* set pos of xyaxis & marks */
    xaxis->setLine(rectWidth/2,rectHeight/2,rectWidth/2+axisLength,rectHeight/2);
    xaxis->setPen(QPen(Qt::green,1));
    yaxis->setLine(rectWidth/2,rectHeight/2,rectWidth/2,rectHeight/2-axisLength);
    yaxis->setPen(QPen(Qt::red,1));

    xMark->setPos(rectWidth/2+13,rectHeight/2-3);
    yMark->setPos(rectWidth/2-10.5,rectHeight/2-axisLength-8);

    idMark->setPos(rectWidth/2,rectHeight/2);

    return;
}

void Slide::setRectAngle(double _rectAngle)
{
    rectAngle = _rectAngle;
    this->setRotation(rectAngle);
    return;
}

void Slide::setRectColor(QColor _color)
{
    color = _color;
    color.setAlpha(alpha);
    this->setBrush(color);
    this->setPen(QColor(0,0,0,0));

    midCircle->setBrush(color);
    midCircle->setPen(QColor(0,0,0,0));

    midHole->setBrush(Qt::white);
    midHole->setPen(QColor(Qt::white));

    return;
}

QPointF Slide::getRectMassCenter()
{
    QPointF _massCenter = massCenter;
    _massCenter.setY( - _massCenter.y());
//    qDebug() << _massCenter;

    return _massCenter;
}

double Slide::getRectWidth()
{
    return rectWidth;
}

double Slide::getRectHeight()
{
    return rectHeight;
}

double Slide::getRectAngle()
{
    double _rectAngle = rectAngle;
    _rectAngle = - _rectAngle;
//    qDebug() << _rectAngle;

    return _rectAngle;
}

double Slide::getRectAngleRadians()
{
    double _rectAngle = rectAngle;
    _rectAngle = - _rectAngle;
    _rectAngle = _rectAngle * PI/ 180.0;

    return _rectAngle;
}

QPointF Slide::getAbsPinPos(PinHole *hole)
{
    QPointF vect = hole->rect().center() - this->rect().center();
    vect = this->rotationMatrix(vect,this->getRectAngle());

    return this->getRectMassCenter() + vect;
}

QPointF Slide::getQtRectMassCenter()
{
    return massCenter;
}

double Slide::getQtRectAngle()
{
    return rectAngle;
}

void Slide::getIdListFromDisplay(std::list<int> _idList)
{
    idList = _idList;
    emit passIdListToDialog(idList);
//    for(int i = 0; i < idList.size(); i++){
//        qDebug() << idList[i];
//    }
}


void Slide::changeRectAngle(double _rectAngle)
{
    //    qDebug() << "changeRectAngle";
        setRectAngle(_rectAngle);
        disconnect(dialog,SIGNAL(changeRectAngle(double)),this,SLOT(changeRectAngle(double)));
        return;
}

void Slide::changeRectMassCenter(QPointF _massCenter)
{
    //    qDebug() << "changeMassCenter";
        setMassCenter(_massCenter);
        disconnect(dialog,SIGNAL(changeMassCenter(QPointF)),this,SLOT(changeRectMassCenter(QPointF)));
        return;
}

void Slide::changeRectColor(QColor _color)
{
    //    qDebug() << "changeRectColor";
        setRectColor(_color);
        disconnect(dialog,SIGNAL(changeRectColor(QColor)),this,SLOT(changeRectColor(QColor)));
        return;
}

void Slide::changePJointConnectingId(int _pJointConnectingId)
{
//    qDebug() << _pJointConnectingId;
    pJointConnectingId = _pJointConnectingId;
    emit passConnectingIdToDisplay(_pJointConnectingId);
    return;
}

void Slide::collisionDetected(PinHole *hole, PinHole *collideItem)
{
    QPointF Bar1MassCenter;
    if( typeid(*(collideItem->parentItem())) == typeid(Anchor) ){
        Bar1MassCenter = static_cast<Anchor*>(collideItem->parentItem())->getQtMassCenter();
    }else{
        Bar1MassCenter = static_cast<NewBar*>(collideItem->parentItem())->getQtRectMassCenter();
    }

    double Bar1_angle = static_cast<Slide*>(collideItem->parentItem())->getQtRectAngle();
    QPointF Bar1_vect = collideItem->rect().center() - static_cast<Slide *>(collideItem->parentItem())->rect().center();
    Bar1_vect = rotationMatrix(Bar1_vect,Bar1_angle);

    double Bar2_angle = static_cast<Slide*>(hole->parentItem())->getQtRectAngle();
    QPointF Bar2_vect = hole->rect().center() - static_cast<Slide *>(hole->parentItem())->rect().center();
    Bar2_vect = rotationMatrix(Bar2_vect,Bar2_angle);

    QPointF newMassCenter = Bar1MassCenter + Bar1_vect - Bar2_vect;
    this->setMassCenter(newMassCenter);

    if( (hole->isJointed == false) && (collideItem->isJointed == false)){
        QPointF jointCenter = Bar1MassCenter + Bar1_vect;
        emit createRJoint(hole, collideItem, jointCenter);
    }

    setDontMove(true);
    return;
}

void Slide::showHideCoordinate(bool open)
{
    if(open){
        xaxis->setVisible(true);
        yaxis->setVisible(true);
        xMark->setVisible(true);
        yMark->setVisible(true);
    }else{
        xaxis->setVisible(false);
        yaxis->setVisible(false);
        xMark->setVisible(false);
        yMark->setVisible(false);
    }
}

