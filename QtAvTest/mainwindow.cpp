#include "mainwindow.h"

#include <QPushButton>
#include <QSlider>
#include <QLayout>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow()
{
    initUI();
    createConnection();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUI()
{
    m_player = new AVPlayer(this);
    m_vo = new VideoOutput(this);

    if (!m_vo->widget()) {
        QMessageBox::warning(0, tr("QtAV error"), tr("Can noto create video renderer"));
        return;
    }
    m_player->setRenderer(m_vo);

    m_slider = new QSlider();
    m_slider->setOrientation(Qt::Horizontal);
    m_unit = 1;   // set slider flash Interval

    m_openBtn = new QPushButton(tr("打开"));
    m_playBtn = new QPushButton(tr("播放/暂停"));
    m_stopBtn = new QPushButton(tr("关闭"));

    buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(m_openBtn);
    buttonLayout->addWidget(m_playBtn);
    buttonLayout->addWidget(m_stopBtn);

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_vo->widget());
    mainLayout->addWidget(m_slider);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("QtAV simple player example"));
}

void MainWindow::createConnection()
{
    connect(m_slider, SIGNAL(sliderMoved(int)), SLOT(seekByslider(int)));
    connect(m_slider, SIGNAL(sliderPressed()), SLOT(seekByslider()));
    connect(m_player, SIGNAL(positionChanged(qint64)), SLOT(updateSlider(qint64)));
    connect(m_player, SIGNAL(started()), SLOT(updateSlider()));
    connect(m_player, SIGNAL(notifyIntervalChanged()), SLOT(updateSlider()));
    connect(m_openBtn, SIGNAL(clicked()), SLOT(openMeida()));
    connect(m_playBtn, SIGNAL(clicked()), SLOT(playPause()));
    connect(m_stopBtn, SIGNAL(clicked()), m_player, SLOT(stop()));
}

void MainWindow::openMeida()
{
    QString file = QFileDialog::getOpenFileName(0, tr("Open a video"));
    if (file.isEmpty())
        return;

    m_player->play(file);
}

void MainWindow::seekByslider(int value)
{
    if (!m_player->isPlaying())
        return;

    m_player->seek(qint64(value * m_unit));
}

void MainWindow::seekByslider()
{
    seekByslider(m_slider->value());
}

void MainWindow::playPause()
{
    if (!m_player->isPlaying()) {
        m_player->play();
        return;
    }

    m_player->pause(!m_player->isPaused());
}

void MainWindow::updateSlider(qint64 value)
{
    m_slider->setRange(0, int(m_player->duration() / m_unit));
    m_slider->setValue(int(value / m_unit));
}

void MainWindow::updateSlider()
{
    updateSlider(m_player->position());
}

void MainWindow::updateSliderUnit()
{
    m_unit = m_player->notifyInterval();
    updateSlider();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();

    if (key == Qt::Key_P) {
       m_player->togglePause();
    } else if (key == Qt::Key_Q) {
        m_player->seekBackward();
    } else if (key == Qt::Key_E) {
        m_player->seekForward();
    }
}
