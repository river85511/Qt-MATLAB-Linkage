#include "bar.h"

Bar::Bar(QGraphicsItem *parent): QGraphicsEllipseItem(parent)
{
    setRect(0,0,100,50);
    color = new QColor(160,160,160,50);
    setBrush(*color);

    this->setTransformOriginPoint(this->rect().width()/2, this->rect().height()/2);

    /*This is to show the origin point of the bar*/
    origin = new QGraphicsEllipseItem(this);
    origin->setRect(this->rect().center().x()-2.5,this->rect().center().y()-2.5,5,5);
    origin->setBrush(QColor(255,0,0,100));

    setAcceptHoverEvents(true);
}

void Bar::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    createDialogBox();
}

void Bar::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        offset = event->pos();
    }else if(event->button() == Qt::RightButton){
        qDebug() << "Function Not READY!";
    }
}

void Bar::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        QPointF p = mapToParent(event->pos() - offset);
        setPos(p);
    }
}

void Bar::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    color->setAlpha(150);
    setBrush(*color);
}

void Bar::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    color->setAlpha(50);
    setBrush(*color);
}

void Bar::createDialogBox()
{

        dialog = new BarDialogBox(this);
        connect(dialog,SIGNAL(angleChanged(float)),this,SLOT(changeAngle(float)));
        connect(dialog,SIGNAL(massCenterChanged(QPointF)),this,SLOT(changeMassCenter(QPointF)));
        connect(dialog,SIGNAL(lengthChanged(float)),this,SLOT(changeLength(float)));
        dialog->exec();
}

void Bar::changeAngle(float angle)
{
    this->setRotation(angle);
    disconnect(dialog,SIGNAL(angleChanged(float)),this,SLOT(changeAngle(float)));
}

void Bar::changeMassCenter(QPointF mc)
{

    QPointF halfWidthAndHeight = QPointF(this->rect().width()/2,this->rect().height()/2);
    this->setPos(mc - halfWidthAndHeight);

    disconnect(dialog,SIGNAL(massCenterChanged(QPointF)),this,SLOT(changeMassCenter(QPointF)));
}

void Bar::changeLength(float length)
{
    this->setRect(0,0,length,50);
    this->setTransformOriginPoint(this->rect().width()/2,this->rect().height()/2);
    origin->setRect(this->rect().width()/2 - origin->rect().width()/2, this->rect().height()/2 - origin->rect().height()/2, 5 ,5);
    disconnect(dialog,SIGNAL(lengthChanged(float)),this,SLOT(changeLength(float)));
}





