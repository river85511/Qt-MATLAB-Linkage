#include "display.h"

Display::Display(QWidget *parent):
    currentLengthUnit("m"),
    rigidBodyNum(1), drivingLinkID(0), coordinateSwitch(false),
    checkMFile(false)
{
    initializeDisplay();

    createGlobalCoordinates();

    this->setRenderHints(QPainter::Antialiasing);

    connect(this,SIGNAL(selectionChanged(QGraphicsItem*)),this,SLOT(showSelectionChanged(QGraphicsItem*)));
}

Display::~Display()
{
}

void Display::wheelEvent(QWheelEvent *event)
{


    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;



    if(event->delta() > 0)
    {
        scale(scaleFactor,scaleFactor);
    }
    else
    {
        scale(1/scaleFactor, 1/scaleFactor);
    }

}

void Display::mousePressEvent(QMouseEvent *event)
{
        if(itemAt(event->pos().x(),event->pos().y()) == NULL)
        {
            if(event->button() == Qt::RightButton){
//                qDebug() << "Mouse Click to View (PRESS)";

                _panStartX = event->x();
                _panStartY = event->y();
                setCursor(Qt::ClosedHandCursor);

            }else if(event->button() == Qt::LeftButton){
                emit selectionChanged(NULL);
            }
        }else{

//            qDebug() << "Mouse Click to Object";
            QGraphicsView::mousePressEvent(event);
                if(typeid(*itemAt(event->pos().x(),event->pos().y())) == typeid(NewBar)){
//                    qDebug() << "You've CLicked on a BAR";
                    itemAt(event->pos().x(),event->pos().y())->setSelected(true);
                    emit selectionChanged(itemAt(event->pos().x(),event->pos().y()));
                }else if(typeid(*itemAt(event->pos().x(),event->pos().y())) == typeid(Slide)){
//                    qDebug() << "You've Clicked on a SLIDE";
                    itemAt(event->pos().x(),event->pos().y())->setSelected(true);
                    emit selectionChanged(itemAt(event->pos().x(),event->pos().y()));
                }else if(typeid(*itemAt(event->pos().x(),event->pos().y())) == typeid(Anchor)){
//                    qDebug() << "You've Clicked on a ANCHOR";
                    itemAt(event->pos().x(),event->pos().y())->setSelected(true);
                    emit selectionChanged(itemAt(event->pos().x(),event->pos().y()));
                }
        }

}

void Display::mouseMoveEvent(QMouseEvent *event)
{

    if(event->buttons() & Qt::RightButton)
    {
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - _panStartX));
        verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - _panStartY));
        _panStartX = event->x();
        _panStartY = event->y();
    }
    else
    {
//        qDebug() << "Mouse Click to Object (MOVE)";
        QGraphicsView::mouseMoveEvent(event);
    }
}

void Display::mouseReleaseEvent(QMouseEvent *event)
{
    if(itemAt(event->pos().x(),event->pos().y()) == NULL)
    {
        if (event->button() == Qt::RightButton)
        {
            setCursor(Qt::ArrowCursor);
        }
    }else{
        QGraphicsView::mouseReleaseEvent(event);
    }
}

void Display::initializeDisplay()
{
    scene = new QGraphicsScene();
    setScene(scene);

    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(800,600);
    this->setSceneRect(-800,-600,1600,1200);
}

void Display::createGlobalCoordinates()
{
    globalCoordinates = new GlobalCoordinate();
    scene->addItem(globalCoordinates);
    ground = new NewBar(false,0);
    ground->setMassCenter(QPointF(0,0));
    ground->setVisible(false);
    idList.push_back(0);
    scene->addItem(ground);

}

void Display::genSystemParamDialog()
{
    qDebug() << "HI systemPARAM";
    dialog = new systemParamDialog(currentLengthUnit);
    connect(dialog,SIGNAL(lengthUnitChanged(QString)),this,SLOT(setLengthUnit(QString)));
    dialog->exec();
}

void Display::setLengthUnit(QString _currentLengthUnit)
{
    currentLengthUnit = _currentLengthUnit;
}

void Display::genAnchor()
{
    qDebug() << "genAnchor";
    Anchor* anchor = new Anchor();
    connect(anchor,SIGNAL(createRJoint(PinHole*,PinHole*,QPointF)),this,SLOT(genRJoint(PinHole*,PinHole*,QPointF)));
    scene->addItem(anchor);
}

void Display::genBar()
{
    qDebug() << "genBar";
    NewBar* newbar = new NewBar(coordinateSwitch, rigidBodyNum);
    newbar->id = rigidBodyNum;
    idList.push_back(rigidBodyNum);

    rigidBodyNum++;

    emit passIdListToSlide(idList);

    connect(newbar,SIGNAL(createRJoint(PinHole*,PinHole*,QPointF)),this,SLOT(genRJoint(PinHole*,PinHole*,QPointF)));

    connect(this,SIGNAL(showHideCoordinate(bool)),newbar,SLOT(showHideCoordinate(bool)));
    connect(newbar,SIGNAL(setDrivingLink(bool,int)),this,SLOT(setDrivingLink(bool,int)));

    scene->addItem(newbar);
}

