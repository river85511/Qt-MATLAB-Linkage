#include "plottab.h"

PlotTab::PlotTab(QWidget *parent): QTabWidget(parent)
{
    this->setMinimumSize(800,600);
    this->show();

    gridLayout = new QGridLayout();
    this->setLayout(gridLayout);

    genTitles();
    genYAxis();

    createTestData();
    genTab();
}

void PlotTab::addTab(QTabWidget *tabWidget, QString title)
{
    PlotGraph *graph = new PlotGraph(this);
    if(title == QString("Displacement"))
    {
        connect(this,SIGNAL(passDisplacementTitlesToGraph(QVector<QString>)),graph,SLOT(changeTitles(QVector<QString>)));
        connect(this,SIGNAL(passDisplacementYAxisToGraph(QVector<QString>)),graph,SLOT(changeYAxis(QVector<QString>)));
        connect(this,SIGNAL(passDisplacementDataToGraph(QVector<double>)),graph,SLOT(changeData(QVector<double>)));
        connect(this,SIGNAL(passTimeDataToGraph(QVector<double>)),graph,SLOT(changeTimeData(QVector<double>)));
        emit this->passDisplacementTitlesToGraph(displacementTitles);
        emit this->passDisplacementYAxisToGraph(displacementYAxis);
        emit this->passDisplacementDataToGraph(displacementData);
        emit this->passTimeDataToGraph(timeData);

//        graph->plotEverything1();
    }
    else if(title == QString("Velocity"))
    {
        connect(this,SIGNAL(passVelocityTitlesToGraph(QVector<QString>)),graph,SLOT(changeTitles(QVector<QString>)));
        connect(this,SIGNAL(passVelocityYAxisToGraph(QVector<QString>)),graph,SLOT(changeYAxis(QVector<QString>)));
        connect(this,SIGNAL(passVelocityDataToGraph(QVector<double>)),graph,SLOT(changeData(QVector<double>)));
        connect(this,SIGNAL(passTimeDataToGraph(QVector<double>)),graph,SLOT(changeTimeData(QVector<double>)));
        emit this->passVelocityTitlesToGraph(velocityTitles);
        emit this->passVelocityYAxisToGraph(velocityYAxis);
        emit this->passVelocityDataToGraph(velocityData);
        emit this->passTimeDataToGraph(timeData);

//        graph->plotEverything2();
    }
    else if(title == QString("Acceleration"))
    {
        connect(this,SIGNAL(passAccelerationTitlesToGraph(QVector<QString>)),graph,SLOT(changeTitles(QVector<QString>)));
        connect(this,SIGNAL(passAccelerationYAxisToGraph(QVector<QString>)),graph,SLOT(changeYAxis(QVector<QString>)));
        connect(this,SIGNAL(passAccelerationDataToGraph(QVector<double>)),graph,SLOT(changeData(QVector<double>)));
        connect(this,SIGNAL(passTimeDataToGraph(QVector<double>)),graph,SLOT(changeTimeData(QVector<double>)));
        emit this->passAccelerationTitlesToGraph(accelerationTitles);
        emit this->passAccelerationYAxisToGraph(accelerationYAxis);
        emit this->passAccelerationDataToGraph(accelerationData);
        emit this->passTimeDataToGraph(timeData);

//        graph->plotEverything3();
    }

    graph->plotGraph();
    tabWidget->addTab(graph, title);
}

void PlotTab::genTitles()
{
    displacementTitles.push_back("Dx");
    displacementTitles.push_back("Dy");
    displacementTitles.push_back("Dphi");

    velocityTitles.push_back("Vx");
    velocityTitles.push_back("Vy");
    velocityTitles.push_back("Vphi");

    accelerationTitles.push_back("Ax");
    accelerationTitles.push_back("Ay");
    accelerationTitles.push_back("Aphi");
}

void PlotTab::genYAxis()
{
    displacementYAxis.push_back("x(m)");
    displacementYAxis.push_back("y(m)");
    displacementYAxis.push_back("phi(rad)");

    velocityYAxis.push_back("Vx(m/s)");
    velocityYAxis.push_back("Vy(m/s)");
    velocityYAxis.push_back("Vphi(rad/s)");

    accelerationYAxis.push_back("Ax(m/s^2)");
    accelerationYAxis.push_back("Ay(m/s^2)");
    accelerationYAxis.push_back("Aphi(rad/s^2)");
}

void PlotTab::genTab()
{
    this->addTab(this, "Displacement");
    this->addTab(this, "Velocity");
    this->addTab(this, "Acceleration");
}

void PlotTab::createTestData()
{
    for(double i = 0; i < 300; i += 0.1){
    displacementData.push_back(sin(i));
    velocityData.push_back(i*1.2);
    accelerationData.push_back(i*1.3);
    }

    for(double i = 0; i < 100; i += 0.1){
        timeData.push_back(i);
    }
}




