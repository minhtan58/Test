#include "MyDatabase.h"

MyDatabase* MyDatabase::m_instance = nullptr;

MyDatabase::MyDatabase(QObject *parent) : QObject(parent)
{
    createDatabase();
    initDatabase();
}

MyDatabase::~MyDatabase() {
    QSqlDatabase::removeDatabase("QSQLITE");
}

MyDatabase::getInstance() {
    if(m_database == nullptr) {
        qDebug() << "MyDatabase null";
        m_database = new MyDatabase();
    }
    return m_database;
}

bool MyDatabase::createDatabase() {
    if(!QSqlDatabase::drivers().contains("QSQLITE")) {
        qDebug << "Can't load Database - Need create data base";
    }

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    bool status = false;
    database.setDatabaseName("D://My_project/Test/minhtan.db");
    if(database.open()) {
        qDebug() << "Have Created Database";
        status =  true;
    } else {
        qDebug() << "Error open Database" << database.lastError();
    }
    database.close();
    return status;
}

bool MyDatabase::isDbExists()
{
    return QFile::exists("D://My_project/Test/minhtan.db");
}

void MyDatabase::createHistoryDataTable() {
    QSqlDatabase database = QSqlDatabase::database();
    const QString createSQL = "CREATE TABLE IF NOT EXISTS HistoryData(""time DATETIME NOT NULL,""data1 TEXT,""data2 TEXT);";
    QSqlQuery m_query(database);
    if(m_query.exec(createSQL)) {
        qDebug() << "Tabale have crete successfully";
    } else {
        qDebug() << "Create table error" << database.lastError();
    }
    database.close();
}

void MyDatabase::createMissingDataDataTable() {
    QSqlDatabase database = QSqlDatabase::database();
    const QString createSQL = "CREATE TABLE IF NOT EXISTS MissingData(""time DATETIME NOT NULL,""data1 TEXT,""data2 TEXT);";
    QSqlQuery m_query(database);
    if(m_query.exec(createSQL)) {
        qDebug() << "Tabale have crete successfully";
    } else {
        qDebug() << "Create table error" << database.lastError();
    }
    database.close();
}

void MyDatabase::initDatabase() {
    if(isDbExists()) {
        QSqlDatabase database = QSqlDatabase::database();
        if (!database.tables().contains("HistoryData")) {
            createHistoryDataTable();
        }
        if (!database.tables().contains("MissingData")) {
            createMissingDataTable();
        }
    }
}

QList<CemsDataRow> MyDatabase::getHistoryData(QString time) {
    QSqlDatabase database = QSqlDatabase::database();
    if (!database.tables().contains("HistoryData")) {
        qDebug() << "Select record error: HistoryData table does not exist.";
    } else {
        QString command = QString("SELECT * FROM HistoryData "
                                  "WHERE time "
                                  "BETWEEN '%1 00:00:00' "
                                  "AND '%2 23:59:59' "
                                  "ORDER BY datetime(time);").arg(time).arg(time);
        query.prepare(command);

    }
}
