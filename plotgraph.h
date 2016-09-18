#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QString>
#include <QVector>
#include <QFont>
#include <QObject>

#include "qcustomplot.h"

class PlotGraph:public QWidget
{
    Q_OBJECT
public:
    PlotGraph(QWidget* parent = NULL);

    void plotGraph();

    void setTitles(QVector<QString> _titles);
    void setYAxis(QVector<QString> _yAxis);

    void setData(QVector<double> _data);
    void setTimeData(QVector<double> _timeData);
    double getDataMax(QVector<double> _data);
    double getDataMin(QVector<double> _data);

public slots:
    void changeTitles(QVector<QString> _titles);
    void changeYAxis(QVector<QString> _yAxis);

    void changeData(QVector<double> _data);
    void changeTimeData(QVector<double> _timeData);

private:
    QGridLayout* gridLayout;
    QVector<QString> titles;
    QVector<QString> yAxis;

    QVector<double> data;
        QVector<double> xData;
        QVector<double> yData;
        QVector<double> phiData;
    QVector<double> timeData;

    QCustomPlot* customPlot;
    QVector<double> x;
    QVector<double> y;
};

#endif // MYWIDGET_H
