#ifndef HISTORYDATA_H
#define HISTORYDATA_H

#include <QObject>
#include <Defines.h>
#include <QThread>
#include <QAbstractListModel>
#include <QVariant>

class HistoryDataElement {
public:
    HistoryDataElement(QString id, QString data1, QString data2) {
        m_id = id;
        m_data1 = data1;
        m_data2 = data2;
    }
    DECLARE_VAR(QString, id)
    DECLARE_VAR(QString, data1)
    DECLARE_VAR(QString, data2)
};

class HistoryDataFeeder : public QThread {
    Q_OBJECT
public:
    explicit HistoryDataFeeder(QList<HistoryDataElement*> *listModel, QObject *parent = nullptr)
        : QThread(parent)
        , m_listModel(listModel)
        {}
signals:
    void updateFetchDataStatus(int status);

protected:
    void run();

private:
    QList<HistoryDataElement*> *m_listModel = nullptr;
};

class HistoryDataModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum LoginHistoryEnum {
        ID,
        DATA1,
        DATA2,
    };

    explicit HistoryDataModel(QObject *parent = nullptr);
    ~HistoryDataModel();
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int,QByteArray> roleNames() const;

signals:

public slots:

private:
    QList<HistoryDataElement*> *m_listElement;
    HistoryDataFeeder *m_feeder;
};

#endif // HISTORYDATA_H
