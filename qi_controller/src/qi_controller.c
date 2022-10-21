#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "qi_controller.h"


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

void QiController_Destroy(QiController me)
{
    if (me)
        return (me->interface_table->Destroy(me));
}


int QiController_Init(QiController me)
{
    if (me)
        return (me->interface_table->Init(me));
}


void QiController_PeriodicServiceCall(QiController me)
{
    if (me)
        return (me->interface_table->PeriodicService(me));
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
