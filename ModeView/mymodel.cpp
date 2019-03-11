#include "mymodel.h"
#include "ui_mymodel.h"
#include <QDebug>
#include <QTime>

MyModel::MyModel(QObject *parent)
    : QAbstractTableModel(parent)
    , timer(new QTimer(this))
{
    timer->setInterval(10000);
    connect(timer, &QTimer::timeout, this, &MyModel::timerHit);
    timer->start();
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return 5;
}


int MyModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

//    qDebug() << QString("row %1, col %2, role %3")
//                .arg(row).arg(col).arg(role);

//    switch (role) {
//    case Qt::DisplayRole:
//        if (row == 0 && col == 1) return QString("<--left");
//        if (row == 1 && col == 1) return QString("right-->");

//        return QString("Row %1, Column %2")
//                .arg(row + 1)
//                .arg(col + 1);
//    case Qt::FontRole:
//        if (row == 0 && col == 0)
//        {
//            QFont boldFont;
//            boldFont.setBold(true);
//            return boldFont;
//        }
//        break;
//    case Qt::BackgroundRole:
//        if (row == 1 && col == 2)
//            return QBrush(Qt::red);
//        break;
//    case Qt::TextAlignmentRole:
//        if (row == 1 && col == 1)
//            return Qt::AlignRight + Qt::AlignVCenter;
//        break;
//    case Qt::CheckStateRole:
//        if (row == 1 && col == 0)
//            return Qt::Checked;
//        break;
//    }

    if (role == Qt::DisplayRole && row == 0 && col == 0)
        return QTime::currentTime().toString();

    return QVariant();
}


void MyModel::timerHit()
{
    QModelIndex topLeft = createIndex(0, 0);
    emit dataChanged(topLeft, topLeft, {Qt::DisplayRole});
}

