#ifndef SIGNALSANDSLOTSWIDGET_H
#define SIGNALSANDSLOTSWIDGET_H

#include <QWidget>

namespace Ui {
class SignalsAndSlotsWidget;
}

class SignalsAndSlotsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SignalsAndSlotsWidget(QWidget *parent = 0);
    ~SignalsAndSlotsWidget();


signals:
    // define a signal
    void sigShowVal(const QString &text);

public slots:
    void sltLineEditChange(const QString& text);

private:
    Ui::SignalsAndSlotsWidget *ui;
};

#endif // SIGNALSANDSLOTSWIDGET_H
