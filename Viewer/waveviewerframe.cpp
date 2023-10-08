#include "waveviewerframe.h"

WaveViewerFrame::WaveViewerFrame(QStatusBar* statusBar):statusBar{statusBar},isStart{false}
{
    Designer();
    Сustomizer();
    Connector();
}

WaveViewerFrame::~WaveViewerFrame()
{
    delete ploter;
    if (isStart) {
        delete receiver;
    }
    delete startButton;
    delete stopButton;
}

void WaveViewerFrame::Designer()
{
    ploter = new Ploter(this);
    startButton = new QPushButton(this);
    stopButton = new QPushButton(this);
}

void WaveViewerFrame::Сustomizer()
{
    startButton->setText("Старт");
    stopButton->setText("Стоп");

    startButton->setGeometry(820,625,65,30);
    stopButton->setGeometry(890,625,65,30);
}

void WaveViewerFrame::Connector()
{
    connect(this->startButton, SIGNAL(clicked(bool)), this, SLOT(slotStart()));
    connect(this->stopButton, SIGNAL(clicked(bool)), this, SLOT(slotStop()));
}

void WaveViewerFrame::slotStart()
{
    if (!isStart)
    {
        receiver = new Receiver(ploter, statusBar);
        isStart = true;
    }
}

void WaveViewerFrame::slotStop()
{
    if (isStart)
    {
        delete receiver;
        isStart = false;
    }
}

