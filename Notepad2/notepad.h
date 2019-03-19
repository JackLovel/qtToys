#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include "editor.h"

class Notepad : public QMainWindow
{
public:
    Notepad(QWidget *parent = 0);
    ~Notepad();

private slots:
    void newDocument();
    void open();
    void save();
    void saveAs();
    void print();
    void exit();
//    void copy();
//    void cut();
//    void paste();
//    void undo();
//    void redo();
    void selectFont();
    void setFontBold();
    void setFontUnderline();
    void setFontItalic();
    void about();

    //QString readJson(const QString &fileName, const QString &key);
    //QString readJson(const QString key);

private:
    void createActions();
    void createMenus();
    void createToolBars();

    QString currentFile;           // current file name, default is empty
    Editor *textEdit;           // content area

    bool boldDone = false;         // default font is not bold
    bool italicDone = false;       // default font is not italic
    bool underLineDone = false;    // default font is not underline

    void settingDialog();
};

#endif // WIDGET_H
