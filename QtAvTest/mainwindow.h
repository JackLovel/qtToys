#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtAV>
#include <QWidget>
#include <QtAVWidgets>
#include <QVBoxLayout>

class QSlider;
class QPushButton;

using namespace QtAV;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

public slots:
    void openMeida();
    void seekByslider(int value);
    void seekByslider();
    void playPause();

private slots:
    void updateSlider(qint64 value);
    void updateSlider();
    void updateSliderUnit();

private:
    void initUI();
    void createConnection();

    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;

    QtAV::VideoOutput *m_vo;
    QtAV::AVPlayer *m_player;
    QSlider *m_slider;
    QPushButton *m_openBtn;
    QPushButton *m_playBtn;
    QPushButton *m_stopBtn;
    int m_unit;
};

#endif // MAINWINDOW_H
