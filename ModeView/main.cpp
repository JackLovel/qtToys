#include "mymodel.h"
#include <QApplication>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTableView tableView;
    MyModel myModel;
    tableView.setModel(&myModel);
    tableView.show();

    return app.exec();
}
