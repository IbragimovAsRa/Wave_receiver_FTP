#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QResizeEvent>
#include <QFrame>
#include <QPushButton>
#include <QStatusBar>

#include "mainframe.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

signals:

private:
    MainFrame *mainFrame;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;
    Receiver *receiver;

    void Dezigner();
    void Сustomizer();
    void Connector();

private slots:
    void slotMenuWaveViewer();
    void slotMenuAbout();

};
#endif // MAINWINDOW_H
