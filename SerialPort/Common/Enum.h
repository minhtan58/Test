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

        DP_PORTCOM,
        DP_SERIALPORT_STATUS,

        DP_NETWORK,
        DP_NETWORK_STATUS,

   }DatapoolID;

     typedef enum _HMIEvent{
        /* Show popup */
        HMI_HOME_SCREEN,
        HMI_CONNECTION_PORTCOM_SCREEN,
        HMI_CONNECTION_NETWORK_SCREEN,
        HMI_DATA_VIEW_SCREEN,

        /* Show popup */
        HMI_COMMON_POPUP,
        HMI_HIDE_POPUP,
        HMI_CONNECTED_POPUP,
        HMI_DISCONNECTED_POPUP,

        /* Connection */
        HMI_TEST_CONNECTIONS_SERIALPORT,
        HMI_SEND_DATA_SERIALPORT,
        HMI_TEST_CONNECTIONS_NETWORK,
        HMI_SEND_DATA_NETWORK,

        /* Setting Time */
        HMI_UPDATE_TIME_AUTOMATIC,
        HMI_SET_DATE_TIME

    }HMIEvent;
};

//***********************************************************************************************//

enum  ScreenID{
    ICS_HOME = 0x0000,
    ICS_CONNECTION_PORTCOM,
    ICS_CONNECTION_NETWORK,
    ICS_DATA_VIEW,

    ICS_COMMON_POPUP = 0xA000,
    ICS_CONNECT_POPUP,
    ICS_DISCONNECT_POPUP
};

const QHash<int, QString> mapScreen = {
    {ICS_HOME,                             "qrc:/Screen/home.qml"                                },
    {ICS_COMMON_POPUP,                     "qrc:/Screen/ics_common_popup.qml"                    },
    {ICS_CONNECTION_PORTCOM,               "qrc:/Screen/ics_connection_portcom.qml"              },
    {ICS_CONNECTION_NETWORK,               "qrc:/Screen/ics_connection_network.qml"              },
    {ICS_DATA_VIEW,                        "qrc:/Screen/ics_data_view.qml"                       },
    {ICS_CONNECT_POPUP,                    "qrc:/Screen/ics_connect_popup.qml"                   },
    {ICS_DISCONNECT_POPUP,                 "qrc:/Screen/ics_disconnect_popup.qml"                },
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

#endif // ENUM_H
