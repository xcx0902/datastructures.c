#ifndef _VARIANT_H
#define _VARIANT_H

#include <stdlib.h>
#include <string.h>
#include "common.h"

typedef struct {
    base_t* value;
    size_t element_size;
} Variant;

void variant_init(Variant* var, size_t element_size) {
    var->element_size = element_size;
    var->value = (base_t*)malloc(element_size);
}

void variant_assign(Variant* var, const void* value) {
    memcpy(var->value, value, var->element_size);
}

void variant_get_value(Variant* var, void* value) {
    memcpy(value, var->value, var->element_size);
}

void variant_free(Variant* var) {
    free(var->value);
    var->value = NULL;
}

#define variant_init_t(var, T) variant_init(var, sizeof(T))

#endif