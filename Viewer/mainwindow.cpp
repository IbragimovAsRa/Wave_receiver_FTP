#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Dezigner();
    Сustomizer();
    Connector();
}

MainWindow::~MainWindow()
{
    delete statusBar;
    delete mainFrame;
    delete menuBar;
    delete menu;
}

void MainWindow::Dezigner()
{
    statusBar = new QStatusBar;
    mainFrame = new MainFrame(statusBar);
    menuBar = new QMenuBar;
    menu = new QMenu;
}

void MainWindow::Сustomizer()
{
    setFixedSize(1000,700);
    setCentralWidget(mainFrame);
    setMenuBar(menuBar);
    setStatusBar(statusBar);
    menuBar->addMenu(menu);

    menu->setTitle("Tools");
    menuBar->setStyleSheet("background-color: lightblue;");
    statusBar->setStyleSheet("background-color: lightblue;");
}

void MainWindow::Connector()
{
    menu->addAction("Wave Viewer", this, SLOT(slotMenuWaveViewer()));
    menu->addAction("About", this, SLOT(slotMenuAbout()));
}

void MainWindow::slotMenuWaveViewer()
{
    mainFrame->aboutFrame->hide();
    mainFrame->waveViewerFrame->show();
}

void MainWindow::slotMenuAbout()
{
    mainFrame->aboutFrame->show();
    mainFrame->waveViewerFrame->hide();
}



