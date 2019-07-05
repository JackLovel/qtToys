#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QtWidgets>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("不能打开数据库"),  QObject::tr("不能连接到数据库"));

        return false;
    }

    // 填充数据
    QSqlQuery query;
    query.exec("create table person (id int primary key,"
               "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into person values(101, 'Daanny', 'Young')");
    query.exec("insert into person values(102, 'Christine', 'Holand')");
    query.exec("insert into person values(103, 'Lars', 'Gordon')");
    query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");

    return true;
}
#endif // CONNECTION_H
