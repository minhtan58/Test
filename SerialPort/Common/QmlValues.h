#ifndef QMLVALUES_H
#define QMLVALUES_H

#include <QObject>

#include "Defines.h"

class QmlValues : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int screenWidth      READ screenWidth    CONSTANT)
    Q_PROPERTY(int screenHeight     READ screenHeight   CONSTANT)
    Q_PROPERTY(int backgroundZ      READ backgroundZ    CONSTANT)

public:
    explicit QmlValues(QObject *parent = 0);

    int screenWidth() const;
    int screenHeight() const;
    int backgroundZ() const;

signals:

public slots:

private:
    int m_screenWidth;
    int m_screenHeight;
    int m_backgroundZ;
};

#endif // QMLVALUES_H
