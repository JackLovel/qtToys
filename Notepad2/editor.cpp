#include <QWheelEvent>
#include <QFontDialog>
#include <QTextStream>
#include <QFile>
#include <QDebug>

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

void Editor::setText(const QString text)
{
    QTextEdit::setText(text);
}

void Editor::open(const QString fileName)
{

    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString text = file.readAll();
    setText(text);

    file.close();
}

void Editor::save(const QString fileName)
{
    QString content = this->toPlainText();

    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    file.write(content.toUtf8());
    file.close();
}

void Editor::saveAs(const QString fileName)
{
    QString content = this->toPlainText();

    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    file.write(content.toUtf8());
    file.close();
}
