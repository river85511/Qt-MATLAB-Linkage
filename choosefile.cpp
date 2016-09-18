#include "choosefile.h"

ChooseFile::ChooseFile(bool _checkMFile): checkMFile(_checkMFile)
{
    qDebug() << "ChooseFile created";

    ground = new NewBar(false,0);
    ground->setMassCenter(QPointF(0,0));
    ground->setVisible(false);
    real4Bars.push_back(ground);

    timer = new QTimer();
}

ChooseFile::~ChooseFile()
{
    qDebug() << "ChooseFile deleted";
}

void ChooseFile::findAllJoints()
{
    foreach(QGraphicsItem* item, totalItemsList){
        if(typeid(*item) == typeid(RevolutionJoint))
            RJointList.push_front(static_cast<RevolutionJoint *>(item));
    }
    qDebug() << "ALL JOINTS HAVE BEEN FOUND!";
    qDebug() << "RJointList size: " << RJointList.size();
    return;
}

void ChooseFile::chooseAFile()
{
    if(!checkMFile){
        QMessageBox msgBox;
        msgBox.setText("ERROR: Gen MatlabFile First.");
        msgBox.exec();

        qDebug() << "ERROR: Gen MatlabFile First.";
        return;
    }

    //fileName = QFileDialog::getOpenFileName(NULL,tr("Open File"),"animation.txt","Text File (*.txt)");
    fileName = "animation.txt";
    qDebug() << fileName;

    if(!fileName.isEmpty() && !fileName.isNull()){

        if(!checkRJointListSize() || !checkRigidBodyIDListSize()){
            return;
        }

        addReal4Bars();
        if(!checkReal4BarsListSize()){
            return;
        }

        AnimationControllPanel* panel = new AnimationControllPanel(NULL,time);

        connect(this,SIGNAL(passTimeToAnimationControllpanel(int)),panel,SLOT(getTimefromChooseFile(int)));
        connect(this,SIGNAL(passFileNameToAnimationControllpanel(QString)),panel,SLOT(getFileNamefromChooseFile(QString)));
        connect(this,SIGNAL(passReal4BarsListToAnimationControllpanel(QList<NewBar *>)),panel,SLOT(getReal4BarsListfromChooseFile(QList<NewBar *>)));
        connect(this,SIGNAL(passReal4BarsPosListToAnimationControllpanel(QList<QPointF>)),panel,SLOT(getReal4BarsPosListfromChooseFile(QList<QPointF>)));
        connect(this,SIGNAL(passReal4BarsAngleListToAnimationControllpanel(QList<double>)),panel,SLOT(getReal4BarsAngleListfromChooseFile(QList<double>)));
        connect(this,SIGNAL(passRJointListToAnimationControllpanel(QList<RevolutionJoint *>)),panel,SLOT(getRJointListfromChooseFile(QList<RevolutionJoint*>)));       

        //qDebug() << RJointList.size();
        foreach(RevolutionJoint* rJoint, RJointList){
            rJoint->timer->stop();
            RJointPosList.push_front(rJoint->pos());
        }
        emit passTimeToAnimationControllpanel(time);
        emit passFileNameToAnimationControllpanel(fileName);
        emit passReal4BarsListToAnimationControllpanel(real4Bars);
        emit passReal4BarsPosListToAnimationControllpanel(real4BarsPos);
        emit passReal4BarsAngleListToAnimationControllpanel(real4BarsAngle);
        emit passRJointListToAnimationControllpanel(RJointList);

        qDebug() << "emit sucess";
        //timer->start(10);
        panel->exec();

        return;

    }else{
        RJointList.clear();
        //qDebug() << "cancel";
        return;
    }

    return;
}

bool ChooseFile::checkRJointListSize()
{
    if(RJointList.size()<3){
        QMessageBox msgBox;
        msgBox.setText("ERROR: Cannot find rigidBodyIDs.");
        msgBox.exec();

        qDebug() << "ERROR: Cannot find rigidBodyIDs.";
        RJointList.clear();
        return false;
    }else
        return true;
}

bool ChooseFile::checkRigidBodyIDListSize()
{
    if(rigidBodyIDList.size() == 0){
        QMessageBox msgBox;
        msgBox.setText("ERROR: Gen MatlabFile First.");
        msgBox.exec();

        qDebug() << "ERROR: Gen MatlabFile First.";
        RJointList.clear();
        return false;
    }else
        return true;
}

void ChooseFile::addReal4Bars()
{
    foreach(QGraphicsItem* item, totalRBList){
        for(int i=1; i<4; i++){
            if(typeid(*item) == typeid(NewBar)){
                if(static_cast<NewBar *>(item)->id == rigidBodyIDList[i]){
                    real4Bars.push_back(static_cast<NewBar *>(item));
                    real4BarsPos.push_back(static_cast<NewBar *>(item)->getRectMassCenter());
                    //qDebug() <<  static_cast<NewBar *>(item)->getRectMassCenter();
                    real4BarsAngle.push_back(static_cast<NewBar *>(item)->getRectAngle());
                    //qDebug() << rigidBodyIDList[i];
                    i++;

                    //qDebug() << real4Bars.size();
                    if(i == 4)
                        break;
                }
            }else if(typeid(*item) == typeid(Slide)){
                if(static_cast<Slide *>(item)->id == rigidBodyIDList[i]){
                    real4Bars.push_back(static_cast<NewBar *>(item));
                    real4BarsPos.push_back(static_cast<Slide *>(item)->getRectMassCenter());
                    //qDebug() <<  static_cast<NewBar *>(item)->getRectMassCenter();
                    real4BarsAngle.push_back(static_cast<Slide *>(item)->getRectAngle());
                    i++;
                    //qDebug() << real4Bars.size();
                    if(i == 4)
                        break;
                }
            }
        }
    }
    //qDebug() << real4Bars.size();
    //qDebug() << "add 4bar sucess";
}

bool ChooseFile::checkReal4BarsListSize()
{
    if(real4Bars.size()<4){
        QMessageBox msgBox;
        msgBox.setText("ERROR: Not Enough RigidBodys.");
        msgBox.exec();

        qDebug() << "ERROR: Not Enough RigidBodys";
        RJointList.clear();
        rigidBodyIDList.clear();
        real4Bars.clear();
        return false;
    }else
        return true;
}

void ChooseFile::setTotalItemList(QList<QGraphicsItem *> _totalItemsList)
{
    totalItemsList = _totalItemsList;
}

void ChooseFile::setTotalRBList(QList<QGraphicsItem *> _totalRBList)
{
    totalRBList = _totalRBList;
    //qDebug() << "totalRBList size " << totalRBList;
}

void ChooseFile::setRigidBodyIDList(QList<int> _rigidBodyIDList)
{
    rigidBodyIDList = _rigidBodyIDList;
}

void ChooseFile::setTime(int _time)
{
    time = _time;
}

void ChooseFile::getTotalItemListFromDisplay(QList<QGraphicsItem *> _totalItemsList)
{
    setTotalItemList(_totalItemsList);
}

void ChooseFile::getTotalRBListFromDisplay(QList<QGraphicsItem *> _totalRBList)
{
    setTotalRBList(_totalRBList);
}

void ChooseFile::getRigidBodyIDListFromDisplay(QList<int> _rigidBodyIDList)
{
    setRigidBodyIDList(_rigidBodyIDList);
}

void ChooseFile::getTimeFromDisplay(int _time)
{
    setTime(_time);
}
