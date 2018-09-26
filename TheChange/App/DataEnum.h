#ifndef DATAENUM_H
#define DATAENUM_H

#include <QObject>

class DataEnum : public QObject
{
    Q_GADGET
    Q_ENUMS(_DatapoolID)
    Q_ENUMS(_HMIEvent)
public:
    typedef enum _DatapoolID{
        //-------------------SYSTEM-------------------//
        DP_SYS_TIME = 0x0000,
        DP_SYS_DATE,

        DP_SYS_TIME_HOUR,
        DP_SYS_TIME_MINUTES,
        DP_SYS_DATE_DAY,
        DP_SYS_DATE_MONTH,
        DP_SYS_DATE_YEAR,

        DP_SYS_SETTINGS_TIME_AUTOMATIC_UPDATE,
        DP_GENERAL_STATION_ID,
        DP_GENERAL_STATION_NAME,
        DP_GENERAL_RADIUS,

        //-----------------SETTINGS--------------------//
        DP_SETTINGS_DATAVIEW_MODE = 0x2000,
        DP_SETTINGS_DATAVIEW_MODE_CO,
        DP_SETTINGS_DATAVIEW_MODE_NO,
        DP_SETTINGS_DATAVIEW_MODE_NOX,
        DP_SETTINGS_DATAVIEW_MODE_SO2,

        //---------------------AIR---------------------//
        DP_PPM_AIR_O2,
        DP_PPM_AIR_CO,
        DP_PPM_AIR_NO,
        DP_PPM_AIR_NOX,
        DP_PPM_AIR_SO2,

        //-----------------SERIALPORT-----------------//
        DP_SETTINGS_SERIALPORT_PORTNAME,
        DP_SETTINGS_SERIALPORT_BAUDRATE,
        DP_SETTINGS_SERIALPORT_INTERVAL,
        DP_SETTINGS_SERIALPORT_STATUS,
        DP_SETTINGS_SERIALPORT_TEST_CONNECTION,
        DP_SETTINGS_SERIALPORT_LIST_AVAIABLE_PORTNAME,

    }DatapoolID;

    typedef enum _HMIEvent{
        //-----------------SCREEN-----------------//
        HMI_BUTTON_HOME,
        HMI_BUTTON_AUDIO,
        HMI_BUTTON_SETTING,
        HMI_BUTTON_CLIMATE,
        HMI_BUTTON_DATA,
        HMI_BUTTON_NETWORK,

        //-----------------POPUP-----------------//
        HMI_REQUEST_SHOW_COMMON_POPUP,
        HMI_REQUEST_HIDE_POPUP,




        HMI_SWITCH_UPDATE_TIME_AUTOMATIC,
        HMI_BUTTON_SET_RADIUS,
        HMI_BUTTON_SET_DATE_TIME,
    }HMIEvent;
};

#endif // DATAENUM_H
