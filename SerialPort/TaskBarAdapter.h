#ifndef TOPBARADAPTER_H
#define TOPBARADAPTER_H

#include <QObject>
#include <QQuickItem>

#include "Enum.h"
#include "ManagerData.h"

class TaskBarAdapter : public QObject
{
    Q_OBJECT
public:
    explicit TaskBarAdapter(QQuickItem *container, QObject *parent = nullptr);
    void initAppData();

public slots:
    void updateAppData(int dpid);

private:
    QQuickItem *m_tasbarContakiner = nullptr;
    QObject *m_taskBarView = nullptr;
};

#endif // TOPBARADAPTER_H
