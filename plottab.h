#ifndef MYPLOTWIDGET_H
#define MYPLOTWIDGET_H

#include <QTabWidget>
#include <QWidget>
#include <QVector>
#include <QGridLayout>
#include <QObject>


#include "plotgraph.h"

class PlotTab: public QTabWidget
{
    Q_OBJECT
public:
    PlotTab(QWidget *parent = NULL);

    void addTab(QTabWidget *tabWidget, QString title);

    void genTitles();
    void genYAxis();

    void genTab();

    void createTestData();

signals:
    void passDisplacementTitlesToGraph(QVector<QString> _displacementTitles);
    void passVelocityTitlesToGraph(QVector<QString> _velocityTitles);
    void passAccelerationTitlesToGraph(QVector<QString> _accelerationTitles);

    void passDisplacementYAxisToGraph(QVector<QString> _displacementYAxis);
    void passVelocityYAxisToGraph(QVector<QString> _velocityYAxis);
    void passAccelerationYAxisToGraph(QVector<QString> _accelerationYAxis);

    void passDisplacementDataToGraph(QVector<double> _displacementData);
    void passVelocityDataToGraph(QVector<double> _velocityData);
    void passAccelerationDataToGraph(QVector<double> _accelerationData);

    void passTimeDataToGraph(QVector<double> _timeData);

private:
    QGridLayout* gridLayout;

    QVector<QString> displacementTitles;
    QVector<QString> velocityTitles;
    QVector<QString> accelerationTitles;

    QVector<QString> displacementYAxis;
    QVector<QString> velocityYAxis;
    QVector<QString> accelerationYAxis;

    QVector<double> displacementData;
    QVector<double> velocityData;
    QVector<double> accelerationData;

    QVector<double> timeData;

};

#endif // MYPLOTWIDGET_H
