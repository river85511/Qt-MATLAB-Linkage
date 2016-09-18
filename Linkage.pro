#-------------------------------------------------
#
# Project created by QtCreator 2016-08-09T15:31:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
                                  QT += multimedia
TARGET = Linkage
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    display.cpp \
    slide.cpp \
    newbar.cpp \
    newbardialogbox.cpp \
    pinhole.cpp \
    revolutionjoint.cpp \
    slidedialogbox.cpp \
    anchor.cpp \
    anchordialogbox.cpp \
    globalcoordinate.cpp \
    prismaticjoint.cpp \
    matlabfile.cpp \
    plotdialog.cpp \
    plotgraph.cpp \
    plottab.cpp \
    qcustomplot.cpp \
    animationcontrollpanel.cpp \
    animationcontrollwidget.cpp \
    choosefile.cpp \
    systemparamdialog.cpp

HEADERS  += mainwindow.h \
    display.h \
    slide.h \
    newbar.h \
    newbardialogbox.h \
    pinhole.h \
    revolutionjoint.h \
    slidedialogbox.h \
    anchor.h \
    anchordialogbox.h \
    globalcoordinate.h \
    prismaticjoint.h \
    matlabfile.h \
    plotdialog.h \
    plotgraph.h \
    plottab.h \
    qcustomplot.h \
    animationcontrollpanel.h \
    animationcontrollwidget.h \
    choosefile.h \
    systemparamdialog.h

FORMS    += mainwindow.ui

RESOURCES += \
    pics.qrc
