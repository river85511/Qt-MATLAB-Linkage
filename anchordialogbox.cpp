#include "anchordialogbox.h"

AnchorDialogBox::AnchorDialogBox(QGraphicsEllipseItem *bar, QWidget *parent):
    rectOrigin(bar->pos()), rectWidth(bar->rect().width()), rectHeight(bar->rect().height()), rectAngle(bar->rotation())
{
    massCenterLabel = new QLabel(tr("Mass &Center:"));

    if(bar->transformOriginPoint() == QPointF(0,0)){
          massCenter = rectOrigin + rotationMatrix(rectWidth/2, rectHeight/2, rectAngle);
          massCenter.setY(-massCenter.y());     //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(TRANS)
    }
    else{
        massCenter = rectOrigin + QPointF(rectWidth/2, rectHeight/2);
        massCenter.setY(-massCenter.y());     //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(TRANS)
    }

    massCenterLineEdit = new QLineEdit(QString("(%1,%2)").arg(massCenter.x()).arg(massCenter.y()));
    massCenterLabel->setBuddy(massCenterLineEdit);

    rectAngleLabel = new QLabel(tr("&Agnle:"));
    rectAngleLineEdit = new QLineEdit(QString("%1").arg(-rectAngle));   //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(TRANS)
    rectAngleLabel->setBuddy(rectAngleLineEdit);
    angleUnitCheckBox = new QComboBox();
    angleUnitCheckBox->addItem("deg");
    angleUnitCheckBox->addItem("rad");
    connect(angleUnitCheckBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeAngleUnit(int)));

    QHBoxLayout *topLeftLayout = new QHBoxLayout();
    topLeftLayout->addWidget(massCenterLabel);
    topLeftLayout->addWidget(massCenterLineEdit);

    QHBoxLayout *topLeftLayout3 = new QHBoxLayout();
    topLeftLayout3->addWidget(rectAngleLabel);
    topLeftLayout3->addWidget(rectAngleLineEdit);
    topLeftLayout3->addWidget(angleUnitCheckBox);

    okButton = new QPushButton(tr("&Ok"));
    okButton->setDefault(true);
    connect(okButton,SIGNAL(pressed()),this,SLOT(okButtonClicked()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(topLeftLayout, 0, 0);
    mainLayout->addLayout(topLeftLayout3, 2, 0);

    mainLayout->addWidget(okButton, 3, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Properties"));
    return;
}

QPointF AnchorDialogBox::rotationMatrix(double _x, double _y, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _x - sin(_theta *PI/ 180.0)* _y;
    double y = sin(_theta * PI/ 180.0)* _x + cos(_theta *PI/ 180.0)* _y;

    return QPointF(x,y);
}

QPointF AnchorDialogBox::rotationMatrix(QPointF _vect, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _vect.x() - sin(_theta *PI/ 180.0)* _vect.y();
    double y = sin(_theta * PI/ 180.0)* _vect.x() + cos(_theta *PI/ 180.0)* _vect.y();

    return QPointF(x,y);
}

QPointF AnchorDialogBox::getMassCenterFromString(QString _massCenterStr)
{
    QStringList xPos = _massCenterStr.split('(').last().split(',');
    QString x = xPos.first();
    QStringList yPos = _massCenterStr.split(')').first().split(',');
    QString y = yPos.last();
    QPointF _massCenter = QPointF(x.toDouble(),y.toDouble());
            _massCenter.setY(-_massCenter.y());     //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(RE-TRANS)

    return _massCenter;
}

void AnchorDialogBox::okButtonClicked()
{

    QString angleStr = rectAngleLineEdit->text();
    if(angleUnitCheckBox->currentIndex() == 0)
        emit changeRectAngle(-angleStr.toDouble());
    else if(angleUnitCheckBox->currentIndex() == 1)
        emit changeRectAngle(-angleStr.toDouble()*180.0/PI);
//    emit changeRectAngle(-angleStr.toDouble());     //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(RE-TRANS)

    QString massCenterStr = massCenterLineEdit->text();
    emit changeMassCenter(getMassCenterFromString(massCenterStr));


    this->close();
    return;
}

void AnchorDialogBox::changeAngleUnit(int index)
{
    qDebug() << "Angle Unit changed";
    QString currentAngle = rectAngleLineEdit->text();

    if(index == 0)
        rectAngleLineEdit->setText(QString("%1").arg(currentAngle.toDouble()/PI*180.0));
    else if(index == 1)
        rectAngleLineEdit->setText(QString("%1").arg(currentAngle.toDouble()*PI/180.0));

}
