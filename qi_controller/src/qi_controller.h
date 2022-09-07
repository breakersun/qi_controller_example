#ifndef QI_CONTROLLER_H
#define QI_CONTROLLER_H

typedef enum {
    gain_level_0,
    gain_level_1,
    gain_level_2,
} FodGainLevel;

typedef enum {
    rx_output_off = 1 << 7,
    rx_output_on = 1 << 6,
} QiEventType;

typedef struct QiControllerStruct *QiController;

typedef struct QiController_InterfaceStruct {
    void (*TurnOnTransmitter)(QiController);
    void (*TurnOffTransmitter)(QiController);
    void (*SetFodGain)(QiController, FodGainLevel);
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
const char* QiController_GetType(QiController);
int QiController_GetId(QiController);

#endif // QI_CONTROLLER_H
