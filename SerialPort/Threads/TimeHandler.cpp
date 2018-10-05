#include "TimeHandler.h"

TimeHandler::TimeHandler(QObject *parent) : QObject(parent)
{
    m_process = new QProcess(this);
}

void TimeHandler::updateSystemTime() {
    SETDPDATA(EnumID::DP_TIME, QDateTime::currentDateTime().toString("hh:mm"));
    SETDPDATA(EnumID::DP_DATE, QDateTime::currentDateTime().toString("dd/MM/yyyy"));

    SETDPDATA(EnumID::DP_HOUR, QDateTime::currentDateTime().toString("HH"));     //hour always 24h format
    SETDPDATA(EnumID::DP_MINUTES, QDateTime::currentDateTime().toString("mm"));

    SETDPDATA(EnumID::DP_YEAR, QDateTime::currentDateTime().toString("yyyy"));
    SETDPDATA(EnumID::DP_MONTH, QDateTime::currentDateTime().toString("MM"));
    SETDPDATA(EnumID::DP_DAY, QDateTime::currentDateTime().toString("dd"));
}

void TimeHandler::eventHandler(QString objectName, int eventId, QString param) {
    Q_UNUSED(objectName)
    QStringList params = getListParam(param);
    switch (eventId) {
    case EnumID::HMI_UPDATE_TIME_AUTOMATIC: {

    }
    case EnumID::HMI_SET_DATE_TIME: {

    }
        break;
    default:
        break;
    }
}
