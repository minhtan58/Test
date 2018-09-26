#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "DataLogger.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    DataLogger logger;
    logger.exec();

    return app.exec();
}
