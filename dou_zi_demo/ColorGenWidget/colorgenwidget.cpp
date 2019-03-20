#include "colorgenwidget.h"
#include "ui_colorgenwidget.h"
#include "colorgen.h"

#include <QTimer>
#include <QLabel>
#include <QGridLayout>

ColorGenWidget::ColorGenWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColorGenWidget)
{
    ui->setupUi(this);

    v.resize(1000);
    std::generate(v.begin(), v.end(), ColorGen(v.size()));

    genLabel();

    // timer
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ColorGenWidget::resetColor);
    timer->start(2000);
}

ColorGenWidget::~ColorGenWidget()
{
    delete ui;
}

// generate 100 color label
void ColorGenWidget::genLabel()
{
    for (int i = 0; i < 100; ++i)
    {
        QLabel *label = new QLabel;

        ui->gridLayout->addWidget(label, i / 10, i % 10, 1, 1);
    }
    resetColor();
}


// reset every label color
void ColorGenWidget::resetColor()
{
    static int start = 0;
    if (start >= v.size())
        start = 0;

    for (int i = 0; i < 100; ++i)
    {
        int r = i / 10; // row
        int c = i % 10; // col

        QLabel *label = dynamic_cast<QLabel*>(ui->gridLayout->itemAtPosition(r, c)->widget());
        if (label)
        {
            label->setStyleSheet(QString("QLabel{background-color:%1}").arg(v.at(i+ start).name()));
        }
    }
    start += 100;
}



