#ifndef EDITORS_H
#define EDITORS_H

#include <QMainWindow>

#include <QAction>
#include <QMenu>
#include <QPlainTextEdit>

class Editors : public QMainWindow
{
    Q_OBJECT

public:
    Editors();
    void loadFile(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void documentWasModified();

private:
    void createActions();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QPlainTextEdit *textEdit;
    QString currentFileName;
};

#endif // EDITORS_H
