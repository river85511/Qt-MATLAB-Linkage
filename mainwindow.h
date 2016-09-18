#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QList>
#include <QPixmap>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void keyPressEvent(QKeyEvent* event);
    ~MainWindow();

public slots:
    void showHideText();

signals:
    void removeSelectedItem(QGraphicsItem* _selectedItems);

private:
    Ui::MainWindow *ui;
    bool showOrHide;
};

#endif // MAINWINDOW_H
