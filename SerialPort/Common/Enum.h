#ifndef ENUM_H
#define ENUM_H

#include <QObject>
#include <QHash>

class EnumID: public QObject
{
    Q_OBJECT
    Q_ENUMS(_DatapoolID)
    Q_ENUMS(_HMIEvent)

public:
    typedef enum _DatapoolID{
        DP_TIME = 0x0000,
        DP_DATE,
        DP_HOUR,
        DP_MINUTES,
        DP_DAY,
        DP_MONTH,
        DP_YEAR,
        DP_STATUS_ALARM_ON_COUNT,

        DP_DATE_DAY,
        DP_DATE_MONTH,
        DP_DATE_YEAR,

        DP_SYS_SETTINGS_TIME_AUTOMATIC_UPDATE,
        DP_GENERAL_STATION_ID,
        DP_GENERAL_STATION_NAME,
        DP_GENERAL_RADIUS,

        DP_PORTCOM,
        DP_SERIALPORT_STATUS,

        DP_NETWORK,
        DP_NETWORK_STATUS,

        DP_SYS_DATE_DAY,
        DP_SEARCH_TIME_HISTORY_DATA,

        DP_SETTINGS_NETWORK_SERVER_INTERVAL
   }DatapoolID;

     typedef enum _HMIEvent{
        /* Show screen */
        HMI_HOME_SCREEN,
        HMI_CONNECTION_PORTCOM_SCREEN,
        HMI_CONNECTION_NETWORK_SCREEN,
        HMI_DATA_VIEW_SCREEN,
        HMI_VIEW_DATA_HISTORY_SCREEN,

        /* Show popup */
        HMI_COMMON_POPUP,
        HMI_HIDE_POPUP,
        HMI_CONNECTED_POPUP,
        HMI_DISCONNECTED_POPUP,
        HMI_REQUEST_SHOW_EXPORT_POPUP,

        /* Connection */
        HMI_TEST_CONNECTIONS_SERIALPORT,
        HMI_SEND_DATA_SERIALPORT,
        HMI_TEST_CONNECTIONS_NETWORK,
        HMI_SEND_DATA_NETWORK,

        /* Setting Time */
        HMI_UPDATE_TIME_AUTOMATIC,
        HMI_SET_DATE_TIME,

        /* Database */
        HMI_UPDATE_DATABASE,
        HMI_REMOVE_DATABASE,
        HMI_REQUEST_GET_HISTORY_DATA,
        HMI_RESPONSE_GET_HISTORY_DATA_FINISHED,
        HMI_REQUEST_ADD_MISSING_DATA_ROW,
        HMI_REQUEST_REMOVE_MISSING_DATA_ROW,
        HMI_BUTTON_REQ_EXPORT

    }HMIEvent;
};

//***********************************************************************************************//

enum  ScreenID{
    ICS_HOME = 0x0000,
    ICS_CONNECTION_PORTCOM,
    ICS_CONNECTION_NETWORK,
    ICS_DATA_VIEW,
    ICS_HISTORY_DATAVIEW,
    ICS_LOGIN_FORM,

    ICP_COMMON_POPUP = 0xA000,
    ICP_CONNECT_POPUP,
    ICP_DISCONNECT_POPUP,
};

const QHash<int, QString> mapScreen = {
    {ICS_HOME,                             "qrc:/Screen/ics_home.qml"                     },
    {ICS_CONNECTION_PORTCOM,               "qrc:/Screen/ics_connection_portcom.qml"       },
    {ICS_CONNECTION_NETWORK,               "qrc:/Screen/ics_connection_network.qml"       },
    {ICS_DATA_VIEW,                        "qrc:/Screen/ics_data_view.qml"                },
    {ICS_HISTORY_DATAVIEW,                 "qrc:/Screen/ics_view_data_history.qml"        },
    {ICS_LOGIN_FORM,                       "qrc:/Screen/ics_login_form.qml"               },

    {ICP_CONNECT_POPUP,                    "qrc:/Screen/icp_connect_popup.qml"            },
    {ICP_DISCONNECT_POPUP,                 "qrc:/Screen/icp_disconnect_popup.qml"         },
    {ICP_COMMON_POPUP,                     "qrc:/Screen/icp_common_popup.qml"             },
};

//***********************************************************************************************//

enum OverlayZ{
    BACKGROUND = -1,
    SCREENCONTAINER,
    TASKBAR,
    KEYBOARD,
    OVERLAY,
};

enum TestConnection {
    IS_CONNECT_FAIL,
    IS_CHECKING,
    IS_CONNECTED,
    IS_DISCONNECTED,
};

enum FetchDataStatus {
    FETCH_IDLE,
    FETCH_STARTING,
    FETCH_FINISHED
};

typedef struct {
    QString id;
    QString time;
    QString data1;
    QString data2;
    QString data3;
} CemsDataRow;

#endif // ENUM_H
