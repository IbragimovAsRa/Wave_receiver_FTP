#ifndef RECEIVER_H
#define RECEIVER_H

#define BUFFER_SIZE  8192
#define LISTENING_PORT 10002

#include <QObject>
#include <QUdpSocket>
#include <QMainWindow>
#include <iostream>
#include <QNetworkDatagram>
#include <QStatusBar>

#include "ploter.h"



class Receiver: public QObject
{
    Q_OBJECT

public:
    explicit Receiver(Ploter* ploter = nullptr, QStatusBar* statusBar = nullptr);
    ~Receiver();

public slots:
    void reader();

signals:


private:
    Ploter* ploter;
    QByteArray* buffer;
    QUdpSocket *socket;
    QStatusBar* statusBar;
    QHostAddress* sender;
    quint16* senderPort;
    int receiveDatagrams;
};

#endif // RECEIVER_H
