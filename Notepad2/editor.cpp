#include "editor.h"
#include <QWheelEvent>
#include <QFontDialog>

Editor::Editor(QWidget *parent)
    : QTextEdit(parent)
{

}

// Editor::~Editor() {}

void Editor::wheelEvent(QWheelEvent *event)
{
        if (event->delta() > 0)
        {
            this->zoomIn();     // enlarge
        }
        else
        {
            this->zoomOut();    // narrow
        }
}


void Editor::copy()
{
    this->copy();
}

void Editor::cut()
{
    this->cut();
}

void Editor::paste()
{
    this->paste();
}

void Editor::undo()
{
    this->undo();
}

void Editor::redo()
{
    this->redo();
}

//void Editor::selectFont()
//{
//    bool fontSelected;
//    QFont font = QFontDialog::getFont(&fontSelected, this);
//    if (fontSelected)
//        this->setFont(font);
//}

//void Editor::setFontUnderline()
//{
//    if (!underLineDone)
//    {
//        underLineDone = true;
//        this->setFontUnderline(true);
//    }
//    else
//    {
//        underLineDone = false;
//        this->setFontUnderline(false);
//    }
//}

//void Editor::setFontItalic()
//{
//    if (!italicDone)
//    {
//        this->setFontItalic(true);
//        italicDone = true;
//    }
//    else
//    {   this->setFontItalic(false);
//        italicDone = false;
//    }
//}

//void Editor::setFontBold()
//{
//    if (!boldDone)
//    {
//        this->setFontWeight(QFont::Bold);
//        boldDone = true;
//    }
//    else
//    {
//        this->setFontWeight(QFont::Normal);
//        boldDone = false;
//    }
//}



