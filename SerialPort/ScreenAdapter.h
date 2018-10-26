#ifndef SCREENADAPTER_H
#define SCREENADAPTER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlProperty>
#include <QQmlContext>
#include <QQuickItem>

#include "Enum.h"
#include "Defines.h"
#include "ManagerData.h"
#include "MyHistoryData.h"

class ScreenAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ScreenAdapter(QObject *container, QObject *parent = nullptr);
    ~ScreenAdapter();

    void createScreen();
    int getCurrentScreen();
    void setScreenId(int screenId);
    void initAppData();

private:
    int m_screenId;
    QQmlApplicationEngine *m_qmlAppEngine = nullptr;
    QObject* m_screenContainer = nullptr;
    QObject* m_screenView = nullptr;
    HistoryDataModel *m_listHistory = nullptr;

signals:

public slots:
    void updateAppdata(int dpid);
    void eventHandler(QString objectName, int eventId, QString param);

};

#endif // SCREENADAPTER_H
