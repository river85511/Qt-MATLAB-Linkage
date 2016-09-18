#ifndef BARDIALOGBOX_H
#define BARDIALOGBOX_H

#include <cmath>

#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>

#include <QDebug>

#define PI 3.14159265

class BarDialogBox: public QDialog
{
    Q_OBJECT
public:
    BarDialogBox(QGraphicsEllipseItem *a, QWidget *parent = 0);

public slots:
    void okButtonClicked();

signals:
    void angleChanged(float angle);
    void lengthChanged(float length);
    void massCenterChanged(QPointF mc);

private:
    QLabel *mcLabel;
    QLineEdit *mcLineEdit;
    QLabel *lengthLabel;
    QLineEdit *lengthLineEdit;
    QLabel *angleLabel;
    QLineEdit *angleLineEdit;

    QPushButton *okButton;
};

#endif // BARDIALOGBOX_H
