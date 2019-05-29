#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void setClipboardContent();
    void getClipboardContent();

protected:
    //void mouseReleaseEvent(QMouseEvent *) override;

private:
     QTextEdit *editor;
};

#endif // WIDGET_H