void Display::genSlide()
{
    qDebug() << "genSlide";
    Slide* slide = new Slide(coordinateSwitch, rigidBodyNum);
    slide->id = rigidBodyNum;
    idList.push_back(rigidBodyNum);

    rigidBodyNum++;

    connect(slide,SIGNAL(createRJoint(PinHole*,PinHole*,QPointF)),this,SLOT(genRJoint(PinHole*,PinHole*,QPointF)));
    connect(this,SIGNAL(passIdListToSlide(std::list<int>)),slide,SLOT(getIdListFromDisplay(std::list<int>)));

    connect(this,SIGNAL(showHideCoordinate(bool)),slide,SLOT(showHideCoordinate(bool)));

    emit passIdListToSlide(idList);

    PrismaticJoint* pJoint = new PrismaticJoint(slide);
    pJoint->setPJointConnectingItem(ground);
    connect(slide,SIGNAL(passConnectingIdToDisplay(int)),this,SLOT(findItemWithId(int)));
    connect(this,SIGNAL(changePJointConnectingItem(NewBar*)),pJoint,SLOT(changePJointConnectingItem(NewBar*)));

    scene->addItem(slide);

}

void Display::genRJoint(PinHole *_pinA, PinHole *_pinB, QPointF _jointCenter)
{
    if( typeid(*(_pinA->parentItem())) == typeid(Slide) &&
        typeid(*(_pinB->parentItem())) == typeid(Slide)   )
    {
        //Two slide won't joint
    }else if( typeid(*(_pinA->parentItem())) == typeid(Anchor) &&
              typeid(*(_pinB->parentItem())) == typeid(Anchor)   ){
        //Two Anchor won't joint
    }
    else
    {
        RevolutionJoint* rJoint = new RevolutionJoint(_pinA,_pinB);
        rJoint->setCenter(_jointCenter);
        rJoint->show();
        scene->addItem(rJoint);
    }
}

void Display::genPJoint(Slide *_slide)
{
//    qDebug() << _slide->id;

//    Slide* slide = new Slide();
//    slide->id = rigidBodyNum;

    //    return;
}

void Display::screenCapture()
{
    QPixmap screenShot;
    screenShot = this->grab();
    QFile file("4-bar linkage system.png");
    file.open(QIODevice::WriteOnly);
    screenShot.save(&file, "PNG");
    file.close();
}

void Display::showSelectionChanged(QGraphicsItem *item)
{
//    qDebug() << "SELECTION CHANGE";
    QList<QGraphicsItem *> selectedItemsList = scene->selectedItems();

    if(item == NULL){
        foreach(QGraphicsItem* selectedItems, selectedItemsList)
            selectedItems->setSelected(false);

        return;
    }

    if(selectedItemsList.size() == 0){
        return;
    }else if(selectedItemsList.size() == 1){
        if(item == selectedItemsList.at(0)){
            return;
        }else{
            selectedItemsList.at(0)->setSelected(false);
            item->setSelected(true);
            return;
        }
    }else if(selectedItemsList.size() > 1){
        foreach(QGraphicsItem* selectedItems, selectedItemsList){
            if(selectedItems != item){
                selectedItems->setSelected(false);
            }
        }
        return;
    }

}

void Display::removeSelectedItem(QGraphicsItem *_selectedItem)
{

    QList<RevolutionJoint* > rJointList;
    getListOf<RevolutionJoint> (rJointList);

    foreach(RevolutionJoint* rJoint, rJointList){
        if(rJoint->pinA->parentItem() == _selectedItem){
            rJoint->removeJoint();
        }
        else if(rJoint->pinB->parentItem() == _selectedItem){
            rJoint->removeJoint();
        }
    }

    QList<QGraphicsItem*> itemList = scene->items();
    QList<QGraphicsItem*>::iterator iter = itemList.begin();

    for(; iter!= itemList.end(); iter++){
        if((*iter) == _selectedItem){
            if(typeid(*_selectedItem) == typeid(NewBar)){
                int id = static_cast<NewBar*>(_selectedItem)->id;
                idList.remove(id);
            }else if(typeid(*_selectedItem) == typeid(Slide)){
                int id = static_cast<Slide*>(_selectedItem)->id;
                idList.remove(id);
            }

            scene->removeItem(*iter);
            delete *iter;
            return;
        }
    }

}

