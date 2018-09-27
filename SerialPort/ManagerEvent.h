#ifndef MANAGEREVENT_H
#define MANAGEREVENT_H

#include <QObject>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "UIBridge.h"
#include "MySerialPort.h"
#include "MyTcpSocket.h"
#include "Enum.h"
#include "ScreenAdapter.h"
#include "BaseThreads.h"
#include "SerialPortHandler.h"

class ManagerEvent : public QObject
{
    Q_OBJECT
public:
    explicit ManagerEvent(QObject *parent = 0);
    QQuickItem *m_screenContainer = nullptr;
    void sendEvent(int EnumID, QString params);
    void initWindow();

private:
    QQmlApplicationEngine m_engine;
    UIBridge *m_uiBridge;
    MySerialPort *m_mySerialPort = nullptr;
    MyTcpSocket *m_myTcpSocket = nullptr;
    ScreenAdapter *m_screenAdapter = nullptr;
    BaseThreads *m_baseThreads = nullptr;

    void showScreen(int screenId);
    void showOverlay(int overlayId, int timeout, int layer = OVERLAY, QString message = "");
    void hideOverlay();

signals:

public slots:
    void hmiHandle(QString objectName, int EnumID, QString param);
};

#endif // MANAGEREVENT_H
