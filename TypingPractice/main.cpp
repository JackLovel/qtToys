#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.resize(500, 500);
    //window.setFixedSize(500, 500);
    window.show();

    return app.exec();
}
