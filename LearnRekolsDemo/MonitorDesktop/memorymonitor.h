#ifndef MEMORYMONITOR_H
#define MEMORYMONITOR_H

#include <QWidget>

class MemoryMonitor : public QWidget
{
    Q_OBJECT

public:
    MemoryMonitor(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

private:
    float percent;
};

#endif // MEMORYMONITOR_H
