
#include <stdlib.h>
#include <memory.h>

#include "qi_controller.h"
#include "stwlc38.h"

typedef struct stwlc38_driver_struct {
    QiController base;
    transport_struct *transport;
} stwlc38_driver_struct;

static void SelectEvents(QiController super, QiEventBitMapType events)
{

}

static QiEventBitMapType GetEvents(QiController super)
{

}

static void ClearEvents(QiController super, QiEventBitMapType events)
{

}

static void Destroy(QiController super)
{
    stwlc38_driver me = (stwlc38_driver)super;
    free(me);
}

static int Init(QiController super)
{
    int result = 0;
    stwlc38_driver me = (stwlc38_driver)super;

    uint8_t value = 0x08;
    me->transport->write_reg(0x00, 1, &value);
    me->transport->write_reg(0x01, 1, &value);

    return result;
}

static void PeriodicService(QiController super)
{
    stwlc38_driver me = (stwlc38_driver)super;

    //do stuff need application to call periodicly
    //such as sending real tx power custmized msg to rx
    //me->transport->write_reg()
}

static QiController_InterfaceStruct interface = {
    SelectEvents,
    GetEvents,
    ClearEvents,
    Destroy,
    Init,
    PeriodicService,
};

// low level interfaces
uint32_t Stwlc38_GetRawEvents(stwlc38_driver me)
{

}

QiController stwlc38_create(int id, transport_struct *transport)
{
    stwlc38_driver_struct *me = calloc(1, sizeof(stwlc38_driver_struct));
    me->base->interface_table = &interface;
    me->base->type = "STWLC38";
    me->base->id = id;
    me->transport = transport;

    return (QiController)me;
}
