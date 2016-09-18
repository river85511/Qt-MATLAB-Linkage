#include "plotgraph.h"

PlotGraph::PlotGraph(QWidget *parent)
{
    gridLayout = new QGridLayout();
    this->setLayout(gridLayout);

    this->showMinimized();
}

void PlotGraph::plotGraph()
{

    for(int i=0; i<3; i++){
        customPlot = new QCustomPlot(this);
        customPlot->addGraph();
        customPlot->xAxis->setLabel("t");
        QCPPlotTitle* title = new QCPPlotTitle(customPlot);
        if(i == 0)
        {
            title->setText(titles[i]);
//            customPlot->graph(0)->setData(timeData, xData);

            customPlot->yAxis->setLabel(yAxis[i]);
            customPlot->xAxis->setRange(0, getDataMax(timeData));
            customPlot->yAxis->setRange(getDataMin(xData), getDataMax(xData));
            QCPCurve * newCurve = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
            newCurve->setData(timeData,xData);
            customPlot->addPlottable(newCurve);
        }
        else if(i == 1)
        {
            title->setText(titles[i]);
//            customPlot->graph(0)->setData(timeData, yData);
            customPlot->yAxis->setLabel(yAxis[i]);
            customPlot->xAxis->setRange(0, getDataMax(timeData));
            customPlot->yAxis->setRange(getDataMin(yData), getDataMax(yData));
            QCPCurve * newCurve = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
            newCurve->setData(timeData,yData);
            customPlot->addPlottable(newCurve);
        }
        else if(i == 2)
        {
            title->setText(titles[i]);
//            customPlot->graph(0)->setData(timeData, phiData);
            customPlot->yAxis->setLabel(yAxis[i]);
            customPlot->xAxis->setRange(0, getDataMax(timeData));
            customPlot->yAxis->setRange(getDataMin(phiData), getDataMax(phiData));
            QCPCurve * newCurve = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
            newCurve->setData(timeData,phiData);
            customPlot->addPlottable(newCurve);
        }

        title->setFont(QFont("sans",12, QFont::Bold));
        customPlot->plotLayout()->insertRow(0);
        customPlot->plotLayout()->addElement(0,0,title);

        customPlot->replot();
        gridLayout->addWidget(customPlot);

    }

}


void PlotGraph::setTitles(QVector<QString> _titles)
{
    titles = _titles;
}

void PlotGraph::setYAxis(QVector<QString> _yAxis)
{
    yAxis = _yAxis;
}

void PlotGraph::setData(QVector<double> _data)
{
    data = _data;
    for(int i =0; i<_data.size()-1; i++){
        if(i <data.size()/3)
            xData.push_back(data[i]);
        else if((data.size()/3 <= i) && (i < data.size()*2/3))
            yData.push_back(data[i]);
        else if((data.size()*2/3 <= i) && (i < data.size()))
            phiData.push_back(data[i]);
    }

}

void PlotGraph::setTimeData(QVector<double> _timeData)
{
    timeData = _timeData;
}

double PlotGraph::getDataMax(QVector<double> _data)
{
    QVector<double>::iterator i = _data.begin();
    double max = (*i);

    for(; i != _data.end(); i++){
        double now = (*i);

        if(now > max)
            max = now;
    }

    return max;
}

double PlotGraph::getDataMin(QVector<double> _data)
{
    QVector<double>::iterator i = _data.begin();
    double min = (*i);

    for(; i != _data.end(); i++){
        double now = (*i);

        if(now < min)
            min = now;
    }

    return min;
}


void PlotGraph::changeTitles(QVector<QString> _titles)
{
    this->setTitles(_titles);
}

void PlotGraph::changeYAxis(QVector<QString> _yAxis)
{
    this->setYAxis(_yAxis);
}

void PlotGraph::changeData(QVector<double> _data)
{
    this->setData(_data);
}

void PlotGraph::changeTimeData(QVector<double> _timeData)
{
    this->setTimeData(_timeData);
}
