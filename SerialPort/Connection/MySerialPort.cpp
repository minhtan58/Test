#include "MySerialPort.h"

MySerialPort::MySerialPort(QObject *parent) : QObject(parent)
{
    m_serial = new QSerialPort(this);
    m_updateStatus = new QTimer(this);

    connect(m_serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));
    connect(m_updateStatus, SIGNAL(timeout()), this, SLOT(sltUpdateStatus()), Qt::UniqueConnection);
    m_updateStatus->start(5000);
}

void MySerialPort::readData() {
   m_serial->waitForReadyRead(200);
   QByteArray data = m_serial->readAll();
   m_dataChange = QString::fromUtf8(data);
   emit readComplete();
   qDebug() << "rev: " << data;
}

void MySerialPort::openSerialPort(QString portCom) {
    if(m_serial->portName() == portCom) {
        if(m_serial->isOpen()) {
            SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Connected");
            return;
        }
    }

    m_serial->setPortName(portCom);
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Connected");
        connect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));
    } else {
        SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Disconnected");
    }
}

void MySerialPort::closeSerialPort() {
    if (m_serial->isOpen())
        m_serial->close();
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

//void MySerialPort::connectSerialPort() {
//    if(m_serial->isOpen()) {
//        if(m_serial->portName() != GETDPDATA(EnumID::DP_SERIALPORT_PORTNAME)) {
//            m_serial->close();
//        } else {
//            return;
//        }
//    }

//    if(!m_serial->isOpen()) {
//        m_serial->setPortName(GETDPDATA(EnumID::DP_SERIALPORT_PORTNAME));
//        if(m_serial->open(QIODevice::ReadWrite)) {
//            qDebug() << "Connected to " << m_serial->portName().toStdString().data();
//            connect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));
//            SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "1");
//        } else {
//            qDebug() << "Can't connect to " << m_serial->portName().toStdString().data();
//            SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "0");
//        }
//    } else{
//        SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "0");
//    }
//}
