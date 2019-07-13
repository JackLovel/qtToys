#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.move((QApplication::desktop()->width()), (QApplication::desktop()->height() - w.height()));
    w.setFixedSize(250, 250);
    w.show();

    QFile file(":/style/style.qss");
    file.open(QIODevice::ReadOnly);
    QString qss = file.readAll();
    qApp->setStyleSheet(qss);

    return a.exec();
}
