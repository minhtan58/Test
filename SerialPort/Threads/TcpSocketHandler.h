#ifndef TCPSOCKETHANDLER_H
#define TCPSOCKETHANDLER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QTimer>
#include <QDateTime>
#include <QProcess>

#include "UIBridge.h"

class TcpSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocketHandler(QObject *parent = nullptr);
    ~TcpSocketHandler();

signals:

public slots:
    void eventHandler(QString objectName, int eventId, QString param);
    void sendDataToServer();
    void updateConnectionState();

private:
    QTcpSocket *m_tcpSocket = nullptr;
    QTimer *m_updateStatus = nullptr;

    void updateTime();
    void testConnection(QString serverIP, int serverPort);
};

class TcpSocketHandlerThread : public QThread
{
    Q_OBJECT
public:
    TcpSocketHandlerThread(QObject *parent = nullptr) : QThread(parent) {}

protected:
    void run() {
        TcpSocketHandlerThread handler;
        connect(UIBridge::getInstance(), SIGNAL(hmiEvent(QString,int,QString)), &handler, SLOT(eventHandler(QString,int,QString)));
        exec();
    }
};

#endif // TCPSOCKETHANDLER_H
