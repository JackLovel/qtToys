#include "singlecontinuousstate.h"

class  DocWidget;

SingleContinuousState::SingleContinuousState(IChildViewer *childViewer) : m_ChildViewer(childViewer)
{

}

void SingleContinuousState::RenderPages(QPainter *paint)
{
    if (paint == NULL) {
        return;
    }

    int nScrollHeight = 0; // 当前窗口的高度
    int nScrollYFlag = 0; // 当前坐标
    nScrollHeight = m_ChildViewer->getScrollArea()->size().height(); // 当前绘制的剩余窗口高度
    nScrollYFlag = GetVScrollPos();

    // 首先刷一下灰色

    // 当前绘制的页码
    int nPageNum;
    // 当前页码绘制的起始VPos
    int nPageVPos;

    // 当前页码的图片
    QImage img;
    QImage imageCopy;

    int nXDrawPos = 0;

    while (nScrollHeight > 0) {
        GetVPos(nScrollYFlag, nPageNum, nPageVPos);

        // 绘制当前页的高度
        int nRenderHeight = GetPageSize(nPageNum).height() + 8 - nPageVPos;

        imageCopy = m_ChildViewer->getPageImage(nPageNum);
        img = imageCopy.copy(0, nPageVPos, GetPageSize(nPageNum).width(), nRenderHeight);

        QSize docWidget = m_ChildViewer->getDocWidgetSize();
        nXDrawPos = ((docWidget.width() - GetPageSize(nPageNum).width())) / 2;
        if (nXDrawPos < 0) {
            nxDrawPos = m_ChildViewer->getScrollArea()->verticalScrollBar()->size().width() / 2;

            paint->drawImage(nXDrawPos, nScrollYFlag, img);

            nScrollHeight -= img.height();
            nScrollYFlag += img.height();
        }
    }
}

int SingleContinuousState::GetCurPageNum()
{
    int nCurPagePos = GetVScrollPos() + m_ChildViewer->getDocWidgetSize().height() / 2;
    int nPageCount = GetPageCount();
    for (int i = 0; i < nPageCount; i++) {
        if (nCurPagePos < m_ChildViewer->getPageSize(i).height()) {
            return i;
        }
    }
}


