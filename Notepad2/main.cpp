#include "notepad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Notepad window;
    window.resize(600, 500);
    window.move(250, 150);
    window.setWindowTitle("Notepad Exmaple");
    window.show();

    return app.exec();
}
