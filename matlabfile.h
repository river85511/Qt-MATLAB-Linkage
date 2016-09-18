#ifndef MATLABFILE_H
#define MATLABFILE_H

#include <QObject>
#include <QGraphicsItem>

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <QList>
#include <vector>
#include <list>
#include <algorithm>

#include "newbar.h"
#include "slide.h"
#include "prismaticjoint.h"
#include "revolutionjoint.h"

class MatlabFile: public QObject
{
    Q_OBJECT
public:
    MatlabFile(QString _lengthUnit = QString("m"));
    ~MatlabFile();

    void findAllJoints();

    bool checkIsAlreadyCounted(int _id);
    void findAllRigidBody();
    void addToBarList(NewBar *bar);
    void addToSlideList(Slide *slide);
    void sortIdList();


    void genFile();
    void    genMainFile();
    void        genMainFileOpening(QTextStream &out);
    void            genInitialCondition(QTextStream &out);
    void            genMainFileCalculationBeginning(QTextStream &out);
    void                genMainFileDisplacement(QTextStream &out);
    void                genMainFileVelocity(QTextStream &out);
    void                genMainFileAcceleration(QTextStream &out);
    void            genMainFileCalculationEnding(QTextStream &out);
    void            genDisplacementPlot(QTextStream &out);
    void            genVelocityPlot(QTextStream &out);
    void            genAccelerationPlot(QTextStream &out);
    void            genDisplacementArray(QTextStream &out);
    void        genMainFileEnding(QTextStream &out);

    void    genFunctionFile();
    void        genConstrEqnOpening(QTextStream &out);
    void            genConstrEqn(QTextStream &out);
    void            genDrivingEqn(QTextStream &out);
    void        genFConstrEqnEnding(QTextStream &out);

    void        genJaco4barOpening(QTextStream &out);
    void            genJaco4bar(QTextStream &out);
    void            genJaco4barDriving(QTextStream &out);
    void        genJaco4barEnding(QTextStream &out);

    void        genGamma4barOpening(QTextStream &out);
    void            genGamma4bar(QTextStream &out);
    void            genGamma4barDriving(QTextStream &out);
    void        genGamma4barEnding(QTextStream &out);


    QString getJaco4BarStr();
    QString getGamma4BarStr();

    void setTotalItemList(QList<QGraphicsItem *> _totalItemsList);
    void setTime(int _time);
public slots:
    void getTotalItemListFromDisplay(QList<QGraphicsItem *> _totalItemsList);
    void getTimeFromDisplay(int _time);

signals:
    void rigidBodyID(int _id);

private:

    QList<QGraphicsItem *> totalItemsList;
    QList<int> idList;
    QList<NewBar *> totalBarList;
    QList<Slide *> totalSlideList;

    QList<RevolutionJoint *> RJointList;
    QList<PrismaticJoint *> PJointList;

    double timeInterval;
    int totalTime;

    QString lengthUnit;
};

#endif // MATLABFILE_H
