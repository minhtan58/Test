#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QObject>
#include <QQmlContext>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int id, QObject *parent = nullptr);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    int socketDiscritor;
};
#endif // MYTHREAD_H
