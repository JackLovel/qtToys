#include <QWheelEvent>
#include <QFontDialog>

#include "editor.h"

Editor::Editor(QWidget *parent)
    : QTextEdit(parent)
{

}

Editor::~Editor()
{

}

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
    QTextEdit::copy();
}

void Editor::cut()
{
    QTextEdit::cut();
}

void Editor::paste()
{
    QTextEdit::paste();
}

void Editor::undo()
{
    QTextEdit::undo();
}

void Editor::redo()
{
    QTextEdit::redo();
}
