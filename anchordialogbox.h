#ifndef ANCHORDIALOGBOX_H
#define ANCHORDIALOGBOX_H

#include <cmath>

#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QComboBox>

#include <QDebug>

#define PI 3.14159265

class AnchorDialogBox: public QDialog
{
    Q_OBJECT
public:
    AnchorDialogBox(QGraphicsEllipseItem *bar, QWidget *parent = 0);

    QPointF rotationMatrix(double _x, double _y, double _theta);
    QPointF rotationMatrix(QPointF _vect, double _theta);

    QPointF getMassCenterFromString(QString _massCenterStr);

public slots:
    void okButtonClicked();

    void changeAngleUnit(int index);

signals:
    void changeRectAngle(double rectAngle);
    void changeMassCenter(QPointF massCenter);

private:
    QLabel *massCenterLabel;
    QLineEdit *massCenterLineEdit;

    QLabel *rectAngleLabel;
    QLineEdit *rectAngleLineEdit;
    QComboBox* angleUnitCheckBox;

    QPointF rectOrigin;
    QPointF massCenter;
    double rectWidth;
    double rectHeight;
    double rectAngle;

    QPushButton *okButton;
};

#endif // ANCHORDIALOGBOX_H
