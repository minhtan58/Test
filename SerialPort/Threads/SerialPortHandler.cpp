#include "SerialPortHandler.h"

SerialPortHandler::SerialPortHandler(QObject *parent) : QObject(parent) {
    m_serialPort = new MySerialPort();
    connect(m_serialPort, SIGNAL(readComplete()), this, SLOT(setData()), Qt::UniqueConnection);
    SETDPDATA(EnumID::DP_SERIALPORT_STATUS, "Connect");
}

//SerialPortHandler::~SerialPortHandler() {
//}

void SerialPortHandler::setData() {
    QString value = m_serialPort->getData();
    SETDPDATA(EnumID::DP_PORTCOM, value);
    qDebug() << value;
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
        m_serialPort->writeData(param.toUtf8());
        break;
    }
    default:
        break;
    }
}
