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

void Editor::setText(const QString &text)
{
    QTextEdit::setText(text);
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

void Editor::setFontUnderline()
{
    if (!underLineDone)
    {
        underLineDone = true;
    }
    else
    {
        underLineDone = false;
    }

    QTextEdit::setFontUnderline(underLineDone);
}

void Editor::setFontItalic()
{
    if (!italicDone)
    {
        italicDone = true;
    }
    else
    {
        italicDone = false;
    }

    QTextEdit::setFontItalic(italicDone);
}


void Editor::setFontBold()
{
    if (!boldDone)
    {
        boldDone = true;
    }
    else
    {
        boldDone = false;
    }

    qint32 font = boldDone ? QFont::Bold : QFont::Normal;
    QTextEdit::setFontWeight(font);
}
