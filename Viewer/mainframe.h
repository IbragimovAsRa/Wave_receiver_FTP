#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QFrame>
#include <QMainWindow>
#include <QMenuBar>
#include <QResizeEvent>
#include <QFrame>
#include <QPushButton>

#include "waveviewerframe.h"
#include "aboutframe.h"

class MainFrame : public QFrame
{
    Q_OBJECT
public:
    explicit MainFrame(QStatusBar *statusBar = nullptr);
    ~MainFrame();

    WaveViewerFrame *waveViewerFrame;
    AboutFrame *aboutFrame;
    QStatusBar *statusBar;
};

#endif // MAINFRAME_H
