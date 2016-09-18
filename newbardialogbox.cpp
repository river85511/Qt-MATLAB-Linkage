#include "newbardialogbox.h"

NewBarDialogBox::NewBarDialogBox(bool _isDrivingLink, double _angularVel, double _angularAcc, QGraphicsRectItem *bar, QWidget *parent):
    rectOrigin(bar->pos()), rectWidth(bar->rect().width()), rectHeight(bar->rect().height()), rectAngle(bar->rotation()),
    rectColor(bar->brush().color()),
    isDrivingLink(_isDrivingLink), angularVel(_angularVel), angularAcc(_angularAcc)

{
    massCenterLabel = new QLabel(tr("Mass &Center:"));

    if(bar->transformOriginPoint() == QPointF(0,0)){
          massCenter = rectOrigin + rotationMatrix(rectWidth/2, rectHeight/2, rectAngle);
          massCenter.setY(-massCenter.y());     //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(TRANS)
    }
    else{
        massCenter = rectOrigin + QPointF(rectWidth/2, rectHeight/2);
        massCenter.setY(-massCenter.y());       //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(TRANS)
    }

    massCenterLineEdit = new QLineEdit(QString("(%1,%2)").arg(massCenter.x()).arg(massCenter.y()));
    massCenterLabel->setBuddy(massCenterLineEdit);

    rectWidthLabel = new QLabel(tr("&Length:"));
    rectWidthLineEdit = new QLineEdit(QString("%1").arg(rectWidth));
    rectWidthLabel->setBuddy(rectWidthLineEdit);

    rectAngleLabel = new QLabel(tr("&Agnle:"));
    rectAngleLineEdit = new QLineEdit(QString("%1").arg(-rectAngle));   //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(TRANS)
    rectAngleLabel->setBuddy(rectAngleLineEdit);
    angleUnitCheckBox = new QComboBox();
    angleUnitCheckBox->addItem("deg");
    angleUnitCheckBox->addItem("rad");
    connect(angleUnitCheckBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeAngleUnit(int)));

    QLabel *colorLabel = new QLabel(tr("&Color:"));
    colorButton = new QPushButton();
    setButtonColor(rectColor);
    connect(colorButton,SIGNAL(pressed()),this,SLOT(colorClicked()));
    colorLabel->setBuddy(colorButton);

    drivingLinkLabel = new QLabel(tr("&Driving Link"));
    drivingLinkCheckBox = new QCheckBox();
    drivingLinkCheckBox->setChecked(isDrivingLink);
    drivingLinkLabel->setBuddy(drivingLinkCheckBox);
    connect(drivingLinkCheckBox,SIGNAL(clicked(bool)),this,SLOT(drivingLinkChecked(bool)));

    angularVelLabel = new QLabel(tr("&Angular Velocity:"));
    angularVelLineEdit = new QLineEdit(QString("%1").arg(angularVel));
    angularVelLabel->setBuddy(angularVelLineEdit);

    angularAccLabel = new QLabel(tr("&Angular Acceleration:"));
    angularAccLineEdit = new QLineEdit(QString("%1").arg(angularAcc));
    angularAccLabel->setBuddy(angularVelLineEdit);

    QHBoxLayout *topLeftLayout = new QHBoxLayout();
    topLeftLayout->addWidget(massCenterLabel);
    topLeftLayout->addWidget(massCenterLineEdit);

    QHBoxLayout *topLeftLayout2 = new QHBoxLayout();
    topLeftLayout2->addWidget(rectWidthLabel);
    topLeftLayout2->addWidget(rectWidthLineEdit);

    QHBoxLayout *topLeftLayout3 = new QHBoxLayout();
    topLeftLayout3->addWidget(rectAngleLabel);
    topLeftLayout3->addWidget(rectAngleLineEdit);
    topLeftLayout3->addWidget(angleUnitCheckBox);

    QHBoxLayout *topLeftLayout4 = new QHBoxLayout();
    topLeftLayout4->addWidget(colorLabel);
    topLeftLayout4->addWidget(colorButton);

    QHBoxLayout *topLeftLayout5 = new QHBoxLayout();
    topLeftLayout5->addWidget(drivingLinkLabel);
    topLeftLayout5->addWidget(drivingLinkCheckBox);

    QHBoxLayout *topLeftLayout6 = new QHBoxLayout();
    topLeftLayout6->addWidget(angularVelLabel);
    topLeftLayout6->addWidget(angularVelLineEdit);

    QHBoxLayout *topLeftLayout7 = new QHBoxLayout();
    topLeftLayout7->addWidget(angularAccLabel);
    topLeftLayout7->addWidget(angularAccLineEdit);

    QVBoxLayout *extensionLayout = new QVBoxLayout();
    extensionLayout->addLayout(topLeftLayout6);
    extensionLayout->addLayout(topLeftLayout7);
    extension = new QWidget;
    extension->setLayout(extensionLayout);

    okButton = new QPushButton(tr("&Ok"));
    okButton->setDefault(true);
    connect(okButton,SIGNAL(pressed()),this,SLOT(okClicked()));

    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(topLeftLayout, 0, 0);
    mainLayout->addLayout(topLeftLayout2, 1, 0);
    mainLayout->addLayout(topLeftLayout3, 2, 0);
    mainLayout->addLayout(topLeftLayout4, 3, 0);
    mainLayout->addLayout(topLeftLayout5, 4, 0);

    mainLayout->addWidget(extension, 5, 0, 1, 2);
    mainLayout->addWidget(okButton, 7, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Properties"));
    extension->setVisible(isDrivingLink);

    return;
}

