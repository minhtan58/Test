#include "BaseThreads.h"

BaseThreads::BaseThreads(QObject *parent) : QObject(parent) {
    m_serialPortHandler = new SerialPortHandlerThread(this);
    m_tcpSocketHandler = new TcpSocketHandlerThread(this);
}

BaseThreads::~BaseThreads() {
    m_serialPortHandler->quit();
    m_tcpSocketHandler->quit();
}

void BaseThreads::start() {
    m_serialPortHandler->start();
    m_tcpSocketHandler->start();
}
