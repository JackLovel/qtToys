#include "editors.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Editors mainWin;
    mainWin.show();

    return app.exec();
}
