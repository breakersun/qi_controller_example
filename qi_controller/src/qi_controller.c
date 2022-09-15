#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "qi_controller.h"

void QiController_TurnOnTransmitter(QiController me)
{
    if (me)
        me->interface_table->TurnOnTransmitter(me);
}

void QiController_TurnOffTransmitter(QiController me)
{
    if (me)
        me->interface_table->TurnOffTransmitter(me);
}

void QiController_SetFodGain(QiController me, FodGainLevel level)
{
    if (me)
        me->interface_table->SetFodGain(me, level);
}

void QiController_SelectEvents(QiController me, QiEventType event_mask)
{
   if (me)
        me->interface_table->SelectEvents(me, event_mask);
}

QiEventType QiController_GetEvents(QiController me)
{
    if (me)
        return (me->interface_table->GetEvents(me));
}

const char * QiController_GetType(QiController driver)
{
    if (driver)
        return driver->type;
    else
        return NULL;
}

int QiController_GetId(QiController driver)
{
    if (driver)
        return driver->id;
    else
        return UINT_MAX;
}
