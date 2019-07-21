#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QMenu>

#include "thread.h"
#include "memorymonitor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void  paintEvent(QPaintEvent *);
    void  mouseMoveEvent(QMouseEvent *);
    void  mousePressEvent(QMouseEvent *);

private:
    QWidget *mainWidget;
    QHBoxLayout *layout;
    QVBoxLayout *networkLayout;
    MemoryMonitor *memoryMonitor;
    QLabel *downloadLabel;
    QLabel *uploadLabel;
    Thread *thread;
    QPoint p;
    QMenu *menu;

private slots:
    void  updateNetworkSpeed(QString, QString);
};

#endif // MAINWINDOW_H
