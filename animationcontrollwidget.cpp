#include "animationcontrollwidget.h"

AnimationControllWidget::AnimationControllWidget(QWidget *parent, int time): QWidget(parent),
    sliderMaxValue(time*100+1), interval(10)
{
    this->show();

    initControllWidget();
    initLayout();
}

AnimationControllWidget::~AnimationControllWidget()
{
    stopAnimation();
    qDebug() << "animation panel deleted";
}

void AnimationControllWidget::initControllWidget()
{
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTick()));

    dataLabel = new QLabel(tr("&Data File:"));
    dataLineEdit = new QLineEdit(fileName);
    dataLineEdit->setReadOnly(true);
    dataLabel->setBuddy(dataLineEdit);

    timeLineSlider = new QSlider(Qt::Orientation::Horizontal);
    timeLineSlider->setFixedHeight(50);
    timeLineSlider->setMaximum(sliderMaxValue);
    connect(timeLineSlider,SIGNAL(valueChanged(int)),this,SLOT(updatePos(int)));

    startButton = new QPushButton(tr("START"));
    startButton->setFixedSize(75,75);
    connect(startButton,SIGNAL(pressed()),this,SLOT(runAnimation()));
    pauseButton = new QPushButton(tr("PAUSE"));
    pauseButton->setFixedSize(75,75);
    connect(pauseButton,SIGNAL(pressed()),this,SLOT(pauseAnimation()));
    stopButton = new QPushButton(tr("STOP"));
    stopButton->setFixedSize(75,75);
    connect(stopButton,SIGNAL(pressed()),this,SLOT(stopAnimation()));

    speedControllLabel = new QLabel(tr("Speed Controll"));
    speedNow = new QLineEdit(QString("      X 1"));
    speedNow->setReadOnly(true);
    speedControllLabel->setBuddy(speedNow);

    speedUpButton = new QPushButton(tr("X 2.0"));
    speedUpButton->setFixedSize(45,45);
    connect(speedUpButton,SIGNAL(pressed()),this,SLOT(speedUp()));
    speedNormalButton = new QPushButton(tr("X 1"));
    speedNormalButton->setFixedSize(45,45);
    connect(speedNormalButton,SIGNAL(pressed()),this,SLOT(speedNormal()));
    speedDownButton = new QPushButton(tr("X 0.5"));
    speedDownButton->setFixedSize(45,45);
    connect(speedDownButton,SIGNAL(pressed()),this,SLOT(speedDown()));
}

void AnimationControllWidget::initLayout()
{
    QHBoxLayout* hBoxLayout1 = new QHBoxLayout();
    hBoxLayout1->addWidget(dataLabel);
    hBoxLayout1->addWidget(dataLineEdit);

    QHBoxLayout* hBoxLayout2 = new QHBoxLayout();
    hBoxLayout2->addWidget(startButton);
    hBoxLayout2->addWidget(pauseButton);
    hBoxLayout2->addWidget(stopButton);

    QHBoxLayout* hBoxLayout3 = new QHBoxLayout();
    hBoxLayout3->addWidget(speedControllLabel);
    hBoxLayout3->addWidget(speedNow);
    hBoxLayout3->addWidget(speedDownButton);
    hBoxLayout3->addWidget(speedNormalButton);
    hBoxLayout3->addWidget(speedUpButton);

    gridLayout = new QGridLayout();
    gridLayout->addLayout(hBoxLayout1,0,0);
    gridLayout->addWidget(timeLineSlider,1,0);
    gridLayout->addLayout(hBoxLayout2,2,0);
    gridLayout->addLayout(hBoxLayout3,3,0);
    this->setLayout(gridLayout);
}

void AnimationControllWidget::setFileNameAndLoad(QString _fileName)
{
    fileName = _fileName;

    dataLineEdit->setText(fileName);

    loadFile(fileName);

    return;
}

void AnimationControllWidget::setReal4Bars(QList<NewBar *> _real4Bars)
{
    real4Bars = _real4Bars;
    return;
}

