#include "BaseThreads.h"

BaseThreads::BaseThreads(QObject *parent) : QObject(parent) {
    m_serialPortHandler = new SerialPortHandlerThread(this);
    m_tcpSocketHandler = new TcpSocketHandlerThread(this);
    m_databaseHandler = new DatabaseHandlerThread(this);
}

BaseThreads::~BaseThreads() {
    m_serialPortHandler->quit();
    m_tcpSocketHandler->quit();
    m_databaseHandler->quit();
}

void BaseThreads::start() {
    m_serialPortHandler->start();
    m_tcpSocketHandler->start();
    m_databaseHandler->start();
}
