#ifndef ANIMATIONCONTROLLWIDGET_H
#define ANIMATIONCONTROLLWIDGET_H

#include <QWidget>
#include <QGridLayout>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QSlider>

#include <QHBoxLayout>
#include <QObject>
#include <QDebug>
#include <QTimer>

#include <QSlider>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "anchor.h"
#include "newbar.h"
#include "slide.h"
#include "revolutionjoint.h"


class AnimationControllWidget: public QWidget
{
    Q_OBJECT
public:
    AnimationControllWidget(QWidget* parent = NULL,int time = 0);
    ~AnimationControllWidget();

    void initControllWidget();
    void initLayout();

    void setFileNameAndLoad(QString _fileName);
    void setReal4Bars(QList<NewBar *> _real4Bars);
    void setReal4BarsPos(QList<QPointF> _real4BarsPos);
    void setReal4BarsAngle(QList<double> _real4BarsAngle);
    void setRJointList(QList<RevolutionJoint *> _RJointList);
    void setSliderMaxValue(int _time);
    void loadFile(QString _fileName);

public slots:

    void runAnimation();
    void pauseAnimation();
    void stopAnimation();

    void speedUp();
    void speedNormal();
    void speedDown();

    void timerTick();
    void updatePos(int _sliderValue);

    void getFileNamefromAnimationControllpanel(QString _fileName);
    void getReal4BarsListfromAnimationControllpanel(QList<NewBar *> _real4Bars);
    void getReal4BarsPosListfromAnimationControllpanel(QList<QPointF> _real4BarsPos);
    void getReal4BarsAngleListfromAnimationControllpanel(QList<double> _real4BarsAngle);
    void getRJointListfromAnimationControllpanel(QList<RevolutionJoint *> _RJointList);
    void getTimefromAnimationControllpanel(int _time);

private:
    QGridLayout* gridLayout;

    QLabel* dataLabel;
    QLineEdit* dataLineEdit;
    QLineEdit* speedNow;

    QSlider* timeLineSlider;
    int sliderMaxValue;
    double interval;

    QPushButton* startButton;
    QPushButton* pauseButton;
    QPushButton* stopButton;

    QLabel* speedControllLabel;
    QPushButton* speedUpButton;
    QPushButton* speedNormalButton;
    QPushButton* speedDownButton;

    QTimer* timer;

    QString file;

    QString fileName;
    //double matrix[12][301];
    vector< vector<double> > datas;
    QList<NewBar *> real4Bars;
    QList<QPointF> real4BarsPos;
    QList<double> real4BarsAngle;
    QList<RevolutionJoint *> RJointList;

};

#endif // ANIMATIONCONTROLLWIDGET_H
