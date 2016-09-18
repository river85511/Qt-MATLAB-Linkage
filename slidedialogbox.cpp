#include "slidedialogbox.h"

SlideDialogBox::SlideDialogBox(QGraphicsRectItem *bar, int _pJointConnectingId, QWidget *parent):
    rectOrigin(bar->pos()), rectWidth(bar->rect().width()), rectHeight(bar->rect().height()), rectAngle(bar->rotation()),
    rectColor(bar->brush().color()), pJointConnectingId(_pJointConnectingId)
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
    rectAngleLabel->setBuddy(rectAngleLineEdit);    angleUnitCheckBox = new QComboBox();
    angleUnitCheckBox->addItem("deg");
    angleUnitCheckBox->addItem("rad");
    connect(angleUnitCheckBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeAngleUnit(int)));

    pJointLabel = new QLabel(tr("&Translate On:"));
    pJointLineEdit = new QLineEdit(QString("%1").arg(pJointConnectingId));
    pJointLabel->setBuddy(pJointLineEdit);

    QLabel *colorLabel = new QLabel(tr("&Color:"));
    colorButton = new QPushButton();
    setButtonColor(rectColor);
    connect(colorButton,SIGNAL(pressed()),this,SLOT(colorClicked()));
    colorLabel->setBuddy(colorButton);

    QHBoxLayout *topLeftLayout = new QHBoxLayout();
    topLeftLayout->addWidget(massCenterLabel);
    topLeftLayout->addWidget(massCenterLineEdit);

    QHBoxLayout *topLeftLayout2 = new QHBoxLayout();
    topLeftLayout2->addWidget(rectAngleLabel);
    topLeftLayout2->addWidget(rectAngleLineEdit);
    topLeftLayout2->addWidget(angleUnitCheckBox);

    QHBoxLayout *topLeftLayout3 = new QHBoxLayout();
    topLeftLayout3->addWidget(pJointLabel);
    topLeftLayout3->addWidget(pJointLineEdit);

    QHBoxLayout *topLeftLayout4 = new QHBoxLayout();
    topLeftLayout4->addWidget(colorLabel);
    topLeftLayout4->addWidget(colorButton);

    okButton = new QPushButton(tr("&Ok"));
    okButton->setDefault(true);
    connect(okButton,SIGNAL(pressed()),this,SLOT(okClicked()));

    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(topLeftLayout, 0, 0);
    mainLayout->addLayout(topLeftLayout2, 1, 0);
    mainLayout->addLayout(topLeftLayout3, 2, 0);
    mainLayout->addLayout(topLeftLayout4, 3, 0);
    mainLayout->addWidget(okButton, 4, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Properties"));

    return;
}

QPointF SlideDialogBox::rotationMatrix(double _x, double _y, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _x - sin(_theta *PI/ 180.0)* _y;
    double y = sin(_theta * PI/ 180.0)* _x + cos(_theta *PI/ 180.0)* _y;

    return QPointF(x,y);
}

QPointF SlideDialogBox::rotationMatrix(QPointF _vect, double _theta)
{
    double x = cos(_theta * PI/ 180.0)* _vect.x() - sin(_theta *PI/ 180.0)* _vect.y();
    double y = sin(_theta * PI/ 180.0)* _vect.x() + cos(_theta *PI/ 180.0)* _vect.y();

    return QPointF(x,y);
}

QPointF SlideDialogBox::getMassCenterFromString(QString _massCenterStr)
{
    QStringList xPos = _massCenterStr.split('(').last().split(',');
    QString x = xPos.first();
    QStringList yPos = _massCenterStr.split(')').first().split(',');
    QString y = yPos.last();
    QPointF _massCenter = QPointF(x.toFloat(),y.toFloat());
    _massCenter.setY(-_massCenter.y());     //Owing to the differences in coordinates between Qt and Right-Hand-Coodinates;(RE-TRANS)

    return _massCenter;
}

bool SlideDialogBox::checkIdValidity(const int &_id)
{
    if(slideId == _id)
    {
        return false;
    }

    std::list<int>::iterator i = idList.begin();
    for(; i != idList.end(); i++){
        if( *(i) == _id){
            return true;
        }
    }

    return false;
}

void SlideDialogBox::okClicked()
{

    QString angleStr = rectAngleLineEdit->text();
    if(angleUnitCheckBox->currentIndex() == 0)
        emit changeRectAngle(-angleStr.toDouble());
    else if(angleUnitCheckBox->currentIndex() == 1)
        emit changeRectAngle(-angleStr.toDouble()*180.0/PI);

    QString massCenterStr = massCenterLineEdit->text();
    emit changeMassCenter(getMassCenterFromString(massCenterStr));

    QString pJointConnectingIdStr = pJointLineEdit->text();
    int enteredId = pJointConnectingIdStr.toInt();
    if(checkIdValidity(enteredId))
        emit changePJointConnectingId(pJointConnectingIdStr.toInt());
    else
        qDebug() << "INVALID NUM!";

    emit changeRectColor(rectColor);

    this->close();
    return;
}

void SlideDialogBox::colorClicked()
{
    QColorDialog* colorDialog = new QColorDialog(this);
    colorDialog->setCurrentColor(rectColor);
    connect(colorDialog,SIGNAL(currentColorChanged(QColor)),this,SLOT(setButtonColor(QColor)));
    colorDialog->exec();

    return;
}

void SlideDialogBox::setButtonColor(QColor _color)
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

void SlideDialogBox::getIdListFromSlide(std::list<int> _idList)
{
    idList = _idList;
}

void SlideDialogBox::getSlideId(int _slideId)
{
    slideId = _slideId;
}

void SlideDialogBox::changeAngleUnit(int index)
{
    qDebug() << "Angle Unit changed";
    QString currentAngle = rectAngleLineEdit->text();

    if(index == 0)
        rectAngleLineEdit->setText(QString("%1").arg(currentAngle.toDouble()/PI*180.0));
    else if(index == 1)
        rectAngleLineEdit->setText(QString("%1").arg(currentAngle.toDouble()*PI/180.0));
}


