#include "titlebar.h"

TitleBar::TitleBar(QWidget *parent)
    :QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    QLabel *m_icon = new QLabel;
    m_icon->setPixmap(QPixmap(":/img/ico.svg").scaled(24, 24));

    m_title = new QLabel("engine-player");
    m_file_name = new QLabel("");

    layout->setMargin(0);

    layout->addWidget(m_icon);
    layout->addWidget(m_title);
    layout->addStretch();
    layout->addWidget(m_file_name);
    layout->addStretch();
}

void TitleBar::setTitleText(const QString &title)
{
    m_title->setText(title);
}

void TitleBar::setFileName(const QString &name)
{
    m_file_name->setText(name);
}
