#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QTextEdit>

class Notepad : public QMainWindow
{
public:
    Notepad(QWidget *parent = 0);


private slots:
    void newDocument();
    void open();
    void save();
    void saveAs();
    void print();
    void exit();
    void copy();
    void cut();
    void paste();
    void undo();
    void redo();
    void selectFont();
    void setFontBold();
    void setFontUnderline();
    void setFontItalic();
    void about();


private:
    QString currentFile;           // current file name, default is empty
    QTextEdit *textEdit;           // content area

    bool boldDone = false;         // default font is not bold
    bool italicDone = false;       // default font is not italic
    bool underLineDone = false;    // default font is not underline
};

#endif // WIDGET_H
