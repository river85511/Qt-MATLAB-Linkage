#include "newbar.h"

NewBar::NewBar(bool _showHideCoordinate, int _id,  QGraphicsItem *parent): QGraphicsRectItem(parent),
    rectWidth(100.0), rectHeight(10), rectAngle(0.0), massCenter(rectWidth/2, rectHeight/2),
    circleDiameter(rectHeight), circleRadius(circleDiameter/2.0),
    holeDiameter(5.0), holeRadius(holeDiameter/2),
    midCircleDiameter(2.0), midCircleRadius(midCircleDiameter/2.0),
    color(QColor(160,160,160,75)), alpha(125), alphaWhenHover(200),
    axisLength(20.0), id(_id),
    dontMove(false), showOrHide(_showHideCoordinate),
    isDrivingLink(false), angularVel(0), angularAcc(0)
{
    initializeBar();

    this->setFlag(GraphicsItemFlag::ItemIsSelectable);

    this->setAcceptHoverEvents(true);
}

NewBar::~NewBar()
{
    qDebug() << "NewBar Deleted!";
}

void NewBar::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        createDialogBox();
        return;
    }
}

void NewBar::mousePressEvent(QGraphicsSceneMouseEvent *event)
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
        leftHole->timer->start(10);
        rightHole->timer->start(10);
        return;
    }else if(event->button() == Qt::RightButton){
        qDebug() << "RIGHT CLICKED";

    }
}

void NewBar::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void NewBar::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        leftHole->timer->stop();
        rightHole->timer->stop();
        return;
    }
}

void NewBar::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    color.setAlpha(alphaWhenHover);
    this->setBrush(color);
    leftCircle->setBrush(color);
    rightCircle->setBrush(color);
    return;
}

void NewBar::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    color.setAlpha(alpha);
    this->setBrush(color);
    leftCircle->setBrush(color);
    rightCircle->setBrush(color);
    return;
}

void NewBar::setMassCenter(QPointF _massCenter)
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