void AnimationControllWidget::setReal4BarsPos(QList<QPointF> _real4BarsPos)
{
    real4BarsPos = _real4BarsPos;
    return;
}

void AnimationControllWidget::setReal4BarsAngle(QList<double> _real4BarsAngle)
{
    real4BarsAngle = _real4BarsAngle;
    return;
}

void AnimationControllWidget::setRJointList(QList<RevolutionJoint *> _RJointList)
{
    RJointList = _RJointList;
    return;
}

void AnimationControllWidget::setSliderMaxValue(int _time)
{
    sliderMaxValue = _time*100 + 1;
    qDebug() << "in setSlide" << sliderMaxValue;
    return;
}

void AnimationControllWidget::loadFile(QString _fileName)
{
    ifstream input(_fileName.toStdString(),ios::in);
    if(!input) {
        cout << "no file\n";
        return;
    }

    double data;
    qDebug() << "in loadfile" <<sliderMaxValue;

    for(int i=0;i<12;i++){
        vector<double> row;
        for(int j=0;j<sliderMaxValue;j++){
            input >> data;
            row.push_back(data);
        }
        datas.push_back(row);
    }
    input.close();

    return;
}



void AnimationControllWidget::timerTick()
{
    timeLineSlider->setValue(timeLineSlider->value()+1);

    if(timeLineSlider->value() == sliderMaxValue){
        timer->stop();
    }
}

void AnimationControllWidget::updatePos(int _sliderValue)
{
    if(_sliderValue == sliderMaxValue){
        _sliderValue-=1;
    }

    foreach(RevolutionJoint* rJoint, RJointList){
        rJoint->timer->stop();
    }

    real4Bars[1]->setRectAngle(-datas[5][_sliderValue]/3.1416*180);
    real4Bars[1]->setMassCenter(QPointF(datas[3][_sliderValue],-datas[4][_sliderValue]));

    real4Bars[2]->setRectAngle(-datas[8][_sliderValue]/3.1416*180);
    real4Bars[2]->setMassCenter(QPointF(datas[6][_sliderValue],-datas[7][_sliderValue]));

    real4Bars[3]->setRectAngle(-datas[11][_sliderValue]/3.1416*180);
    real4Bars[3]->setMassCenter(QPointF(datas[9][_sliderValue],-datas[10][_sliderValue]));

    foreach(RevolutionJoint* rJoint, RJointList){

        if(typeid(*rJoint->pinA->parentItem()) == typeid(NewBar)){
            QPointF jointPos = static_cast<NewBar *>(rJoint->pinA->parentItem())->getAbsPinPos(rJoint->pinA);

            jointPos.setX(jointPos.x()-rJoint->jointRadius);
            jointPos.setY(-jointPos.y()-rJoint->jointRadius);

            rJoint->setPos(jointPos);

        }else if(typeid(*rJoint->pinA->parentItem()) == typeid(Slide)){
            QPointF jointPos = static_cast<Slide *>(rJoint->pinA->parentItem())->getAbsPinPos(rJoint->pinA);

            jointPos.setX(jointPos.x()-rJoint->jointRadius);
            jointPos.setY(-jointPos.y()-rJoint->jointRadius);

            rJoint->setPos(jointPos);

        }else if(typeid(*rJoint->pinA->parentItem()) == typeid(Anchor)){
            QPointF jointPos = static_cast<Anchor *>(rJoint->pinA->parentItem())->getAbsPinPos(rJoint->pinA);

            jointPos.setX(jointPos.x()-rJoint->jointRadius);
            jointPos.setY(-jointPos.y()-rJoint->jointRadius);

            rJoint->setPos(jointPos);
        }
    }
}

void AnimationControllWidget::getFileNamefromAnimationControllpanel(QString _fileName)
{
    setFileNameAndLoad(_fileName);
}

void AnimationControllWidget::getReal4BarsListfromAnimationControllpanel(QList<NewBar *> _real4Bars)
{
    setReal4Bars(_real4Bars);
}

