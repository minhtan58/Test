#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>

class MyDatabase : public QObject
{
    Q_OBJECT
public:
    explicit MyDatabase(QObject *parent = 0);

signals:

public slots:
};

#endif // MYDATABASE_H