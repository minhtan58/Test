#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>

#include "MyThread.h"

class Myserver : public QTcpServer
{
    Q_OBJECT
public:
    explicit Myserver(QObject *parent = nullptr);
    void startServer();

signals:

public slots:

protected:
    void incomingConnection(int socketDescriptor);
};

#endif // MYSERVER_H
