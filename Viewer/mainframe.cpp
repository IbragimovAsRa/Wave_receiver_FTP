#include "mainframe.h"


MainFrame::MainFrame(QStatusBar *statusBar):statusBar{statusBar}
{
    waveViewerFrame = new WaveViewerFrame(statusBar);
    aboutFrame = new AboutFrame;

    aboutFrame->setParent(this);
    waveViewerFrame->setParent(this);
}

MainFrame::~MainFrame()
{
    delete waveViewerFrame;
    delete aboutFrame;
}