QPointF NewBarDialogBox::rotationMatrix(double _x, double _y, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _x - sin(_theta *PI/ 180.0)* _y;
    double y = sin(_theta * PI/ 180.0)* _x + cos(_theta *PI/ 180.0)* _y;

    return QPointF(x,y);
}

QPointF NewBarDialogBox::rotationMatrix(QPointF _vect, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _vect.x() - sin(_theta *PI/ 180.0)* _vect.y();
    double y = sin(_theta * PI/ 180.0)* _vect.x() + cos(_theta *PI/ 180.0)* _vect.y();

    return QPointF(x,y);
}

QPointF NewBarDialogBox::getMassCenterFromString(QString _massCenterStr)
{
    QStringList xPos = _massCenterStr.split('(').last().split(',');
    QString x = xPos.first();
    QStringList yPos = _massCenterStr.split(')').first().split(',');
    QString y = yPos.last();
    QPointF _massCenter = QPointF(x.toDouble(),y.toDouble());
            _massCenter.setY(-_massCenter.y());     //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(RE-TRANS)

    return _massCenter;
}

void NewBarDialogBox::okClicked()
{
    QString lengthStr = rectWidthLineEdit->text();
    emit changeRectWidth(lengthStr.toDouble());

    QString angleStr = rectAngleLineEdit->text();
    if(angleUnitCheckBox->currentIndex() == 0)
        emit changeRectAngle(-angleStr.toDouble());
    else if(angleUnitCheckBox->currentIndex() == 1)
        emit changeRectAngle(-angleStr.toDouble()*180.0/PI);

    QString massCenterStr = massCenterLineEdit->text();
    emit changeMassCenter(getMassCenterFromString(massCenterStr));

    emit changeRectColor(rectColor);

    if(drivingLinkCheckBox->isChecked()){
        isDrivingLink = true;
        //qDebug() << "yes";
        emit setAsDrivingLink(isDrivingLink);

        QString angularVelocity = angularVelLineEdit->text();
        emit changeAngularVel(angularVelocity.toDouble());

        QString angularAcceleration = angularAccLineEdit->text();
        emit changeAngularAcc(angularAcceleration.toDouble());
    }else{
        isDrivingLink = false;
        //qDebug() << "no";
        emit setAsDrivingLink(isDrivingLink);

        emit changeAngularVel(0);

        emit changeAngularAcc(0);
    }

    this->close();
    return;
}

void NewBarDialogBox::colorClicked()
{
    QColorDialog* colorDialog = new QColorDialog(this);
    colorDialog->setCurrentColor(rectColor);
    connect(colorDialog,SIGNAL(currentColorChanged(QColor)),this,SLOT(setButtonColor(QColor)));
    colorDialog->exec();

    return;
}

void NewBarDialogBox::setButtonColor(QColor _color)
{
    rectColor = _color;
    QString s("background: #"
                          + QString(_color.red() < 16? "0" : "") + QString::number(_color.red(),16)
                          + QString(_color.green() < 16? "0" : "") + QString::number(_color.green(),16)
                          + QString(_color.blue() < 16? "0" : "") + QString::number(_color.blue(),16) + ";");
    colorButton->setStyleSheet(s);
    colorButton->update();

    return;
}

void NewBarDialogBox::drivingLinkChecked(bool _checked)
{
    if(_checked){
//        qDebug() << "good";
        extension->setVisible(true);
    }else{
//        qDebug() << "bad";
        extension->setVisible(false);
    }

    return;
}

void NewBarDialogBox::changeAngleUnit(int index)
{
    qDebug() << "Angle Unit changed";
    QString currentAngle = rectAngleLineEdit->text();

    if(index == 0)
        rectAngleLineEdit->setText(QString("%1").arg(currentAngle.toDouble()/PI*180.0));
    else if(index == 1)
        rectAngleLineEdit->setText(QString("%1").arg(currentAngle.toDouble()*PI/180.0));
}

