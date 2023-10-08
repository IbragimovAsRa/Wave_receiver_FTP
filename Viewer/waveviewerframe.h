#ifndef WAVEVIEWERFRAME_H
#define WAVEVIEWERFRAME_H


#include <QMainWindow>
#include <QMenuBar>
#include <QFrame>
#include <QPushButton>

#include "receiver.h"

class WaveViewerFrame : public QFrame
{
    Q_OBJECT
public:
    explicit WaveViewerFrame(QStatusBar *statusBar = nullptr);
    ~WaveViewerFrame();

private:
    Receiver* receiver;
    Ploter* ploter;
    QStatusBar* statusBar;
    QPushButton* startButton;
    QPushButton* stopButton;
    bool isStart;

    void Designer();
    void Сustomizer();
    void Connector();

private slots:
    void slotStart();
    void slotStop();
};

#endif // WAVEVIEWERFRAME_H
