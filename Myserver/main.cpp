#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QDebug>

#include "Myserver.h"
#include "MyThread.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Myserver server;
    server.startServer();

    return app.exec();
}
