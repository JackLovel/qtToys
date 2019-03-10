#include "notepad.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <qtprintsupportglobal.h>
#include <QPrintDialog>
#include <QPrinter>
#include <QFont>
#include <QFontDialog>
#include <QAction>
#include <QTextEdit>
#include <QCoreApplication>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent)
{
    textEdit = new QTextEdit;


    QPixmap newPix(":/img/new.png");
    QPixmap openPix(":/img/open.png");
    QPixmap savePix(":/img/save.png");
    QPixmap saveAsPix(":/img/save_as.png");
    QPixmap printPix(":/img/print.png");
    QPixmap copyPix(":/img/copy.png");
    QPixmap cutPix(":/img/cut.png");
    QPixmap pastePix(":/img/paste.png");
    QPixmap redoPix(":/img/edit_redo.png");
    QPixmap undoPix(":/img/edit_undo.png");
    QPixmap fontPix(":/img/font.png");
    QPixmap exitPix(":/img/exit.png");
    QPixmap fontBoldPix(":/img/bold.png");
    QPixmap underlinePix(":/img/underline.png");
    QPixmap italicPix(":/img/italic.png");
    QPixmap aboutPix(":/img/about.png");


    QAction *newAct = new QAction(newPix, "&New", this);
    QAction *openAct = new QAction(openPix, "&Open", this);
    QAction *saveAct = new QAction(savePix, "&Save", this);
    QAction *saveAsAct = new QAction(saveAsPix, "&SaveAs", this);
    QAction *printAct = new QAction(printPix, "&Print", this);
    QAction *exitAct = new QAction(exitPix, "&Exit", this);
    QAction *copyAct = new QAction(copyPix, "&Copy", this);
    QAction *cutAct = new QAction(cutPix, "&Cut", this);
    QAction *pasteAct = new QAction(pastePix, "&Paste", this);
    QAction *undoAct = new QAction(undoPix, "&Undo", this);
    QAction *redoAct = new QAction(redoPix, "&Redo", this);
    QAction *fontAct = new QAction(fontPix, "&Font", this);
    QAction *boldAct = new QAction(fontBoldPix, "&Bold", this);
    QAction *underlineAct = new QAction(underlinePix, "&Underline", this);
    QAction *fontItalicAct = new QAction(italicPix, "&FontItalic", this);
    QAction *aboutAct = new QAction(aboutPix, "&about", this);


    QMenu *fileMenu = menuBar()->addMenu(tr("&file"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);


    QMenu *editMenu = menuBar()->addMenu(tr("&edit"));
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(undoAct);
    fileMenu->addAction(redoAct);
    editMenu->addAction(fontAct);

    QToolBar *toolbar = addToolBar(tr("main toolbar"));
    toolbar->addAction(newAct);
    toolbar->addAction(openAct);
    toolbar->addAction(saveAct);
    toolbar->addAction(saveAsAct);
    toolbar->addAction(printAct);
    toolbar->addSeparator();
    toolbar->addAction(copyAct);
    toolbar->addAction(cutAct);
    toolbar->addAction(pasteAct);
    toolbar->addAction(undoAct);
    toolbar->addAction(redoAct);
    toolbar->addAction(fontAct);
    toolbar->addSeparator();
    toolbar->addAction(exitAct);
    toolbar->addAction(underlineAct);
    toolbar->addAction(fontItalicAct);
    toolbar->addAction(aboutAct);


    connect(newAct, &QAction::triggered, this, &Notepad::newDocument);
    connect(openAct, &QAction::triggered, this, &Notepad::open);
    connect(saveAct, &QAction::triggered, this, &Notepad::save);
    connect(saveAsAct, &QAction::triggered, this, &Notepad::saveAs);
    connect(printAct, &QAction::triggered, this, &Notepad::print);
    connect(exitAct, &QAction::triggered, this, &Notepad::exit);
    connect(copyAct, &QAction::triggered, this, &Notepad::copy);
    connect(cutAct, &QAction::triggered, this, &Notepad::cut);
    connect(pasteAct, &QAction::triggered, this, &Notepad::paste);
    connect(undoAct, &QAction::triggered, this, &Notepad::undo);
    connect(redoAct, &QAction::triggered, this, &Notepad::redo);
    connect(fontAct, &QAction::triggered, this, &Notepad::selectFont);
    connect(boldAct, &QAction::triggered, this, &Notepad::setFontBold);
    connect(underlineAct, &QAction::triggered, this, &Notepad::setFontUnderline);
    connect(fontItalicAct, &QAction::triggered, this, &Notepad::setFontItalic);
    connect(aboutAct, &QAction::triggered, this, &Notepad::about);


    setCentralWidget(textEdit);
}

void Notepad::newDocument()
{
    currentFile.clear();
    textEdit->setText(QString());
}

void Notepad::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open  the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&fileName);
    QString text = in.readAll();
    textEdit->setText(text);
    file.close();
}

void Notepad::save()
{
    QString fileName;
    if (currentFile.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    }
    else
    {
        fileName = currentFile;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Can not save file:" + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = textEdit->toPlainText();
    out << text;
    file.close();
}

void Notepad::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file" + file.errorString());
        return;
    }

    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = textEdit->toPlainText();
    out << text;
    file.close();
}

void Notepad::print()
{
    QPrinter printDev;
    QPrintDialog dialog(&printDev, this);
    if (dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    textEdit->print(&printDev);
}

void Notepad::exit()
{
    QCoreApplication::quit();
}

void Notepad::copy()
{
    textEdit->copy();
}

void Notepad::cut()
{
    textEdit->cut();
}


void Notepad::paste()
{
    textEdit->paste();
}

void Notepad::undo()
{
    textEdit->undo();
}

void Notepad::redo()
{
    textEdit->redo();
}

void Notepad::selectFont()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
        textEdit->setFont(font);
}

void Notepad::setFontUnderline(bool underline)
{
    textEdit->setFontUnderline(underline);
}

void Notepad::setFontItalic(bool italic)
{
    textEdit->setFontItalic(italic);
}

void Notepad::setFontBold(bool bold)
{
    bold ? textEdit->setFontWeight(QFont::Bold) :
           textEdit->setFontWeight(QFont::Normal);
}

void Notepad::about()
{
    QMessageBox::about(this, tr("About Notepad"),
                       tr("The <b>Notepad</b> example demonstrace  how to code a basic"
                          "text editor using QtWidgets"));
}
