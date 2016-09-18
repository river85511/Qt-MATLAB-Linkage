#ifndef DISPLAY_H
#define DISPLAY_H

#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>

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
#include <QKeyEvent>

#include <QMovie>
#include <QVideoFrame>
#include <QImage>
#include <QPainter>
#include <vector>
#include <list>

#include <QPixmap>
#include <QWidget>
#include <QDebug>

#include "newbar.h"
#include "slide.h"
#include "anchor.h"

#include "globalcoordinate.h"

#include "prismaticjoint.h"
#include "revolutionjoint.h"

#include "matlabfile.h"
#include "choosefile.h"

#include "plotdialog.h"
#include "systemparamdialog.h"

#define PI 3.14159265

class Display: public QGraphicsView
{
    Q_OBJECT

public:
    Display(QWidget *parent = NULL);
    ~Display();

    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void initializeDisplay();
    void createGlobalCoordinates();

    template <typename T>
    void getListOf(QList<T*> &listOut);

    QGraphicsScene* scene;

public slots:
    void genSystemParamDialog();
    void setLengthUnit(QString _currentLengthUnit);

    void genAnchor();
    void genBar();
    void genSlide();

    void genRJoint(PinHole* _pinA, PinHole* _pinB, QPointF _jointCenter);
    void genPJoint(Slide* _slide);


    //show coordinates
    void showCoordinate();

//    //setDrivingLink
    void setDrivingLink(bool isDrivingLink, int id);

    void genMatlabFile();

    void findItemWithId(int _pJointConnectingId);
    void screenCapture();

    void showSelectionChanged(QGraphicsItem* item);

    void removeSelectedItem(QGraphicsItem* _selectedItem);

    void chooseFile();
    void getID(int _id);

signals:
    void passIdListToSlide(std::list<int> _idList);
    void changePJointConnectingItem(NewBar* _pJointConnectingItem);
    void passTotalItemListToMatlabFile(QList<QGraphicsItem *> _totalItemsList);
    void passTimeToMatlabFile(int time);

    void passTotalItemListToChooseFile(QList<QGraphicsItem *> _totalItemsList);
    void passTotalRBListToChooseFile(QList<QGraphicsItem*> _totalRBList);
    void passRigidBodyIDListToChooseFile(QList<int> _rigidBodyIDList);
    void passTimeToChooseFile(int _time);

    //send to rigid bodies to show or hide coordinates
    void showHideCoordinate(bool open);

    void selectionChanged(QGraphicsItem* item);

private:

    QPointF offset;
    QPointF p;

    systemParamDialog* dialog;
    QString currentLengthUnit;

    GlobalCoordinate* globalCoordinates;
    NewBar* ground;

    int rigidBodyNum;
    std::list<int> idList;

    //save id of drivingLink
    int drivingLinkID;

    //decide show or hide coordinates
    bool coordinateSwitch;

    MatlabFile* matlabFile;
    ChooseFile* chooseFile1;

    float _panStartX;
    float _panStartY;

    QList<QGraphicsItem *> totalRBList;
    QList<int> rigidBodyIDList;

    QList<RevolutionJoint *> RJointList;
    QList<QPointF> RJointPosList;

    int time;
    bool checkMFile;

};

#endif // DISPLAY_H
