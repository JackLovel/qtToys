#ifndef THUMBNAILWIDGET_H
#define THUMBNAILWIDGET_H

#include "ReadDefine.h"
#include "IChildViewer.h"
#include <QStandardItem>

class ThumbnailWidget : public QWidget
{
    Q_OBJECT
public:
    ThumbnailWidget(QWidget *parent = nullptr);
    ~ThumbnailWidget();

private:
    IChildViewer *m_IChildViewer;
    QVBoxLayout * m_vBoxlayout;

    int m_nTimerIdle;
    QListView *m_listView;
    QStandardItemModel *m_ItemModel;
    int m_nCurThumDrawPageNum;
    int m_nPageCount;

private:
    void timerEvent(QTimerEvent *);
};

#endif // THUMBNAILWIDGET_H
