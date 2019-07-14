#include "mainwindow.h"

#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QDate>
#include <QDateTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mainWidget = new QWidget();
    layout = new QVBoxLayout();
    titleLayout = new QHBoxLayout();

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setWindowOpacity(0.7);

    initUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUI()
{
    QPushButton *closeButton = new QPushButton();
    closeButton->setFixedSize(19, 19);
    closeButton->setObjectName("CloseButton");
    closeButton->setFocusPolicy(Qt::NoFocus);

    layout->setMargin(5);
    layout->addLayout(titleLayout, 0);

    titleLayout->addStretch();
    titleLayout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, this, &QApplication::quit);

    QLabel *timeLabel = new QLabel();
    timeLabel->setStyleSheet("QLabel { font-size: 25px; color: #FFFFFF;}");

    QLabel *timeLabel2 = new QLabel();
    timeLabel2->setStyleSheet("QLabel { font-size: 17px; color: #FFFFFF;}");

    layout->addWidget(timeLabel, 0, Qt::AlignCenter);
    layout->addWidget(timeLabel2, 0, Qt::AlignCenter);
    layout->addStretch();

    QTimer *timer = new QTimer(this);
    timer->start(1000);

    connect(timer, &QTimer::timeout, this, [=]{
        QDateTime timeData = QDateTime::currentDateTime();
        timeLabel->setText(timeData.toString("hh:mm:ss"));
        timeLabel2->setText(timeData.toString("yyyy-MM-dd ddd"));
    });
}

void MainWindow::paintEvent(QPaintEvent */*e*/)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QColor("#FFFFFF"));
    painter.setBrush(QColor("#000000"));
    painter.drawRect(rect());
}

// 鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p); // 鼠标位置减去按下点的坐标
    }
}

// 鼠标按下事件
// globalPos 全局位置，相对于屏幕位置
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton) {
        p = e->globalPos() - frameGeometry().topLeft();  // 鼠标位置减去左上角的左边
    }
}






















