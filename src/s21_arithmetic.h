#ifndef S21_ARITHMETIC_H
#define S21_ARITHMETIC_H

#include "s21_decimal.h"

#define OK 0
#define POS_OVERFLOW 1
#define NEG_OVERFLOW 2
#define ZERO_DIVISION 3

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif