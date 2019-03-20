#ifndef COLORGENWIDGET_H
#define COLORGENWIDGET_H

#include <QMainWindow>
#include <QGridLayout>
namespace Ui {
class ColorGenWidget;
}

class ColorGenWidget : public QMainWindow
{
    Q_OBJECT

public:
    ColorGenWidget(QWidget *parent = 0);
    ~ColorGenWidget();

private slots:
    void genLabel();
    void resetColor();

private:
    QVector<QColor> v;
    Ui::ColorGenWidget *ui;


};

#endif // COLORGENWIDGET_H
