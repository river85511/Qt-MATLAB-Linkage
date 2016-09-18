#ifndef NEWBARDIALOGBOX_H
#define NEWBARDIALOGBOX_H

#include <QColor>
#include <QPointF>
#include <QLabel>
#include <QString>
#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QColorDialog>
#include <QCheckBox>
#include <QSlider>
#include <QComboBox>

#include <QDebug>

#define PI 3.14159265

class NewBarDialogBox: public QDialog
{
    Q_OBJECT
public:
    NewBarDialogBox(bool _isDrivingLink, double _angularVel, double _angularAcc, QGraphicsRectItem *bar, QWidget *parent = 0);

    QPointF rotationMatrix(double _x, double _y, double _theta);
    QPointF rotationMatrix(QPointF _vect, double _theta);

    QPointF getMassCenterFromString(QString _massCenterStr);

public slots:
    void okClicked();
    void colorClicked();
    void setButtonColor(QColor _color);
    void drivingLinkChecked(bool _checked);

    void changeAngleUnit(int index);

signals:
    void changeMassCenter(QPointF massCenter);
    void changeRectWidth(double rectWidth);
    void changeRectAngle(double rectAngle);
    void changeRectColor(QColor rectColor);
    void setAsDrivingLink(bool isDirvingLink);
    void changeAngularVel(double angularVel);
    void changeAngularAcc(double angularAcc);

private:

    QLabel *massCenterLabel;
    QLineEdit *massCenterLineEdit;

    QLabel *rectWidthLabel;
    QLineEdit *rectWidthLineEdit;
    QLabel *rectAngleLabel;
    QLineEdit *rectAngleLineEdit;
    QComboBox* angleUnitCheckBox;

    QLabel *drivingLinkLabel;
    QCheckBox *drivingLinkCheckBox;

    QLabel *angularVelLabel;
    QLineEdit *angularVelLineEdit;
    QLabel *angularAccLabel;
    QLineEdit *angularAccLineEdit;

    QPointF rectOrigin;
    QPointF massCenter;
    double rectWidth;
    double rectHeight;
    double rectAngle;

    QPushButton *colorButton;
    QColor rectColor;

    bool isDrivingLink;
    double angularVel;
    double angularAcc;

    QPushButton *okButton;

    QWidget *extension;
};

#endif // NEWBARDIALOGBOX_H
