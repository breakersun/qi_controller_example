/****************************************************************************
* Title                 :   Qi controller(QiController)
* Filename              :   qi_controller.h
* Author                :   Leo Sun
* Origin Date           :   10/21/2022 Fri
* Version               :   0.0.0
* Compiler              :   TBD
* Target                :   TBD
* Notes                 :   None
*
*****************************************************************************/
/*************** INTERFACE CHANGE LIST **************************************
*
*    Date    Version   Author         Description
*
*****************************************************************************/
/** @file qi_controller.h
 *  @brief The interface definition for the QiController.
 *
 *  This is the header file for the definition of the interface for a qi-wireless charger
 *  peripheral on a standard microcontroller.
 */

#ifndef QI_CONTROLLER_H
#define QI_CONTROLLER_H

#include <stdint.h>

typedef enum {
    gain_level_0,
    gain_level_1,
    gain_level_2,
} FodGainLevel;

typedef enum {
    ovp = 1,
    ocp = 1 << 1,
    otp = 1 << 2,
    fod = 1 << 3,
} QiEventType;

typedef uint32_t QiEventBitMapType;

typedef struct QiControllerStruct *QiController;

typedef struct QiController_InterfaceStruct {
    void (*SelectEvents)(QiController, QiEventBitMapType);
    QiEventBitMapType (*GetEvents)(QiController);
    void (*ClearEvents)(QiController, QiEventBitMapType);
    void (*Destroy)(QiController);
    int (*Init)(QiController);
    void (*PeriodicService)(QiController);

} QiController_InterfaceStruct;

typedef struct QiControllerStruct {
    QiController_InterfaceStruct *interface_table;
    const char *type;
    int id;
} QiControllerStruct;

/**
 * @brief
 *
 * @return
 */
int QiController_Init(QiController);
void QiController_Destroy(QiController);
void QiController_SelectEvent(QiController, QiEventBitMapType);
QiEventBitMapType QiController_GetEvents(QiController);
void QiController_ClearEvents(QiController, QiEventBitMapType);
void QiController_PeriodicServiceCall(QiController);
const char* QiController_GetType(QiController);
int QiController_GetId(QiController);

#endif // QI_CONTROLLER_H
