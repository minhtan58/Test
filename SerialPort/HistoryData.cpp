#include "HistoryData.h"

QVariant HistoryDataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 ||
            index.row() >= m_listElement->size()){
        return QVariant();
    }
    const HistoryDataElement *dobj = m_listElement->at(index.row());

    switch (role) {
    case ID:
        return QVariant::fromValue(dobj->id());
    case DATA1:
        return QVariant::fromValue(dobj->data1());
    case DATA2:
        return QVariant::fromValue(dobj->data2());
    default:
        return QVariant();
    }
}
