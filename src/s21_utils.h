#ifndef S21_UTILS_H
#define S21_UTILS_H

#include "s21_decimal.h"

#define OK 0
#define CALC_ERR 1

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

void decimal_output(s21_decimal value); // don't forget to delete this

#endif