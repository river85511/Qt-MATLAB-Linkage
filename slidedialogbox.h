#ifndef SLIDEDIALOGBOX_H
#define SLIDEDIALOGBOX_H

#include <QColor>
#include <QPointF>
#include <QLabel>
#include <QString>
#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QColorDialog>
#include <QComboBox>

#include <QDebug>

#define PI 3.14159265

class SlideDialogBox: public QDialog
{
    Q_OBJECT
public:
    SlideDialogBox(QGraphicsRectItem *bar, int _pJointConnectingId, QWidget *parent = 0);

    QPointF rotationMatrix(double _x, double _y, double _theta);
    QPointF rotationMatrix(QPointF _vect, double _theta);

    QPointF getMassCenterFromString(QString _massCenterStr);

    bool checkIdValidity(const int& _id);

public slots:
    void okClicked();
    void colorClicked();
    void setButtonColor(QColor _color);
    void getIdListFromSlide(std::list<int> _idList);
    void getSlideId(int _slideId);

    void changeAngleUnit(int index);

signals:
    void changeMassCenter(QPointF massCenter);
    void changeRectAngle(double rectAngle);
    void changePJointConnectingId(int _pJointConnectingId);
    void changeRectColor(QColor rectColor);

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

    QPushButton *colorButton;
    QColor rectColor;

    QLabel *pJointLabel;
    QLineEdit *pJointLineEdit;
    int pJointConnectingId;

    int slideId;
    std::list<int> idList;

    QPushButton *okButton;
};

#endif // SLIDEDIALOGBOX_H
