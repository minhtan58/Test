#include "HistoryDatahandler.h"

HistoryDataHandler::HistoryDataHandler(QObject *parent) : QObject(parent)
{

}

void HistoryDataHandler::eventHandler(QString objectName, int eventId, QString param)
{
    Q_UNUSED(objectName)
    switch (eventId) {
    case EnumID::HMI_REQUEST_GET_HISTORY_DATA: {
        SETDPDATA(EnumID::DP_SEARCH_TIME_HISTORY_DATA, param);
        if(m_listHistory) {
            m_listHistory->~HistoryDataListModel();
            m_qmlAppEngine->rootContext()->setContextProperty("listHistory", nullptr);
        }
        break;
    }
    case EnumID::DB_RESPONSE_GET_HISTORY_DATA_FINISHED: {
        m_listHistory = new HistoryDataListModel(this);
        m_listHistory->fetchData();
        m_qmlAppEngine->rootContext()->setContextProperty("listHistory", m_listHistory);
        emit m_listHistory->updateFetchDataStatus(FETCH_FINISHED);
        break;
    }
    default:
        break;
    }
}
