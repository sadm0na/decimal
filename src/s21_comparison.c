#include "s21_comparison.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
    int return_value = 0;
    s21_long_decimal d1, d2;
    decimal_to_long(value_1, &d1);
    decimal_to_long(value_2, &d2);
    return_value = long_less(d1, d2);
    return return_value;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
    int return_value = 0;
    int less = s21_is_less(value_1, value_2);
    int equal = s21_is_equal(value_1, value_2);
    if (less || equal) {
        return_value = 1;
    }
    return return_value;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
    int return_value = 0;
    return_value = s21_is_less(value_2, value_1);
    return return_value;
}

int s21_is_greater_or_equal(s21_decimal a, s21_decimal b)
{
	int return_value = 0;
    int less = s21_is_less(value_1, value_2);
    if (!less) {
        return_value = 1;
    }
    return return_value;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
    int return_value = 0;
    s21_long_decimal d1, d2;
    decimal_to_long(value_1, &d1);
    decimal_to_long(value_2, &d2);
    normalize_long(&d1);
    normalize_long(&d2);
    return_value = long_eq(d1, d2);
    return return_value;
}

int s21_is_not_equal(s21_decimal a, s21_decimal b)
{
	int return_value = 0;
    int equal = s21_is_equal(value_1, value_2);
    if (!equal) {
        return_value = 1;
    }
    return return_value;
}
