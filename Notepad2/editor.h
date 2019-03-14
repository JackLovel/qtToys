#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>

class Editor : public QTextEdit
{
    Q_OBJECT
public:
    Editor(QWidget *parent = 0);
    //~Editor();

protected:
    void wheelEvent(QWheelEvent * event);

public slots:
    void copy();
    void cut();
    void paste();
    void undo();
    void redo();
//    void selectFont();
//    void setFontBold();
//    void setFontUnderline();
//    void setFontItalic();

private:
//    bool boldDone = false;         // default font is not bold
//    bool italicDone = false;       // default font is not italic
//    bool underLineDone = false;    // default font is not underline
};

#endif // EDITOR_H
