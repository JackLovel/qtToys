#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUI();

protected:
    void  paintEvent(QPaintEvent *);
    void  mouseMoveEvent(QMouseEvent *);
    void  mousePressEvent(QMouseEvent *);

private:
    QWidget *mainWidget;
    QVBoxLayout *layout;
    QHBoxLayout *titleLayout;
    QPoint p;
};

#endif // MAINWINDOW_H
