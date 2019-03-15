#ifndef MYMODEL_H
#define MYMODEL_H

#include <QWidget>
#include <QAbstractTableModel>
#include <QTimer>


class MyModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    MyModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const  override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void timerHit();

private:
    QTimer *timer;
};



#endif // MYMODEL_H