void NewBar::setRectWidth(double _rectWidth)
{
    rectWidth = _rectWidth;
    this->setRect(0,0,rectWidth,rectHeight);
    this->setTransformOriginPoint(rectWidth/2, rectHeight/2);

    midCircle->setRect(rectWidth/2 - midCircleRadius, rectHeight/2 - midCircleRadius, midCircleDiameter,midCircleDiameter);

    leftCircle->setRect(-rectHeight/2, 0, circleDiameter, circleDiameter);
    rightCircle->setRect(rectWidth -rectHeight/2, 0, circleDiameter, circleDiameter);
    leftHole->setRect(-holeRadius, rectHeight/2- holeRadius, holeDiameter, holeDiameter);
    rightHole->setRect(rectWidth - holeRadius, rectHeight/2 - holeRadius, holeDiameter, holeDiameter);

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

void NewBar::setRectAngle(double _rectAngle)
{
    rectAngle = _rectAngle;
    this->setRotation(rectAngle);
    return;
}

void NewBar::setRectColor(QColor _color)
{
    color = _color;
    color.setAlpha(alpha);
    this->setBrush(color);
    this->setPen(QColor(0,0,0,0));

    midCircle->setBrush(QColor(255,0,0,100));
    midCircle->setPen(QColor(255,0,0,100));

    leftCircle->setBrush(color);
    leftCircle->setPen(QColor(0,0,0,0));
    rightCircle->setBrush(color);
    rightCircle->setPen(QColor(0,0,0,0));

    leftHole->setBrush(Qt::white);
    leftHole->setPen(QColor(Qt::white));
    rightHole->setBrush(Qt::white);
    rightHole->setPen(QColor(Qt::white));
    return;
}

void NewBar::setAngularVel(double _angularVel)
{
    angularVel = _angularVel;

    return;
}

void NewBar::setAngularAcc(double _angularAcc)
{
    angularAcc = _angularAcc;

    return;
}

double NewBar::getAngularVel()
{
    return angularVel;
}

double NewBar::getAngularAcc()
{
    return angularAcc;
}

void NewBar::createDialogBox()
{
    dialog = new NewBarDialogBox(isDrivingLink, angularVel, angularAcc, this);
    connect(dialog,SIGNAL(changeMassCenter(QPointF)),this,SLOT(changeRectMassCenter(QPointF)));
    connect(dialog,SIGNAL(changeRectWidth(double)),this,SLOT(changeRectWidth(double)));
    connect(dialog,SIGNAL(changeRectAngle(double)),this,SLOT(changeRectAngle(double)));
    connect(dialog,SIGNAL(changeRectColor(QColor)),this,SLOT(changeRectColor(QColor)));
    connect(dialog,SIGNAL(setAsDrivingLink(bool)),this,SLOT(setAsDrivingLink(bool)));
    connect(dialog,SIGNAL(changeAngularVel(double)),this,SLOT(changeAngularVel(double)));
    connect(dialog,SIGNAL(changeAngularAcc(double)),this,SLOT(changeAngularAcc(double)));
    dialog->exec();

    return;
}

void NewBar::initializeBar()
{
    midCircle = new QGraphicsEllipseItem(this);

    leftCircle = new QGraphicsEllipseItem(this);
    leftCircle->setStartAngle(90 * 16);
    leftCircle->setSpanAngle(180* 16);

    rightCircle = new QGraphicsEllipseItem(this);
    rightCircle->setStartAngle(-90 * 16);
    rightCircle->setSpanAngle(180* 16);

    leftHole = new PinHole(QString("left"),this);
    connect(leftHole,SIGNAL(isCollided(PinHole*,PinHole*)),this,SLOT(collisionDetected(PinHole*,PinHole*)));
    rightHole = new PinHole(QString("right"),this);
    connect(rightHole,SIGNAL(isCollided(PinHole*,PinHole*)),this,SLOT(collisionDetected(PinHole*,PinHole*)));

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

QPointF NewBar::rotationMatrix(double _x, double _y, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _x - sin(_theta *PI/ 180.0)* _y;
    double y = sin(_theta * PI/ 180.0)* _x + cos(_theta *PI/ 180.0)* _y;

    return QPointF(x,y);
}

QPointF NewBar::rotationMatrix(QPointF _vect, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _vect.x() - sin(_theta *PI/ 180.0)* _vect.y();
    double y = sin(_theta * PI/ 180.0)* _vect.x() + cos(_theta *PI/ 180.0)* _vect.y();

    return QPointF(x,y);
}

void NewBar::setDontMove(bool trueOrFalse)
{
    dontMove = trueOrFalse;
    return;
}

QPointF NewBar::getRectMassCenter()
{
    QPointF _massCenter = massCenter;
    _massCenter.setY( - _massCenter.y());
//    qDebug() << _massCenter;

    return _massCenter;
}

double NewBar::getRectWidth()
{
    return rectWidth;
}

double NewBar::getRectHeight()
{
    return rectHeight;
}

double NewBar::getRectAngle()
{
    double _rectAngle = rectAngle;
    _rectAngle = - _rectAngle;
//    qDebug() << _rectAngle;

    return _rectAngle;
}

double NewBar::getRectAngleRadians()
{
    double _rectAngle = rectAngle;
    _rectAngle = - _rectAngle;
    _rectAngle = _rectAngle * PI/ 180.0;

    return _rectAngle;
}

QPointF NewBar::getAbsPinPos(PinHole *hole)
{
    QPointF vect = hole->rect().center() - this->rect().center();
    vect = this->rotationMatrix(vect,this->getRectAngle());

    return this->getRectMassCenter() + vect;
}

QPointF NewBar::getQtRectMassCenter()
{
    return massCenter;
}

double NewBar::getQtRectAngle()
{
    return rectAngle;
}

void NewBar::changeRectWidth(double _rectWidth)
{
//    qDebug() << "changeRectWidth";
    setRectWidth(_rectWidth);
    disconnect(dialog,SIGNAL(changeRectWidth(double)),this,SLOT(changeRectWidth(double)));
    return;
}

void NewBar::changeRectAngle(double _rectAngle)
{
//    qDebug() << "changeRectAngle";
    setRectAngle(_rectAngle);
    disconnect(dialog,SIGNAL(changeRectAngle(double)),this,SLOT(changeRectAngle(double)));
    return;
}

void NewBar::changeRectMassCenter(QPointF _massCenter)
{
//    qDebug() << "changeMassCenter";
    setMassCenter(_massCenter);
    disconnect(dialog,SIGNAL(changeMassCenter(QPointF)),this,SLOT(changeRectMassCenter(QPointF)));
    return;
}

void NewBar::changeRectColor(QColor _color)
{
//    qDebug() << "changeRectColor";
    setRectColor(_color);
    disconnect(dialog,SIGNAL(changeRectColor(QColor)),this,SLOT(changeRectColor(QColor)));
    return;
}

void NewBar::changeAngularVel(double _angularVel)
{
    setAngularVel(_angularVel);
//    qDebug() << angularVel;
    disconnect(dialog,SIGNAL(changeAngularVel(double)),this,SLOT(changeAngularVel(double)));

    return;
}

void NewBar::changeAngularAcc(double _angularAcc)
{
    setAngularAcc(_angularAcc);
//    qDebug() << angularAcc;
    disconnect(dialog,SIGNAL(changeAngularAcc(double)),this,SLOT(changeAngularAcc(double)));

    return;
}

void NewBar::collisionDetected(PinHole *hole, PinHole *collideItem)
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

    double Bar2_angle = static_cast<NewBar*>(hole->parentItem())->getQtRectAngle();
    QPointF Bar2_vect = hole->rect().center() - static_cast<NewBar *>(hole->parentItem())->rect().center();
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

void NewBar::showHideCoordinate(bool open)
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

void NewBar::setAsDrivingLink(bool _isDrivingLink)
{
    isDrivingLink = _isDrivingLink;
    if(isDrivingLink){
        emit setDrivingLink(isDrivingLink, id);
    }
    else{
       emit setDrivingLink(isDrivingLink, id);
    }
}





