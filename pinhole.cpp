#include "pinhole.h"

PinHole::PinHole(QString _name, QGraphicsItem *parent): QGraphicsEllipseItem(parent),
    isJointed(false), name(_name),
    holeDiameter(5.0), holeRadius(holeDiameter/2.0)
{
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(checkCollision()));
//    timer->start(100);

    this->setAcceptHoverEvents(true);
}

void PinHole::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
    this->setBrush(QColor(Qt::black));
}

void PinHole::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
    this->setBrush(QColor(Qt::white));
}

void PinHole::checkCollision()
{

    QList<QGraphicsItem *> colliding_items = this->collidingItems();

//    qDebug() << colliding_items.size();
    if(colliding_items.size() <= 3)  // not Jointed
    {
        isJointed = false;
    }
    else
    {
        foreach(QGraphicsItem* item, colliding_items){
            if(typeid(*(item)) == typeid(PinHole)){
                    emit isCollided(this, static_cast<PinHole *>(item));
                    return;
            }
        }
    }

}

