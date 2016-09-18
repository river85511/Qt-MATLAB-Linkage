#ifndef ANIMATIONCONTROLLPANEL_H
#define ANIMATIONCONTROLLPANEL_H

#include <QDialog>
#include <QWidget>

#include "animationcontrollwidget.h"

class AnimationControllPanel: public QDialog
{
    Q_OBJECT
public:
    AnimationControllPanel(QWidget* parent = NULL, int _time = 0);

    void closeEvent(QCloseEvent *event);

public slots:
    void getFileNamefromChooseFile(QString _fileName);
    void getReal4BarsListfromChooseFile(QList<NewBar *> _real4Bars);
    void getReal4BarsPosListfromChooseFile(QList<QPointF> _real4BarsPos);
    void getReal4BarsAngleListfromChooseFile(QList<double> _real4BarsAngle);
    void getRJointListfromChooseFile(QList<RevolutionJoint *> _RJointList);
    void getTimefromChooseFile(int _time);

signals:
    void passTimeToAnimationControllWidget(int _time);
    void passFileNameToAnimationControllWidget(QString _fileName);
    void passReal4BarsListToAnimationControllWidget(QList<NewBar *> _real4Bars);
    void passReal4BarsPosListToAnimationControllWidget(QList<QPointF> _real4BarsPos);
    void passReal4BarsAngleListToAnimationControllWidget(QList<double> _real4BarsAngle);
    void passRJointListToAnimationControllWidget(QList<RevolutionJoint *> _RJointList);

private:
    AnimationControllWidget* controllWidget;
    int time;
};

#endif // ANIMATIONCONTROLLPANEL_H