void AnimationControllWidget::getReal4BarsPosListfromAnimationControllpanel(QList<QPointF> _real4BarsPos)
{
    setReal4BarsPos(_real4BarsPos);
}

void AnimationControllWidget::getReal4BarsAngleListfromAnimationControllpanel(QList<double> _real4BarsAngle)
{
    setReal4BarsAngle(_real4BarsAngle);
}

void AnimationControllWidget::getRJointListfromAnimationControllpanel(QList<RevolutionJoint *> _RJointList)
{
    setRJointList(_RJointList);
}

void AnimationControllWidget::getTimefromAnimationControllpanel(int _time)
{
    setSliderMaxValue(_time);
}

void AnimationControllWidget::runAnimation()
{
    qDebug() << "RUN";
    timer->start(interval);
    speedNow->setText(QString("      %1 %2").arg('X').arg(1/(interval/10)));
}

void AnimationControllWidget::pauseAnimation()
{
    qDebug() << "PAUSE";
    timer->stop();
    speedNow->setText(QString("      PAUSE"));
}

void AnimationControllWidget::stopAnimation()
{
    qDebug() << "STOP";
    speedNow->setText(QString("      STOP"));
    timer->stop();
    timeLineSlider->setValue(0);

    real4Bars[1]->setRectAngle(-real4BarsAngle[0]);
    real4Bars[1]->setMassCenter(QPointF(real4BarsPos[0].x(),-real4BarsPos[0].y()));

    real4Bars[2]->setRectAngle(-real4BarsAngle[1]);
    real4Bars[2]->setMassCenter(QPointF(real4BarsPos[1].x(),-real4BarsPos[1].y()));

    real4Bars[3]->setRectAngle(-real4BarsAngle[2]);
    real4Bars[3]->setMassCenter(QPointF(real4BarsPos[2].x(),-real4BarsPos[2].y()));

    foreach(RevolutionJoint* rJoint, RJointList){

        if(typeid(*rJoint->pinA->parentItem()) == typeid(NewBar)){
            QPointF jointPos = static_cast<NewBar *>(rJoint->pinA->parentItem())->getAbsPinPos(rJoint->pinA);

            jointPos.setX(jointPos.x()-rJoint->jointRadius);
            jointPos.setY(-jointPos.y()-rJoint->jointRadius);

            rJoint->setPos(jointPos);
            rJoint->timer->start(100);

       }else if(typeid(*rJoint->pinA->parentItem()) == typeid(Slide)){
            QPointF jointPos = static_cast<Slide *>(rJoint->pinA->parentItem())->getAbsPinPos(rJoint->pinA);

            jointPos.setX(jointPos.x()-rJoint->jointRadius);
            jointPos.setY(-jointPos.y()-rJoint->jointRadius);

            rJoint->setPos(jointPos);
            rJoint->timer->start(100);

       }else if(typeid(*rJoint->pinA->parentItem()) == typeid(Anchor)){
            QPointF jointPos = static_cast<Anchor *>(rJoint->pinA->parentItem())->getAbsPinPos(rJoint->pinA);

            jointPos.setX(jointPos.x()-rJoint->jointRadius);
            jointPos.setY(-jointPos.y()-rJoint->jointRadius);

            rJoint->setPos(jointPos);
            rJoint->timer->start(100);
        }

    }
}

void AnimationControllWidget::speedUp()
{
    interval *= 0.5;
    if(interval < 10*0.5*0.5*0.5*0.5){
        interval = interval/0.5;
    }
    qDebug() << interval;
    timer->start(interval);
    speedNow->setText(QString("      %1 %2").arg('X').arg(1/(interval/10)));
}

void AnimationControllWidget::speedNormal()
{
    interval = 10;
    timer->start(interval);
    speedNow->setText(QString("      %1 %2").arg('X').arg(interval/10));
}

void AnimationControllWidget::speedDown()
{
    interval *= 2;
    if(interval > 10*16){
        interval = interval/2;
    }
    qDebug() << interval;
    timer->start(interval);
    speedNow->setText(QString("      %1 %2").arg('X').arg(1/(interval/10)));
}

