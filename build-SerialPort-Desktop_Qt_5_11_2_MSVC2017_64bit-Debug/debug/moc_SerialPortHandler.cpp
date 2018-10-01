/****************************************************************************
** Meta object code from reading C++ file 'SerialPortHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SerialPort/Threads/SerialPortHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialPortHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortHandler_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortHandler_t qt_meta_stringdata_SerialPortHandler = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SerialPortHandler"
QT_MOC_LITERAL(1, 18, 12), // "eventHandler"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 10), // "objectName"
QT_MOC_LITERAL(4, 43, 7), // "eventId"
QT_MOC_LITERAL(5, 51, 5) // "param"

    },
    "SerialPortHandler\0eventHandler\0\0"
    "objectName\0eventId\0param"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,    5,

       0        // eod
};

void SerialPortHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortHandler *_t = static_cast<SerialPortHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->eventHandler((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialPortHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialPortHandler.data,
      qt_meta_data_SerialPortHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialPortHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialPortHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SerialPortHandlerThread_t {
    QByteArrayData data[1];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortHandlerThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortHandlerThread_t qt_meta_stringdata_SerialPortHandlerThread = {
    {
QT_MOC_LITERAL(0, 0, 23) // "SerialPortHandlerThread"

    },
    "SerialPortHandlerThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortHandlerThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SerialPortHandlerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SerialPortHandlerThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SerialPortHandlerThread.data,
      qt_meta_data_SerialPortHandlerThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialPortHandlerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortHandlerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortHandlerThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int SerialPortHandlerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
