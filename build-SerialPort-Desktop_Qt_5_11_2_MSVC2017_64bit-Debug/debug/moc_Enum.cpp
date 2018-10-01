/****************************************************************************
** Meta object code from reading C++ file 'Enum.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SerialPort/Common/Enum.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Enum.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EnumID_t {
    QByteArrayData data[26];
    char stringdata0[429];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EnumID_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EnumID_t qt_meta_stringdata_EnumID = {
    {
QT_MOC_LITERAL(0, 0, 6), // "EnumID"
QT_MOC_LITERAL(1, 7, 11), // "_DatapoolID"
QT_MOC_LITERAL(2, 19, 7), // "DP_TIME"
QT_MOC_LITERAL(3, 27, 7), // "DP_DATE"
QT_MOC_LITERAL(4, 35, 7), // "DP_HOUR"
QT_MOC_LITERAL(5, 43, 10), // "DP_MINUTES"
QT_MOC_LITERAL(6, 54, 6), // "DP_DAY"
QT_MOC_LITERAL(7, 61, 8), // "DP_MONTH"
QT_MOC_LITERAL(8, 70, 7), // "DP_YEAR"
QT_MOC_LITERAL(9, 78, 10), // "DP_PORTCOM"
QT_MOC_LITERAL(10, 89, 20), // "DP_SERIALPORT_STATUS"
QT_MOC_LITERAL(11, 110, 10), // "DP_NETWORK"
QT_MOC_LITERAL(12, 121, 17), // "DP_NETWORK_STATUS"
QT_MOC_LITERAL(13, 139, 9), // "_HMIEvent"
QT_MOC_LITERAL(14, 149, 15), // "HMI_HOME_SCREEN"
QT_MOC_LITERAL(15, 165, 29), // "HMI_CONNECTION_PORTCOM_SCREEN"
QT_MOC_LITERAL(16, 195, 29), // "HMI_CONNECTION_NETWORK_SCREEN"
QT_MOC_LITERAL(17, 225, 20), // "HMI_DATA_VIEW_SCREEN"
QT_MOC_LITERAL(18, 246, 16), // "HMI_COMMON_POPUP"
QT_MOC_LITERAL(19, 263, 14), // "HMI_HIDE_POPUP"
QT_MOC_LITERAL(20, 278, 19), // "HMI_CONNECTED_POPUP"
QT_MOC_LITERAL(21, 298, 22), // "HMI_DISCONNECTED_POPUP"
QT_MOC_LITERAL(22, 321, 31), // "HMI_TEST_CONNECTIONS_SERIALPORT"
QT_MOC_LITERAL(23, 353, 24), // "HMI_SEND_DATA_SERIALPORT"
QT_MOC_LITERAL(24, 378, 28), // "HMI_TEST_CONNECTIONS_NETWORK"
QT_MOC_LITERAL(25, 407, 21) // "HMI_SEND_DATA_NETWORK"

    },
    "EnumID\0_DatapoolID\0DP_TIME\0DP_DATE\0"
    "DP_HOUR\0DP_MINUTES\0DP_DAY\0DP_MONTH\0"
    "DP_YEAR\0DP_PORTCOM\0DP_SERIALPORT_STATUS\0"
    "DP_NETWORK\0DP_NETWORK_STATUS\0_HMIEvent\0"
    "HMI_HOME_SCREEN\0HMI_CONNECTION_PORTCOM_SCREEN\0"
    "HMI_CONNECTION_NETWORK_SCREEN\0"
    "HMI_DATA_VIEW_SCREEN\0HMI_COMMON_POPUP\0"
    "HMI_HIDE_POPUP\0HMI_CONNECTED_POPUP\0"
    "HMI_DISCONNECTED_POPUP\0"
    "HMI_TEST_CONNECTIONS_SERIALPORT\0"
    "HMI_SEND_DATA_SERIALPORT\0"
    "HMI_TEST_CONNECTIONS_NETWORK\0"
    "HMI_SEND_DATA_NETWORK"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnumID[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,   11,   22,
      13, 0x0,   12,   44,

 // enum data: key, value
       2, uint(EnumID::DP_TIME),
       3, uint(EnumID::DP_DATE),
       4, uint(EnumID::DP_HOUR),
       5, uint(EnumID::DP_MINUTES),
       6, uint(EnumID::DP_DAY),
       7, uint(EnumID::DP_MONTH),
       8, uint(EnumID::DP_YEAR),
       9, uint(EnumID::DP_PORTCOM),
      10, uint(EnumID::DP_SERIALPORT_STATUS),
      11, uint(EnumID::DP_NETWORK),
      12, uint(EnumID::DP_NETWORK_STATUS),
      14, uint(EnumID::HMI_HOME_SCREEN),
      15, uint(EnumID::HMI_CONNECTION_PORTCOM_SCREEN),
      16, uint(EnumID::HMI_CONNECTION_NETWORK_SCREEN),
      17, uint(EnumID::HMI_DATA_VIEW_SCREEN),
      18, uint(EnumID::HMI_COMMON_POPUP),
      19, uint(EnumID::HMI_HIDE_POPUP),
      20, uint(EnumID::HMI_CONNECTED_POPUP),
      21, uint(EnumID::HMI_DISCONNECTED_POPUP),
      22, uint(EnumID::HMI_TEST_CONNECTIONS_SERIALPORT),
      23, uint(EnumID::HMI_SEND_DATA_SERIALPORT),
      24, uint(EnumID::HMI_TEST_CONNECTIONS_NETWORK),
      25, uint(EnumID::HMI_SEND_DATA_NETWORK),

       0        // eod
};

void EnumID::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject EnumID::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EnumID.data,
      qt_meta_data_EnumID,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EnumID::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnumID::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnumID.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EnumID::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
