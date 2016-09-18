#include "animationcontrollpanel.h"

AnimationControllPanel::AnimationControllPanel(QWidget *parent, int _time): QDialog(parent)
{
    this->setFixedSize(400,300);
    time = _time;
    qDebug() << "time in controllpanel" << time;

    controllWidget = new AnimationControllWidget(this,time);
    connect(this,SIGNAL(passFileNameToAnimationControllWidget(QString)),controllWidget,SLOT(getFileNamefromAnimationControllpanel(QString)));
    connect(this,SIGNAL(passReal4BarsListToAnimationControllWidget(QList<NewBar*>)),controllWidget,SLOT(getReal4BarsListfromAnimationControllpanel(QList<NewBar*>)));
    connect(this,SIGNAL(passReal4BarsPosListToAnimationControllWidget(QList<QPointF>)),controllWidget,SLOT(getReal4BarsPosListfromAnimationControllpanel(QList<QPointF>)));
    connect(this,SIGNAL(passReal4BarsAngleListToAnimationControllWidget(QList<double>)),controllWidget,SLOT(getReal4BarsAngleListfromAnimationControllpanel(QList<double>)));
    connect(this,SIGNAL(passRJointListToAnimationControllWidget(QList<RevolutionJoint*>)),controllWidget,SLOT(getRJointListfromAnimationControllpanel(QList<RevolutionJoint*>)));
    connect(this,SIGNAL(passTimeToAnimationControllWidget(int)),controllWidget,SLOT(getTimefromAnimationControllpanel(int)));

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->addWidget(controllWidget);

    this->setLayout(gridLayout);

//    if(this->close()){
//        delete controllWidget;
//        controllWidget = NULL;
    //    }
}

void AnimationControllPanel::closeEvent(QCloseEvent *event)
{
    controllWidget->stopAnimation();
}

void AnimationControllPanel::getFileNamefromChooseFile(QString _fileName)
{
    emit passFileNameToAnimationControllWidget(_fileName);
    qDebug() << _fileName;
    disconnect(this,SIGNAL(passFileNameToAnimationControllWidget(QString)),controllWidget,SLOT(getFileNamefromAnimationControllpanel(QString)));
}

void AnimationControllPanel::getReal4BarsListfromChooseFile(QList<NewBar *> _real4Bars)
{
    emit passReal4BarsListToAnimationControllWidget(_real4Bars);
    disconnect(this,SIGNAL(passReal4BarsListToAnimationControllWidget(QList<NewBar*>)),controllWidget,SLOT(getReal4BarsListfromAnimationControllpanel(QList<NewBar*>)));
}

void AnimationControllPanel::getReal4BarsPosListfromChooseFile(QList<QPointF> _real4BarsPos)
{
    emit passReal4BarsPosListToAnimationControllWidget(_real4BarsPos);
    disconnect(this,SIGNAL(passReal4BarsPosListToAnimationControllWidget(QList<QPointF>)),controllWidget,SLOT(getReal4BarsPosListfromAnimationControllpanel(QList<QPointF>)));
}

void AnimationControllPanel::getReal4BarsAngleListfromChooseFile(QList<double> _real4BarsAngle)
{
    emit passReal4BarsAngleListToAnimationControllWidget(_real4BarsAngle);
    disconnect(this,SIGNAL(passReal4BarsAngleListToAnimationControllWidget(QList<double>)),controllWidget,SLOT(getReal4BarsAngleListfromAnimationControllpanel(QList<double>)));
}

void AnimationControllPanel::getRJointListfromChooseFile(QList<RevolutionJoint *> _RJointList)
{
    emit passRJointListToAnimationControllWidget(_RJointList);
    disconnect(this,SIGNAL(passRJointListToAnimationControllWidget(QList<RevolutionJoint*>)),controllWidget,SLOT(getRJointListfromAnimationControllpanel(QList<RevolutionJoint*>)));
}

void AnimationControllPanel::getTimefromChooseFile(int _time)
{
    emit passTimeToAnimationControllWidget(_time);
    disconnect(this,SIGNAL(passTimeToAnimationControllWidget(int)),controllWidget,SLOT(getTimefromAnimationControllpanel(int)));
}
