#ifndef ANIMATION_H
#define ANIMATION_H

#include <QGraphicsSceneMouseEvent>
#include <QCoreApplication>
#include <QPointF>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QTimeLine>
#include <QWheelEvent>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QScrollBar>
#include <QFile>

#include <QMovie>
#include <QVideoFrame>
#include <QImage>
#include <QPainter>
#include <vector>
#include <list>

#include <QTimer>
#include <QTime>

#include <QPixmap>
#include <QWidget>
#include <QDebug>

#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <fstream>
using namespace std;

#include "newbar.h"
#include "bar.h"
#include "slide.h"
#include "anchor.h"

#include "globalcoordinate.h"

#include "prismaticjoint.h"
#include "revolutionjoint.h"

#include "matlabfile.h"

#define PI 3.14159265

class Animation: public QObject
{
    Q_OBJECT
public:
    Animation();
};

#endif // ANIMATION_H
