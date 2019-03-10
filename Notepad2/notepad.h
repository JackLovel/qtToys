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
    void setFontBold(bool bold);
    void setFontUnderline(bool underline);
    void setFontItalic(bool italic);
    void about();
private:
    QString currentFile;
    QTextEdit *textEdit;
};

#endif // WIDGET_H
