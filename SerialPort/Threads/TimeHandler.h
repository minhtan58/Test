#ifndef TIMEHANDLER_H
#define TIMEHANDLER_H

#include <QObject>

class TimeHandler : public QObject
{
    Q_OBJECT
public:
    explicit TimeHandler(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TIMEHANDLER_H
