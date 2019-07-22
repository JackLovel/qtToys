#ifndef VIEWMODEL_H
#define VIEWMODEL_H


#include "kit.h"
#include "pdfkit.h"
#include "viewsate.h"
#include "singlecontinuousstate.h"

#include <QtWidgets>

class ChlidViewer;
class DocWidget;

class ViewModel
{
public:
    ViewModel(ChlidViewer *ChlidViewer);
    ~ViewModel();

public:
  ChlidViewer *m_ViewState;
  Kit *m_kit;

private:
  ViewState *m_ViewState;
  double m_DocMultiple;

public:
  int GetPageCount() { return m_kit->GetPageCount(); }
  QSize GetActruallyPageSize(int nPageNum) { return m_kit->GetActruallyPageSize(nPageNum); } 
  QImage GetActruallyPageImage(int nPageNum) { return m_kit->GetActruallyPageSize(nPageNum); } 
  QSize GetPageSize(int nPageNum) { return m_kit->GetPageSize(nPageNum) }
  QImage GetPageImage(int nPageNum) { return m_kit->GetPageImage(nPageNum); }

  QDomDocument* GetTOC() { return m_kit->GetTOC(); }

public:
  int GetActruallyPageHighCount();
  int GetPageHightCount();
  int GetActruallyMaxPageWidth();
  int GetMaxPageWidth();
  int GetCurPageNum() { return m_ViewState->GetCurPageNum(); }
  void GotoPage(int nPageNum) { return m_ViewState->GotoPage(nPageNum);} 

public:
  ChlidViewer *GetChildViewer() { return m_ChildViewer; }
  void SetDocMultiple(double docMultiple);

public:
  void RenderPages(QPainter *paint);
};


#ENDIF // VIEWMODEL_H
