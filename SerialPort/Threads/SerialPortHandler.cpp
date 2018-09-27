#include "SerialPortHandler.h"

SerialPortHandler::SerialPortHandler(QObject *parent) : QObject(parent)
{
    m_serialPort = new MySerialPort();
    connect(m_serialPort, SIGNAL(readComplete()), this, SLOT(readDataType()), Qt::UniqueConnection);
}

void SerialPortHandler::readDataType() {
    readData(EnumID::DP_FROM_PORTCOM);
    readData(EnumID::DP_FROM_NETWORK);
    qDebug() << "Okq";
}

void SerialPortHandler::readData(int dpId) {
    QString value = m_serialPort->getData();
    qDebug() << value;
    switch (dpId) {
    case EnumID::DP_FROM_PORTCOM : {
        SETDPDATA(EnumID::DP_PORTCOM, value);
        qDebug() << "OK-1";
        break;
    }

    case EnumID::DP_FROM_NETWORK : {
        SETDPDATA(EnumID::DP_NETWORK, value);
        qDebug() << "OK-2";
        break;
    }

    default:
        break;
    }
}

void SerialPortHandler::eventHandler(QString objectName, int eventId, QString param) {
    Q_UNUSED(objectName)
    switch (eventId) {
    case EnumID::HMI_TEST_CONNECTIONS_SERIALPORT: {
        SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Connecting...");
        m_serialPort->openSerialPort(param);
        break;
    }
    case EnumID::HMI_SEND_DATA_SERIALPORT: {
        m_serialPort->closeSerialPort();
        break;
    }
    default:
        break;
    }
}
