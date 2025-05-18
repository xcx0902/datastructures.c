#include <stdio.h>
#include "../src/list.h"

void print_int(void* value) {
    printf("%d\n", *(int*)(value));
}

void add1(void* value) {
    int* v = (int*)value;
    // fprintf(stderr, "Debug: %d\n", *v);
    *v += 1;
    // fprintf(stderr, "Debug: %d\n", *v);
}

int main() {
    List L;
    list_init_t(&L, int, 1);
    int value0 = 0;
    list_add(&L, &value0);
    int value1 = 1;
    list_add(&L, &value1);
    printf("%d\n", list_contains(&L, &value0));
    int value2 = 2;
    printf("%d\n", list_contains(&L, &value2));
    list_foreach(&L, print_int);
    list_foreach(&L, add1);
    list_foreach(&L, print_int);
    list_free(&L);
}