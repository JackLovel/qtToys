#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>

class Editor : public QTextEdit
{
    Q_OBJECT
public:
    Editor(QWidget *parent = 0);
    ~Editor();

protected:
    void wheelEvent(QWheelEvent * event);

public slots:
    void copy();
    void cut();
    void paste();
    void undo();
    void redo();
};

#endif // EDITOR_H
