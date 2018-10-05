#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QTimer>
#include <QProcess>

class DatabaseHandler : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseHandler(QObject *parent = 0);

signals:

public slots:
    void eventHandler(QString objectName, int eventId, QString param);

private:
    QTimer *m_timerSendDataToServer = nullptr;
    QProcess *m_process = nullptr;
};

#endif // DATABASEHANDLER_H
