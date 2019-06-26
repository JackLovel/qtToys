#include <QApplication>

#include "tableeditor.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection())
        return 1;

    TableEditor editor("person");
    editor.show();

    return app.exec();
}
