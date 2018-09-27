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
    QQmlApplicationEngine *m_qmAppEngine = nullptr;
    QObject* m_screenContainer = nullptr;
    QObject* m_screenView = nullptr;

signals:

public slots:
    void updateAppdata(int dpid);

};

#endif // SCREENADAPTER_H
