#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

#include "ManagerData.h"
#include "Defines.h"

class MyTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = nullptr);
    void doConnect(QString ipAdress,int port);
    QString getData() const;

private:
    QTcpSocket *m_socket = nullptr;
    QString m_dataChange;

signals:
    void readComplete();

public slots:
    void disconnected();
    void readData();
    void senData(const QByteArray &data);
};

#endif // MYTCPSOCKET_H
