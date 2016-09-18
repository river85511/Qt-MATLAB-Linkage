#ifndef MYPLOTMAINWINDOW_H
#define MYPLOTMAINWINDOW_H
#include <QDialog>
#include <QGridLayout>
#include <QMainWindow>
#include "plottab.h"
#include <QKeyEvent>

class PlotDialog: public QDialog
{
public:
    PlotDialog(QWidget* parent = NULL);

    void keyPressEvent(QKeyEvent* event);

private:
    PlotTab* plotWidget;
};

#endif // MYPLOTMAINWINDOW_H
