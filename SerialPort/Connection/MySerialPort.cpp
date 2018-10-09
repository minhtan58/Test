#include "MySerialPort.h"

MySerialPort::MySerialPort(QObject *parent) : QObject(parent)
{
    m_serial = new QSerialPort(this);

    connect(m_serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));
}

void MySerialPort::openSerialPort(QString portCom) {
    if(m_serial->isOpen()) {
        closeSerialPort();
        return;
    }

    m_serial->setPortName(portCom);
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Disconnected");
        connect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));
    } else {
        SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Connect");
    }
}

void MySerialPort::closeSerialPort() {
    if (m_serial->isOpen())
        m_serial->close();
    SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Connect");
}

void MySerialPort::readData() {
   m_serial->waitForReadyRead(200);
   QByteArray data = m_serial->readAll();
   m_dataChange = QString::fromUtf8(data);
   emit readComplete();
   qDebug() << "rev: " << data;
}

void MySerialPort::writeData(const QByteArray &data) {
    m_serial->write(data);
}

QString MySerialPort::getData() const {
    return m_dataChange;
}

void MySerialPort::handleError(QSerialPort::SerialPortError error) {
    if (error == QSerialPort::ResourceError) {
        closeSerialPort();
    }
}
