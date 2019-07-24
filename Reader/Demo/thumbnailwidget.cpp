#include "thumbnailwidget.h"

ThumbnailWidget::ThumbnailWidget(IChildViewer *childViewer) : m_IChildViewer(childViewer), m_nCurThumDrawPageNum(0), m_nPageCount(0)
{
    m_nTimerIdle = startTimer(0);
    m_vBoxlayout = new QVBoxLayout(this);
    m_listView = new QListView();
    m_listView->setViewMode(QListView::IConMode);
    m_listView->setSpacing(10);
    m_listView->setIconSize(QSize(150, 300));
    m_listView->setModelColumn(1);
    m_listView->setMovement(QListView::Static);
    m_listView->setResizeMode(QListView::Adjust);
    m_ItemModel = new QStandardItemModel();
    m_ItemModel->setModel(m_ItemModel);
    m_vBoxlayout->addWidget(m_listView);
    m_vBoxlayout->setContentsMargins(1, 1, 1, 1);

    m_nPageCount = m_IChildViewer->getPageCount();
}

ThumbnailWidget::~ThumbnailWidget()
{
    
}

void ThumbnailWidget::timeEvent(QTimerEvent *)
{
    if (m_nCurThumDrawPageNum >= m_nPageCount) {
        return;
    }

    QImage img;
    img = m_IChildViewer->getActruallyPage(m_nCurThumDrawPageNum);
    QPixmap pixmap;
    pixmap = QPixmap::fromImage(img);

    QString strPageNum = QString::number(m_nCurThumDrawPageNum + 1);
    QStandardItem *item = new QStandardItem(QIcon(pixmap), strPageNum);
    m_ItemModel->appendRow(item);
    m_nCurThumDrawPageNum++;
    // m_listView->setModel(m_ItemModel);
}