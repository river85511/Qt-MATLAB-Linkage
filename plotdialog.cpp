#include "plotdialog.h"

PlotDialog::PlotDialog(QWidget *parent): QDialog(parent)
{

    this->setMinimumSize(800,600);

    plotWidget = new PlotTab(this);

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->addWidget(plotWidget);

    this->setLayout(gridLayout);

    this->setWindowTitle("Bar 1 - Simulation Results");
}

void PlotDialog::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        this->close();
    }
}

