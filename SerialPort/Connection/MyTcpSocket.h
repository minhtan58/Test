#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class MyTcpSocket : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
public:
    explicit MyTcpSocket(QObject *parent = nullptr);
    void doConnect(QString ipAdress,int port);
    QString getData() const;

private:
    QTcpSocket *m_tcpSocket = nullptr;
    QString m_dataChange;

signals:
    void readComplete();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void senData(const QByteArray &data);
    void setMessage(const QString &m);
};

#endif // MYTCPSOCKET_H
