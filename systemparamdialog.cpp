#include "systemparamdialog.h"

systemParamDialog::systemParamDialog(QString _currentLengthUnit, QWidget *parent)
{
    lengthUnitLabel = new QLabel(tr("&Length Unit:"));
    lengthUnitComboBox = new QComboBox();
        lengthUnitComboBox->addItem("km");
        lengthUnitComboBox->addItem("m");
        lengthUnitComboBox->addItem("cm");
        lengthUnitComboBox->addItem("mm");
//        lengthUnitComboBox->setCurrentIndex(currentLengthIndex);
        lengthUnitComboBox->setCurrentText(_currentLengthUnit);
    lengthUnitLabel->setBuddy(lengthUnitComboBox);

    okButton = new QPushButton(tr("&Ok"));
    okButton->setDefault(true);
    connect(okButton,SIGNAL(clicked(bool)),this,SLOT(okButtonClicked()));

    QHBoxLayout *HLayout_lengthUnit = new QHBoxLayout();
    HLayout_lengthUnit->addWidget(lengthUnitLabel);
    HLayout_lengthUnit->addWidget(lengthUnitComboBox);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    mainLayout->addLayout(HLayout_lengthUnit,0,0);
    mainLayout->addWidget(okButton, 3, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("System Parameter"));
    return;

}

void systemParamDialog::okButtonClicked()
{
    qDebug() << lengthUnitComboBox->currentText();
    emit lengthUnitChanged(lengthUnitComboBox->currentText());

    this->close();
}
