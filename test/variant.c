#include <stdio.h>
#include "../src/variant.h"

int main() {
    Variant var_i;
    variant_init_t(&var_i, int);
    int value1 = 1;
    variant_assign(&var_i, &value1);
    int get_value_i = 0;
    variant_get_value(&var_i, &get_value_i);
    printf("%d\n", get_value_i);
    variant_free(&var_i);
    Variant var_f;
    variant_init_t(&var_f, double);
    double value2 = 2.0;
    variant_assign(&var_f, &value2);
    double get_value_f = 0;
    variant_get_value(&var_f, &get_value_f);
    printf("%.6f\n", get_value_f);
    variant_free(&var_f);
}