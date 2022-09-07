
#include <stdlib.h>
#include <memory.h>

#include "qi_controller.h"
#include "stwlc38.h"

typedef struct stwlc38_driver_struct {
    QiController base;
    transport_struct *transport;
} stwlc38_driver_struct;

static void TurnOnTransmitter(QiController super)
{

}

static void TurnOffTransmitter(QiController super)
{

}

static void SetFodGain(QiController super, FodGainLevel level)
{

}

static void Destroy(QiController super)
{
    stwlc38_driver me = (stwlc38_driver)super;
    free(me);
}

static QiController_InterfaceStruct interface = {
    TurnOffTransmitter,
    TurnOffTransmitter,
    SetFodGain,
    Destroy,
};

QiController stwlc38_create(int id, transport_struct *transport)
{
    stwlc38_driver_struct *me = calloc(1, sizeof(stwlc38_driver_struct));
    me->base->interface_table = &interface;
    me->base->type = "STWLC38";
    me->base->id = id;
    me->transport = transport;

    return (QiController)me;
}
