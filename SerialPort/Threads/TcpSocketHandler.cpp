#include "TcpSocketHandler.h"

TcpSocketHandler::TcpSocketHandler(QObject *parent) : QObject(parent)
{
    m_tcpSocket = new MyTcpSocket(this);
    connect(m_tcpSocket, SIGNAL(readComplete()), this, SLOT(readData()), Qt::UniqueConnection);
    SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Connect");
}

TcpSocketHandler::~TcpSocketHandler() {
    if (m_tcpSocket && m_tcpSocket->state() == QTcpSocket::ConnectedState) {
        m_tcpSocket->disconnectFromHost();
        m_tcpSocket->waitForDisconnected();
    }
}

void TcpSocketHandler::readData() {
    QString value = m_tcpSocket->getData();
    SETDPDATA(EnumID::DP_NETWORK, value);
}

void TcpSocketHandler::eventHandler(QString objectName, int eventId, QString param) {
    Q_UNUSED(objectName)
    switch (eventId) {
    case EnumID::HMI_TEST_CONNECTIONS_NETWORK: {
        SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Connecting...");
        m_tcpSocket->doConnect(param);
        break;
    }
    case EnumID::HMI_SEND_DATA_NETWORK: {
        m_tcpSocket->senData(param.toUtf8());
        break;
    }
    default:
        break;
    }
}


