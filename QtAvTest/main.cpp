#include "mainwindow.h"
#include <QApplication>
#include <QtAVWidgets>

int main(int argc, char *argv[])
{
    QtAV::Widgets::registerRenderers();
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    window.resize(800, 600);

    return a.exec();
}
