#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include <string.h>
#include "common.h"

typedef struct {
    base_t* data;
    size_t element_size;
    size_t capacity;
    size_t count;
} List;

void list_init(List* list, size_t element_size, size_t initial_capacity) {
    list->element_size = element_size;
    list->capacity = initial_capacity;
    list->count = 0;
    list->data = (base_t*)malloc(element_size * initial_capacity);
}

void list_add(List* list, const void* element) {
    if (list->count >= list->capacity) {
        list->capacity *= 2;
        list->data = (base_t*)realloc(list->data, list->element_size * list->capacity);
    }

    memcpy(list->data + list->count * list->element_size, element, list->element_size);
    list->count++;
}

int list_contains(List* list, const void* element) {
    for (size_t i = 0; i < list->count; ++i) {
        if (memcmp(list->data + i * list->element_size, element, list->element_size) == 0)
            return 1;
    }
    return 0;
}

void list_free(List* list) {
    free(list->data);
    list->data = NULL;
    list->count = list->capacity = 0;
}

void list_foreach(List* list, void (*func)(void*)) {
    for (size_t i = 0; i < list->count; ++i) {
        char* element = list->data + i * list->element_size;
        func(element);
    }
}

#define list_init_t(list, T, initial_capacity) list_init(list, sizeof(T), initial_capacity)

#endif