#include "TaskBarAdapter.h"

TaskBarAdapter::TaskBarAdapter(QQuickItem *container, QObject *parent)
    : QObject(parent)
{
    m_tasbarContakiner = container;
    m_taskBarView = qvariant_cast<QObject*>(m_tasbarContakiner->property("item"));
}

void TaskBarAdapter::initAppData()
{
    m_taskBarView->setProperty("stationId",      QVariant::fromValue(GETDPDATA(EnumID::DP_GENERAL_STATION_ID)));
    m_taskBarView->setProperty("stationName",    QVariant::fromValue(GETDPDATA(EnumID::DP_GENERAL_STATION_NAME)));
    m_taskBarView->setProperty("systemDate",     QVariant::fromValue(GETDPDATA(EnumID::DP_DATE)));
    m_taskBarView->setProperty("systemTime",     QVariant::fromValue(GETDPDATA(EnumID::DP_TIME)));
}

void TaskBarAdapter::updateAppData(int dpid)
{
    QString data = GETDPDATA(dpid);
    switch (dpid) {
    case EnumID::DP_DATE: {
        m_taskBarView->setProperty("systemDate", QVariant::fromValue(data));
        break;
    }
    case EnumID::DP_TIME:{
        m_taskBarView->setProperty("systemTime", QVariant::fromValue(data));
        break;
    }
    case EnumID::DP_GENERAL_STATION_NAME: {
        m_taskBarView->setProperty("stationName", QVariant::fromValue(data));
        break;
    }
    case EnumID::DP_STATUS_ALARM_ON_COUNT: {
        m_taskBarView->setProperty("alarmCount", QVariant::fromValue(data));
        break;
    }
    default:
        break;
    }
}
