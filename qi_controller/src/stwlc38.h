#ifndef STWLC38_H
#define STWLC38_H

#include <stdint.h>
#include "qi_controller.h"

typedef struct stwlc38_driver_struct * stwlc38_driver; 

typedef struct transport_struct {
    void (*write_reg)(uint8_t addr, uint8_t len, const void *in_data);
    void (*read_reg)(uint8_t addr, uint8_t len, void *out_data);
} transport_struct;

QiController stwlc38_create(int id, transport_struct *transport);

#endif // STWLC38_H