void Display::chooseFile()
{
    chooseFile1 = new ChooseFile(checkMFile);
    checkMFile = false;
    connect(this,SIGNAL(passTotalItemListToChooseFile(QList<QGraphicsItem*>)),chooseFile1,SLOT(getTotalItemListFromDisplay(QList<QGraphicsItem *>)));
    connect(this,SIGNAL(passTotalRBListToChooseFile(QList<QGraphicsItem*>)),chooseFile1,SLOT(getTotalRBListFromDisplay(QList<QGraphicsItem *>)));
    connect(this,SIGNAL(passRigidBodyIDListToChooseFile(QList<int>)),chooseFile1,SLOT(getRigidBodyIDListFromDisplay(QList<int>)));
    connect(this,SIGNAL(passTimeToChooseFile(int)),chooseFile1,SLOT(getTimeFromDisplay(int)));

    QList<QGraphicsItem*> totalItemList = this->items();

    foreach(QGraphicsItem* item, totalItemList){
        if(typeid(*item) == typeid(NewBar) && static_cast<NewBar* >(item)->id!=0){
            totalRBList.push_front(static_cast<NewBar* >(item));
//            qDebug() << "id = " <<static_cast<NewBar* >(item)->id;
        }else if(typeid(*item) == typeid(Slide)){
            totalRBList.push_front(static_cast<Slide* >(item));
//            qDebug() << "id = " <<static_cast<Slide* >(item)->id;
        }
    }

//    qDebug() << "totalRBList size: " <<totalRBList.size();

    emit passTimeToChooseFile(time);
    emit passTotalItemListToChooseFile(totalItemList);
    emit passTotalRBListToChooseFile(totalRBList);
    emit passRigidBodyIDListToChooseFile(rigidBodyIDList);

    chooseFile1->findAllJoints();
    chooseFile1->chooseAFile();

    rigidBodyIDList.clear();
    totalRBList.clear();

    return;
}

void Display::getID(int _id)
{
    rigidBodyIDList.push_back(_id);
}

void Display::showCoordinate()
{
    emit showHideCoordinate(!coordinateSwitch);
    coordinateSwitch = !coordinateSwitch;
}

void Display::setDrivingLink(bool isDrivingLink, int id)
{
    if(isDrivingLink){
        drivingLinkID = id;
    }

    QList<NewBar *> totalBars;
    getListOf<NewBar> (totalBars);

    QList<NewBar *>::iterator i;
    int notDrivingLinkNum = 0;
    for(i = totalBars.begin(); i != totalBars.end(); i++){

        if((*i)->id != drivingLinkID){
            (*i)->isDrivingLink = false;
            (*i)->setAngularVel(0);
            (*i)->setAngularAcc(0);
        }

        if(!(*i)->isDrivingLink)
            notDrivingLinkNum++;
    }

    if(isDrivingLink){
//        qDebug() << "DrivingLink is Bar" << drivingLinkID;
    }else{
        if(notDrivingLinkNum == totalBars.size()){
            drivingLinkID = 0;
//            qDebug() << "DrivingLink is Bar" << drivingLinkID;
        }
//            qDebug() << "DrivingLink is Bar" << drivingLinkID;
    }
}

void Display::genMatlabFile()
{
    if(rigidBodyNum<4){
            QMessageBox msgBox;
            msgBox.setText("ERROR: Need at less four rigid bodys(include ground) to generate Matlabfile.");
            msgBox.exec();

            return;
        }

    bool ok;
    time = QInputDialog::getInt(this, tr("Set Time"),
                                         tr("How many second:"), 3, 1, 2147483647, 1, &ok);
    if(ok){
        qDebug() << "time = " <<time;

        matlabFile = new MatlabFile(currentLengthUnit);
        connect(this,SIGNAL(passTotalItemListToMatlabFile(QList<QGraphicsItem*>)),matlabFile,SLOT(getTotalItemListFromDisplay(QList<QGraphicsItem*>)));
        connect(matlabFile,SIGNAL(rigidBodyID(int)),this,SLOT(getID(int)));
        connect(this,SIGNAL(passTimeToMatlabFile(int)),matlabFile,SLOT(getTimeFromDisplay(int)));

        QList<QGraphicsItem*> totalItemList = this->items();
        emit passTotalItemListToMatlabFile(totalItemList);
        emit passTimeToMatlabFile(time);
        matlabFile->genFile();

        delete matlabFile;
        matlabFile = NULL;
        checkMFile = true;
        return;
    }else{
        return;
    }
}

void Display::findItemWithId(int _pJointConnectingId)
{

    if(_pJointConnectingId == 0){
        emit changePJointConnectingItem(ground);
        return;
    }

//    qDebug() << _pJointConnectingId;
    QList<QGraphicsItem *> totalItemList = this->items();
    foreach(QGraphicsItem* item, totalItemList){
        if(typeid(*(item)) == typeid(NewBar)){
            if(static_cast<NewBar *>(item)->id == _pJointConnectingId){
//                qDebug() << static_cast<NewBar *>(item)->getRectMassCenter();
                emit changePJointConnectingItem(static_cast<NewBar *>(item));
                return;
            }
        }
    }

}

template <typename T>
void Display::getListOf(QList<T*> &listOut)
{
    QList<QGraphicsItem*> itemList = scene->items();
    foreach(QGraphicsItem* item, itemList){
        if(typeid(*item) == typeid(T)){
            listOut.push_back(static_cast<T*>(item));
        }
    }
}
