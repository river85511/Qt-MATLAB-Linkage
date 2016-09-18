#include "revolutionjoint.h"

RevolutionJoint::RevolutionJoint(PinHole *_pinA, PinHole *_pinB, QGraphicsItem *parent): QGraphicsEllipseItem(parent),
    jointDiameter(6.0), jointRadius(jointDiameter/2.0),
    innerCircleDiameter(jointDiameter/2), innerCircleRadius(jointRadius/2),
    pinA(_pinA), pinB(_pinB)
{
    qDebug() << "R Joint Created";
    initializeRevolutionJoint();

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(checkCollision()));
    timer->start(100);

    stopPinTimer();
    setPinIsJointed(true);
}



void RevolutionJoint::initializeRevolutionJoint()
{
    setRect(0,0,jointDiameter,jointDiameter);
    setBrush(QColor(160,160,160,250));

    innerCircle = new QGraphicsEllipseItem(this);
    innerCircle->setRect(jointRadius - innerCircleRadius,jointRadius - innerCircleRadius, innerCircleDiameter,innerCircleDiameter);
    innerCircle->setBrush(QColor(255,255,0,150));
}

void RevolutionJoint::stopPinTimer()
{
    pinA->timer->stop();
    pinB->timer->stop();
}

void RevolutionJoint::setPinIsJointed(bool trueOrFalse)
{
    pinA->isJointed = trueOrFalse;
    pinB->isJointed = trueOrFalse;
}

void RevolutionJoint::setBarDontMove(bool trueOrFalse)
{
    if(typeid(*(pinA->parentItem())) == typeid(NewBar)){
//        qDebug() << "NewBar A";
        static_cast<NewBar *>(pinA->parentItem())->setDontMove(trueOrFalse);
    }else if(typeid(*(pinA->parentItem())) == typeid(Slide)){
        qDebug() << "Slide A";
        static_cast<Slide *>(pinA->parentItem())->setDontMove(trueOrFalse);
    }else if(typeid(*(pinA->parentItem())) == typeid(Anchor)){
        static_cast<Anchor *>(pinA->parentItem())->setDontMove(trueOrFalse);
    }

    if(typeid(*(pinB->parentItem())) == typeid(NewBar)){
//        qDebug() << "NewBar B";
        static_cast<NewBar *>(pinB->parentItem())->setDontMove(trueOrFalse);
    }else if(typeid(*(pinB->parentItem())) == typeid(Slide)){
//        qDebug() << "Slide B";
        static_cast<Slide *>(pinB->parentItem())->setDontMove(trueOrFalse);
    }else if(typeid(*(pinB->parentItem())) == typeid(Anchor)){
        static_cast<Anchor *>(pinB->parentItem())->setDontMove(trueOrFalse);
    }

}


void RevolutionJoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        qDebug() << "Right CLICKED!";
    }
}

void RevolutionJoint::setCenter(QPointF _jointCenter)
{
    jointCenter =  _jointCenter;
    jointCenter.setY(- jointCenter.y());
//    qDebug() << jointCenter;

    QPointF origin = _jointCenter - QPointF(jointRadius,jointRadius);

    setPos(origin);
}

QPointF RevolutionJoint::getJointCenter()
{
    return jointCenter;
}

void RevolutionJoint::removeJoint()
{
    timer->stop();

    setPinIsJointed(false);
    setBarDontMove(false);

    pinA = nullptr;
    pinB = nullptr;

    qDebug() << "Joint Removed";
    this->scene()->removeItem(this);
    delete this;
}

void RevolutionJoint::checkCollision()
{
    QList<QGraphicsItem *> colliding_items = this->collidingItems();

//    qDebug() << colliding_items.size();
    bool jointdetect = false;
    int pinHole_num = 0;
    for(int i=0; i<colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(PinHole)){
            pinHole_num++;
            //qDebug() << pinHole_num;
            if(pinHole_num == 2){
                jointdetect = true;
                //qDebug() << pinHole_num;
                break;
            }
       }
    }

    if(!jointdetect)  // not Jointed
    {
        foreach(QGraphicsItem* item, colliding_items){
            if(typeid(*(item)) == typeid(PinHole)){
                    removeJoint();
                    return;
            }
        }
    }
}
