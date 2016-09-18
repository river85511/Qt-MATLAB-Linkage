#ifndef SYSTEMPARAMDIALOG_H
#define SYSTEMPARAMDIALOG_H

#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QVariant>
#include <QCheckBox>

#include <QDebug>
class systemParamDialog: public QDialog
{
    Q_OBJECT
public:
    systemParamDialog(QString _currentLengthUnit, QWidget *parent = 0);

public slots:
    void okButtonClicked();

signals:
    void lengthUnitChanged(QString _currentLengthUnit);

private:

    QLabel *lengthUnitLabel;
    QComboBox *lengthUnitComboBox;

    QPushButton* okButton;
};

#endif // SYSTEMPARAMDIALOG_H
