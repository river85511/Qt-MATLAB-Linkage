#include "bardialogbox.h"

BarDialogBox::BarDialogBox(QGraphicsEllipseItem *a, QWidget *parent)
{
    mcLabel = new QLabel(tr("Mass &Center:"));
    double Xmc = a->scenePos().x() + cos(a->rotation()* PI / 180.0) * a->rect().width()/2 - sin(a->rotation()* PI / 180.0) * a->rect().height()/2;
    double Ymc = a->scenePos().y() + sin(a->rotation()* PI / 180.0) * a->rect().width()/2 + cos(a->rotation()* PI / 180.0) * a->rect().height()/2;
    mcLineEdit = new QLineEdit(QString("(%1,%2)").arg(Xmc).arg(Ymc));
    mcLabel->setBuddy(mcLineEdit);

    lengthLabel = new QLabel(tr("&Length:"));
    lengthLineEdit = new QLineEdit(QString("%1").arg(a->rect().width()));
    lengthLabel->setBuddy(lengthLineEdit);

    angleLabel = new QLabel(tr("&Agnle:"));
    angleLineEdit = new QLineEdit(QString("%1").arg(a->rotation()));
    angleLabel->setBuddy(angleLineEdit);

    QHBoxLayout *topLeftLayout = new QHBoxLayout();
    topLeftLayout->addWidget(mcLabel);
    topLeftLayout->addWidget(mcLineEdit);

    QHBoxLayout *topLeftLayout2 = new QHBoxLayout();
    topLeftLayout2->addWidget(lengthLabel);
    topLeftLayout2->addWidget(lengthLineEdit);

    QHBoxLayout *topLeftLayout3 = new QHBoxLayout();
    topLeftLayout3->addWidget(angleLabel);
    topLeftLayout3->addWidget(angleLineEdit);

    okButton = new QPushButton(tr("&Ok"));
    okButton->setDefault(true);
    connect(okButton,SIGNAL(pressed()),this,SLOT(okButtonClicked()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(topLeftLayout, 0, 0);
    mainLayout->addLayout(topLeftLayout2, 1, 0);
    mainLayout->addLayout(topLeftLayout3, 2, 0);

    mainLayout->addWidget(okButton, 3, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Properties"));
}

void BarDialogBox::okButtonClicked()
{

    /*Length*/
    QString lengthStr = lengthLineEdit->text();
//    qDebug() << "New Length = " << lengthStr.toFloat();
    emit lengthChanged(lengthStr.toFloat());

    /*Angle*/
    QString angleStr = angleLineEdit->text();
//    qDebug() << "New Angle = " << angleStr.toFloat();
    emit angleChanged(angleStr.toFloat());

    /*Mass Center*/
    QString massCenterStr = mcLineEdit->text();
    QStringList xPos = massCenterStr.split('(').last().split(',');
    QString x = xPos.first();
    QStringList yPos = massCenterStr.split(')').first().split(',');
    QString y = yPos.last();
    QPointF newMC = QPointF(x.toFloat(),y.toFloat());
//    qDebug() << "New MassCenter = " << newMC;
    emit massCenterChanged(newMC);



    this->close();
}
