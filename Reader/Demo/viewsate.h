#ifndef VIEWSATE_H
#define VIEWSATE_H

#include <QPainter>
#include <QScrollBar>

#include "IChlidViewer.h"

class ViewModel;
class ChlidViewer;
class DocWidget;

class ViewSate
{
public:
  ViewSate() {};
  virtual ~ViewSate() {};

public:
  virtual void RenderPages(QPainter *paint = 0);
  virtual int GetCurPageNum() = 0;
  virtual void GotoPage(int nPageNum) = 0;
  
};

#endif // VIEWSATE_H
