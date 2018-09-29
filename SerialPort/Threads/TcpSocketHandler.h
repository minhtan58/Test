#ifndef TCPSOCKETHANDLER_H
#define TCPSOCKETHANDLER_H

#include <QObject>

class TcpSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocketHandler(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TCPSOCKETHANDLER_H