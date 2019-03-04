#include "mainwindow.h"
#include "setting.h"
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QToolBar>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QSplitter>
#include <QStatusBar>
#include <QTableWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QAction *quit = new QAction("&Quit", this);
    QAction *setting = new QAction("setting", this);

    QMenu *menu = menuBar()->addMenu("&menu");
    menu->addAction(quit);
    menu->addAction(setting);

    QMenu *changeGroupMenu = menuBar()->addMenu("chageGoup");
    QMenu *modeMenu = menuBar()->addMenu("mode");

    QPushButton *speedButton = new QPushButton("spend: 21", this);
    QPushButton *keyButton = new QPushButton("enterKey: 7.1", this);
    QToolBar *toolbar = addToolBar("main toolbar");


    toolbar->addWidget(speedButton);
    toolbar->addWidget(keyButton);


    QTextEdit *outputArea = new QTextEdit;
    QTextEdit *inputArea = new QTextEdit;
    QTableWidget *table = new QTableWidget(10, 10, this);

    QSplitter *splitter = new QSplitter(Qt::Vertical);
    splitter->addWidget(outputArea);
    splitter->addWidget(inputArea);
    splitter->addWidget(table);

    setCentralWidget(splitter);

    //statusBar()->showMessage("this is status bar (^_^)~~~");
    QLabel *qqGroup = new QLabel("QQ group: 210172@qq.com", this);
    statusBar()->addWidget(qqGroup);

    QLabel *segmentNumber = new QLabel("segment number: 4", this);
    statusBar()->addWidget(segmentNumber);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    connect(setting, &QAction::triggered, this, &MainWindow::openSetting);
}

void MainWindow::openSetting()
{
    Setting *settingDialog = new Setting(this);

    settingDialog->exec();
}

