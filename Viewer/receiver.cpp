#include "receiver.h"


Receiver::Receiver(Ploter *ploter,QStatusBar* statusBar):ploter{ploter},statusBar{statusBar}
{
    receiveDatagrams = 0;
    buffer = new QByteArray;
    sender = new QHostAddress;
    senderPort = new quint16;
    socket = new QUdpSocket(this);

    buffer->resize(BUFFER_SIZE);

    socket->bind(QHostAddress::LocalHost, LISTENING_PORT);

    connect(socket, &QUdpSocket::readyRead,
            this, &Receiver::reader);
}

Receiver::~Receiver()
{
    delete buffer;
    delete sender;
    delete senderPort;
    delete socket;
}

void Receiver::reader() {
    while (socket->hasPendingDatagrams()) {
        receiveDatagrams++;
        statusBar->showMessage("Принято пакетов: "+ QString::number(receiveDatagrams));
        socket->readDatagram(buffer->data(), BUFFER_SIZE, sender, senderPort);
        ploter->plot(reinterpret_cast<short *>(buffer->data()+1));
    }
}
