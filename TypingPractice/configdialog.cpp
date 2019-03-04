#include "configdialog.h"
#include "settingpage.h"
#include <QAbstractButton>
#include <QHBoxLayout>
#include <QPushButton>
#include <QIcon>

ConfigDialog::ConfigDialog(QWidget *parent)
    : QDialog(parent)
{
    contentsWidget = new QListWidget;
    contentsWidget->setViewMode(QListView::IconMode);
    contentsWidget->setIconSize(QSize(96, 84));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setMaximumWidth(128);
    //contentsWidget->setMaximumWidth(100);
    //contentsWidget->setMinimumHeight(100);
    contentsWidget->setSpacing(12);

    pagesWidget = new QStackedWidget;
    pagesWidget->addWidget(new BasicConfigPage);
    pagesWidget->addWidget(new ScorePage);
    pagesWidget->addWidget(new ShortcutPage);
    pagesWidget->addWidget(new TypeingConfigPage);
    pagesWidget->addWidget(new AdvancedConfigPage);

    QPushButton *closeButton = new QPushButton(tr("Close"));
    createIcons();
    contentsWidget->setCurrentRow(0);

    connect(closeButton, &QAbstractButton::clicked, this, &QWidget::close);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(contentsWidget);
    hbox->addWidget(pagesWidget, 1);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(closeButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(hbox);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    setLayout(mainLayout);

    setWindowTitle(tr("Config Dialog"));
}


void ConfigDialog::createIcons()
{
    QListWidgetItem *configButton = new QListWidgetItem(contentsWidget);
    configButton->setIcon(QIcon(":/img/copy.png"));
    configButton->setText(tr("Configure"));
    configButton->setTextAlignment(Qt::AlignHCenter);
    configButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *scoreButton = new QListWidgetItem(contentsWidget);
    scoreButton->setIcon(QIcon(":/img/cut.png"));
    scoreButton->setText(tr("score"));
    scoreButton->setTextAlignment(Qt::AlignHCenter);
    scoreButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


    QListWidgetItem *shortCutButton = new QListWidgetItem(contentsWidget);
    shortCutButton->setIcon(QIcon(":/img/new.png"));
    shortCutButton->setText(tr("Shortcut"));
    shortCutButton->setTextAlignment(Qt::AlignHCenter);
    shortCutButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


    QListWidgetItem *typeingButton = new QListWidgetItem(contentsWidget);
    typeingButton->setIcon(QIcon(":/img/paste.png"));
    typeingButton->setText(tr("typeing"));
    typeingButton->setTextAlignment(Qt::AlignHCenter);
    typeingButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *advanceButton = new QListWidgetItem(contentsWidget);
    advanceButton->setIcon(QIcon(":/img/save.png"));
    advanceButton->setText(tr("advance"));
    advanceButton->setTextAlignment(Qt::AlignHCenter);
    advanceButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(contentsWidget, &QListWidget::currentItemChanged,
            this, &ConfigDialog::changePage);
}

void ConfigDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
    {
        current = previous;
    }

    pagesWidget->setCurrentIndex(contentsWidget->row(current));
}


















