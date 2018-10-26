#include "ManagerData.h"

#define INITDATA(param) \
    m_datapool.insert(int(param), QString("")); \
    m_dpName.insert(int(param), (QString(#param)).mid(10))

ManagerData* ManagerData::m_managerData = nullptr;

ManagerData::ManagerData(QObject *parent) : QObject(parent)
{
    initData();
    //DbManager::getInstance();
}

ManagerData *ManagerData::getInstance()
{
    if(m_managerData == nullptr) {
        m_managerData = new ManagerData();
    }
    return m_managerData;
}

QString ManagerData::getData(int dpId)
{
    if(m_datapool.contains(dpId)) {
        return m_datapool.value(dpId);
    }
    return "";
}

void ManagerData::setData(int dpid, QString value)
{
    if(m_datapool.contains(dpid)) {
        if (getData(dpid) != value) {
            mutex.lock();
            m_datapool[dpid] = value;
            mutex.unlock();
            emit dataChanged(dpid);
            return;
        }
    } else {
        qDebug() << "DPID:" << dpid << "Incorrect";
    }
}

QString ManagerData::getDataName(int dpId)
{
    if(m_dpName.contains(dpId)) {
        return m_dpName.value(dpId);
    }
    return "";
}

/********************HistoryData**************************/

void ManagerData::setHistoryDataList(const QList<CemsDataRow> &historyDataList)
{
    m_historyDataList = historyDataList;
}

QList<CemsDataRow> ManagerData::getHistoryDataList() const
{
    return m_historyDataList;
}

/********************HistoryData**************************/

void ManagerData::initData()
{
    INITDATA(EnumID::DP_TIME);
    INITDATA(EnumID::DP_DATE);
    INITDATA(EnumID::DP_HOUR);
    INITDATA(EnumID::DP_MINUTES);
    INITDATA(EnumID::DP_DAY);
    INITDATA(EnumID::DP_MONTH);
    INITDATA(EnumID::DP_YEAR);
    INITDATA(EnumID::DP_PORTCOM);
    INITDATA(EnumID::DP_NETWORK);
    INITDATA(EnumID::DP_SERIALPORT_STATUS);
    INITDATA(EnumID::DP_NETWORK_STATUS);
    INITDATA(EnumID::DP_SEARCH_TIME_HISTORY_DATA);
    INITDATA(EnumID::DP_SYS_DATE_DAY);
}
