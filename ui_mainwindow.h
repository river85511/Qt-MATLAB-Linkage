/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "display.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Project;
    QAction *action_Save_Project;
    QAction *action_Save_Project_2;
    QWidget *centralWidget;
    Display *graphicsView;
    QPushButton *systemParam;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *genAnchorButton;
    QPushButton *genBarButton;
    QPushButton *genSlideButton;
    QPushButton *showCoordinate;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *genFunction;
    QPushButton *chooseFile;
    QSpacerItem *verticalSpacer;
    QPushButton *captureButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1062, 709);
        MainWindow->setMouseTracking(false);
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QStringLiteral("actionNew_Project"));
        action_Save_Project = new QAction(MainWindow);
        action_Save_Project->setObjectName(QStringLiteral("action_Save_Project"));
        action_Save_Project_2 = new QAction(MainWindow);
        action_Save_Project_2->setObjectName(QStringLiteral("action_Save_Project_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new Display(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(200, 50, 800, 600));
        systemParam = new QPushButton(centralWidget);
        systemParam->setObjectName(QStringLiteral("systemParam"));
        systemParam->setGeometry(QRect(70, 80, 56, 56));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 180, 181, 91));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        genAnchorButton = new QPushButton(widget);
        genAnchorButton->setObjectName(QStringLiteral("genAnchorButton"));
        genAnchorButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(genAnchorButton->sizePolicy().hasHeightForWidth());
        genAnchorButton->setSizePolicy(sizePolicy);
        genAnchorButton->setMouseTracking(false);
        genAnchorButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(genAnchorButton);

        genBarButton = new QPushButton(widget);
        genBarButton->setObjectName(QStringLiteral("genBarButton"));
        sizePolicy.setHeightForWidth(genBarButton->sizePolicy().hasHeightForWidth());
        genBarButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(genBarButton);

        genSlideButton = new QPushButton(widget);
        genSlideButton->setObjectName(QStringLiteral("genSlideButton"));
        sizePolicy.setHeightForWidth(genSlideButton->sizePolicy().hasHeightForWidth());
        genSlideButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(genSlideButton);


        verticalLayout->addLayout(horizontalLayout);

        showCoordinate = new QPushButton(widget);
        showCoordinate->setObjectName(QStringLiteral("showCoordinate"));
        showCoordinate->setFlat(false);

        verticalLayout->addWidget(showCoordinate);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(70, 320, 61, 271));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        genFunction = new QPushButton(widget1);
        genFunction->setObjectName(QStringLiteral("genFunction"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(genFunction->sizePolicy().hasHeightForWidth());
        genFunction->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(genFunction);

        chooseFile = new QPushButton(widget1);
        chooseFile->setObjectName(QStringLiteral("chooseFile"));
        sizePolicy1.setHeightForWidth(chooseFile->sizePolicy().hasHeightForWidth());
        chooseFile->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(chooseFile);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer);

        captureButton = new QPushButton(widget1);
        captureButton->setObjectName(QStringLiteral("captureButton"));
        sizePolicy1.setHeightForWidth(captureButton->sizePolicy().hasHeightForWidth());
        captureButton->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(captureButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1062, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_WHATSTHIS
        MainWindow->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionNew_Project->setText(QApplication::translate("MainWindow", "&New Project", 0));
        action_Save_Project->setText(QApplication::translate("MainWindow", "&Load Project", 0));
        action_Save_Project_2->setText(QApplication::translate("MainWindow", "&Save Project", 0));
#ifndef QT_NO_STATUSTIP
        systemParam->setStatusTip(QApplication::translate("MainWindow", "Set system parameter", 0));
#endif // QT_NO_STATUSTIP
        systemParam->setText(QString());
#ifndef QT_NO_STATUSTIP
        genAnchorButton->setStatusTip(QApplication::translate("MainWindow", "Create Anchor", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        genAnchorButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        genAnchorButton->setText(QString());
#ifndef QT_NO_STATUSTIP
        genBarButton->setStatusTip(QApplication::translate("MainWindow", "Create Bar", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        genBarButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        genBarButton->setText(QString());
#ifndef QT_NO_STATUSTIP
        genSlideButton->setStatusTip(QApplication::translate("MainWindow", "Create Slide", 0));
#endif // QT_NO_STATUSTIP
        genSlideButton->setText(QString());
#ifndef QT_NO_STATUSTIP
        showCoordinate->setStatusTip(QApplication::translate("MainWindow", "Show/Hide coordinates", 0));
#endif // QT_NO_STATUSTIP
        showCoordinate->setText(QApplication::translate("MainWindow", "Show Coordinate", 0));
#ifndef QT_NO_STATUSTIP
        genFunction->setStatusTip(QApplication::translate("MainWindow", "Create MATLAB file", 0));
#endif // QT_NO_STATUSTIP
        genFunction->setText(QString());
#ifndef QT_NO_STATUSTIP
        chooseFile->setStatusTip(QApplication::translate("MainWindow", "Run Animation", 0));
#endif // QT_NO_STATUSTIP
        chooseFile->setText(QString());
#ifndef QT_NO_STATUSTIP
        captureButton->setStatusTip(QApplication::translate("MainWindow", "Take screenShot ", 0));
#endif // QT_NO_STATUSTIP
        captureButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
