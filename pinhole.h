#ifndef PINHOLE_H
#define PINHOLE_H

#include <typeinfo>

#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QPen>

#include <QList>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneHoverEvent>

#include <QDebug>


class PinHole:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    PinHole(QString _name, QGraphicsItem* parent = NULL);

    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

    QTimer* timer;

    bool isJointed;
    QString name;


public slots:
    void checkCollision();

signals:
   void isCollided(PinHole* itself, PinHole* collideItem);

private:
    double holeDiameter;
    double holeRadius;



};

#endif // PINHOLE_H
