#include "MyTcpSocket.h"

MyTcpSocket::MyTcpSocket(QObject *parent) : QObject(parent)
{
    m_tcpSocket = new QTcpSocket(this);
}

void MyTcpSocket::doConnect(QString ipAdress,int port)
{
    qDebug() << "Connecting...";
    if (m_tcpSocket->state() != QTcpSocket::ConnectedState) {
        qDebug() << "Reconnect to host";
        m_tcpSocket->connectToHost(ipAdress, port);
        m_tcpSocket->waitForConnected(1000);
    }
}

void MyTcpSocket::disconnected() {
    qDebug() << "Disconnected";
    m_tcpSocket->disconnectFromHost();
}

QString MyTcpSocket::getData() const {
    return m_dataChange;
}

void MyTcpSocket::readyRead(){
    QByteArray data = m_tcpSocket->readAll();
    m_dataChange = QString::fromUtf8(data);
    qDebug() << data;
    emit readComplete();
}
