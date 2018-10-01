#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QTimer>

#include "ManagerData.h"
#include "Defines.h"

class MySerialPort : public QObject
{
    Q_OBJECT

public:
    explicit MySerialPort(QObject *parent = nullptr);
    QString getData() const;

signals:
    void readComplete();

public slots:
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    void openSerialPort(QString portCom);
    void closeSerialPort();
    void writeData(const QByteArray &data);

private:
    QString m_dataChange;
    QSerialPort *m_serial = nullptr;
    QTimer *m_updateStatus = nullptr;
};

#endif // MYSERIALPORT_H

