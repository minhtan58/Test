#ifndef DEFINES_H
#define DEFINES_H

#include <QStringList>

inline QStringList getListParam(QString params)
{
    return params.split(",");
}

#define DECLARE_VAR(TYPE, NAME) \
    private: \
        TYPE m_##NAME;\
    public: TYPE NAME() const \
    { \
        return m_##NAME; \
    } \
    void set##NAME(const TYPE &value) \
    { \
        m_##NAME = value; \
    }

/********************Define value QML***********************/

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   480
#define Z_BACKGROUND    0



/***********************************************************/

#define SENDEVENT(OBJECT, EVENTID, PARAM)   UIBridge::getInstance()->sendEvent(OBJECT, EVENTID, PARAM)

#define SETDPDATA(DPID, VALUE)  ManagerData::getInstance()->setData(DPID, VALUE)

#define GETDPDATA(DPID)         ManagerData::getInstance()->getData(DPID)

#define SETPROPERTY(OBJECT, PROPERTY, VALUE)    { \
                                                    if((!strcmp(OBJECT, ""))||(!m_screenView->objectName().compare(OBJECT))) {\
                                                        m_screenView->setProperty(PROPERTY, VALUE); \
                                                    } \
                                                    else { \
                                                        QList<QObject*> _uiObjects = m_screenView->findChildren<QObject*>(OBJECT); \
                                                        if (m_screenView->objectName() == OBJECT) \
                                                            m_screenView->setProperty(PROPERTY, VALUE); \
                                                        foreach (QObject* _uiObject, _uiObjects) {\
                                                            if (_uiObject) _uiObject->setProperty(PROPERTY, VALUE); \
                                                        } \
                                                    } \
                                                }

#endif // DEFINES_H
