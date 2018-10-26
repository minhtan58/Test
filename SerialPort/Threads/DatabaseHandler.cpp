//#include "DatabaseHandler.h"

//DatabaseHandler::DatabaseHandler(QObject *parent) : QObject(parent)
//{
//    MyDatabase::getInstance();
//}

//void DatabaseHandler::eventHandler(QString objectName, int eventId, QString param) {
//    Q_UNUSED(objectName)
//    Q_UNUSED(param)
//    switch (eventId) {
//    case EnumID::HMI_UPDATE_DATABASE: {
//        MyDatabase::getInstance()->createHistoryDataTable();
//        break;
//    }
//    case EnumID::HMI_REMOVE_DATABASE: {
//        MyDatabase::getInstance()->createHistoryDataTable();
//        break;
//    }
//    default:
//        break;
//    }
//}
