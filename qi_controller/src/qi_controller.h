#ifndef QI_CONTROLLER_H
#define QI_CONTROLLER_H

typedef enum {
    gain_level_0,
    gain_level_1,
    gain_level_2,
} FodGainLevel;

typedef enum {
    ovp = 1,
    ocp = 1 << 1,
    otp = 1 << 2,
    rx_output_off = 1 << 7,
    rx_output_on = 1 << 6,
} QiEventType;


typedef struct QiControllerStruct *QiController;

typedef struct QiController_InterfaceStruct {
    void (*TurnOnTransmitter)(QiController);
    void (*TurnOffTransmitter)(QiController);
    void (*SetFodGain)(QiController, FodGainLevel);
    void (*SelectEvents)(QiController, QiEventType);
    QiEventType (*GetEvents)(QiController);
    void (*Destroy)(QiController);

} QiController_InterfaceStruct;

typedef struct QiControllerStruct {
    QiController_InterfaceStruct *interface_table;
    const char *type;
    int id;
} QiControllerStruct;


void QiController_TurnOnTransmitter(QiController);
void QiController_TurnOffTransmitter(QiController);
void QiController_SetFodGain(QiController, FodGainLevel);
void QiController_SelectEvent(QiController, QiEventType);
QiEventType QiController_GetEvents(QiController);
const char* QiController_GetType(QiController);
int QiController_GetId(QiController);

#endif // QI_CONTROLLER_H
