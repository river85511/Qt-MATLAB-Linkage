#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    showOrHide(true)
{
    this->setFixedSize(1062,709);
    this->setStyleSheet("QMainWindow{background-color:rgb(240, 240, 240);}");

    ui->setupUi(this);
    ui->graphicsView->setParent(this);
    ui->graphicsView->show();

    QPixmap anchorPixmap(":/pics/anchor.png");
    QIcon anchorButtonIcon(anchorPixmap);
    ui->genAnchorButton->setIcon(anchorButtonIcon);
    ui->genAnchorButton->setIconSize(anchorPixmap.rect().size()/3);
    ui->genAnchorButton->setFixedSize(anchorPixmap.rect().size()/3*1.15);


    QPixmap barPixmap(":/pics/bar.png");
    QIcon barButtonIcon(barPixmap);
    ui->genBarButton->setIcon(barButtonIcon);
    ui->genBarButton->setIconSize(barPixmap.rect().size()/3);
    ui->genBarButton->setFixedSize(barPixmap.rect().size()/3*1.15);

    QPixmap slidePixmap(":/pics/slide.png");
    QIcon slideButtonIcon(slidePixmap);
    ui->genSlideButton->setIcon(slideButtonIcon);
    ui->genSlideButton->setIconSize(slidePixmap.rect().size()/3);
    ui->genSlideButton->setFixedSize(slidePixmap.rect().size()/3*1.15);

    QPixmap capturePixmap(":/pics/screenShot.png");
    QIcon captureButtonIcon(capturePixmap);
    ui->captureButton->setIcon(captureButtonIcon);
    ui->captureButton->setIconSize(capturePixmap.rect().size()/3);
    ui->captureButton->setFixedSize(capturePixmap.rect().size()/3*1.15);

    QPixmap matlabPixmap(":/pics/matlab.png");
    QIcon matlabButtonIcon(matlabPixmap);
    ui->genFunction->setIcon(matlabButtonIcon);
    ui->genFunction->setIconSize(matlabPixmap.rect().size()/3);
    ui->genFunction->setFixedSize(matlabPixmap.rect().size()/3*1.15);

    QPixmap playAnimationPixmap(":/pics/playAnimation.png");
    QIcon playAnimationButtonIcon(playAnimationPixmap);
    ui->chooseFile->setIcon(playAnimationButtonIcon);
    ui->chooseFile->setIconSize(playAnimationPixmap.rect().size()/3);
    ui->chooseFile->setFixedSize(playAnimationPixmap.rect().size()/3*1.15);

    QPixmap setSystemParamPixmap(":/pics/setSystemParam.png");
    QIcon setSystemParamButtonIcon(setSystemParamPixmap);
    ui->systemParam->setIcon(setSystemParamButtonIcon);
    ui->systemParam->setIconSize(setSystemParamPixmap.rect().size()/3);
    ui->systemParam->setFixedSize(setSystemParamPixmap.rect().size()/3*1.15);

    connect(ui->systemParam,SIGNAL(pressed()),ui->graphicsView,SLOT(genSystemParamDialog()));
    connect(ui->genAnchorButton,SIGNAL(pressed()),ui->graphicsView,SLOT(genAnchor()));
    connect(ui->genBarButton,SIGNAL(pressed()),ui->graphicsView,SLOT(genBar()));
    connect(ui->genSlideButton,SIGNAL(pressed()),ui->graphicsView,SLOT(genSlide()));
    connect(ui->genFunction,SIGNAL(pressed()),ui->graphicsView,SLOT(genMatlabFile()));
    connect(ui->showCoordinate,SIGNAL(pressed()),ui->graphicsView,SLOT(showCoordinate()));
    connect(ui->showCoordinate,SIGNAL(pressed()),this,SLOT(showHideText()));
    connect(ui->captureButton,SIGNAL(pressed()),ui->graphicsView,SLOT(screenCapture()));
    connect(ui->chooseFile,SIGNAL(pressed()),ui->graphicsView,SLOT(chooseFile()));
    connect(this,SIGNAL(removeSelectedItem(QGraphicsItem*)),ui->graphicsView,SLOT(removeSelectedItem(QGraphicsItem*)));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        this->close();
    }else if(event->key() == Qt::Key_Delete){
       QList<QGraphicsItem *> selectedItemsList =  ui->graphicsView->scene->selectedItems();
       if(selectedItemsList.size() != 0)
            emit removeSelectedItem(selectedItemsList.at(0));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showHideText()
{
    if(showOrHide){
        ui->showCoordinate->setText("Hide Coordinate");
        showOrHide = false;
    }else{
       ui->showCoordinate->setText("Show Coordinate");
       showOrHide = true;
    }
}
