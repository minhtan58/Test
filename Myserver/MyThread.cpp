#include "MyThread.h"

MyThread::MyThread(int id, QObject *parent) : QThread(parent)
{
    this->socketDiscritor = id;
}

void MyThread::run() {
    qDebug() << socketDiscritor << "Start";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDiscritor)){
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()), Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()), Qt::DirectConnection);

    qDebug() << socketDiscritor << "Client Connected";
    exec();
}

void MyThread::readyRead() {
    QByteArray data = socket->readAll();
    qDebug() << socketDiscritor << "Data in : " << data;
    socket->write(data);
}

void MyThread::disconnected() {
    qDebug() << socketDiscritor << "Disconneted: ";
    socket->deleteLater();
    exit(0);
}
