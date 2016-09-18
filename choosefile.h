#ifndef CHOOSEFILE_H
#define CHOOSEFILE_H

#include <QCoreApplication>
#include <QPointF>
#include <QGraphicsEllipseItem>
#include <QTimeLine>
#include <QObject>
#include <QFile>

#include <QMovie>
#include <QVideoFrame>
#include <QImage>
#include <QPainter>
#include <vector>
#include <list>

#include <QTimer>
#include <QTime>

#include <QDebug>

#include <QFileDialog>
#include <QMessageBox>

#include "newbar.h"
#include "bar.h"
#include "slide.h"
#include "anchor.h"

#include "globalcoordinate.h"

#include "prismaticjoint.h"
#include "revolutionjoint.h"

#include "matlabfile.h"

#include "animationcontrollpanel.h"

#define PI 3.14159265

class ChooseFile: public QObject
{
    Q_OBJECT
public:
    ChooseFile(bool _checkMFile);
    ~ChooseFile();

    void findAllJoints();
    void chooseAFile();
    bool    checkRJointListSize();
    bool    checkRigidBodyIDListSize();
    void    addReal4Bars();
    bool    checkReal4BarsListSize();

    void setTotalItemList(QList<QGraphicsItem *> _totalItemsList);
    void setTotalRBList(QList<QGraphicsItem *> _totalRBList);
    void setRigidBodyIDList(QList<int> _rigidBodyIDList);
    void setTime(int _time);

public slots:
    void getTotalItemListFromDisplay(QList<QGraphicsItem *> _totalItemsList);
    void getTotalRBListFromDisplay(QList<QGraphicsItem *> _totalRBList);
    void getRigidBodyIDListFromDisplay(QList<int> _rigidBodyIDList);
    void getTimeFromDisplay(int _time);

signals:
    void removeItself();

    void passFileNameToAnimationControllpanel(QString _fileName);
    void passReal4BarsListToAnimationControllpanel(QList<NewBar *> _real4Bars);
    void passReal4BarsPosListToAnimationControllpanel(QList<QPointF> _real4BarsPos);
    void passReal4BarsAngleListToAnimationControllpanel(QList<double> _real4BarsAngle);
    void passRJointListToAnimationControllpanel(QList<RevolutionJoint *> _RJointList);
    void passTimeToAnimationControllpanel(int _time);

private:
    QList<QGraphicsItem *> totalItemsList;

    QString fileName;

    NewBar* ground;

    QList<QGraphicsItem *> totalRBList;
    QList<int> rigidBodyIDList;
    QList<NewBar *> real4Bars;
    QList<QPointF> real4BarsPos;
    QList<double> real4BarsAngle;

    QList<RevolutionJoint *> RJointList;
    QList<QPointF> RJointPosList;

    QTimer* timer;

    int time;
    bool checkMFile;

};

#endif // CHOOSEFILE_H
