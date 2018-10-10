#include "Myserver.h"

Myserver::Myserver(QObject *parent) : QTcpServer(parent)
{

}

void Myserver::startServer()
{
    if(!this->listen(QHostAddress::Any,1234)) {
       qDebug() << "Could not start server";
    } else {
       qDebug() << "Listening...";
    }
}

void Myserver::incomingConnection(int socketDiscritor)
{
    qDebug() << socketDiscritor << "Connecting...";
    MyThread * thread = new MyThread(socketDiscritor,this);
    connect(thread,SIGNAL(finished()),this,SLOT(deleteLater()));
    thread->start();
}
