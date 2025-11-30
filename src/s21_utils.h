#ifndef S21_UTILS_H
#define S21_UTILS_H

#include "s21_decimal.h"
#include <stdint.h>

#define OK 0
#define CALC_ERR 1

typedef struct {
    uint32_t bits[6];
    uint32_t scale;
    uint32_t sign;
} s21_long_decimal;

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

void decimal_to_long(s21_decimal src, s21_long_decimal *dst);
void normalize_long(s21_long_decimal *d);
int long_eq(s21_long_decimal a, s21_long_decimal b);
int long_less(s21_long_decimal a, s21_long_decimal b);
static void multiply_long_by_10(s21_long_decimal *d);
static unsigned int divide_long_by_10(s21_long_decimal *d);

static inline uint32_t get_sign(s21_decimal d) {
    return (uint32_t)((d.bits[3] >> 31) & 1);
}

static inline uint32_t get_scale(s21_decimal d) {
    return (uint32_t)((d.bits[3] >> 16) & 0xFF);
}

static inline void set_sign(s21_decimal *d, uint32_t sign) {
    if (sign)
        d->bits[3] |= (1U << 31);
    else
        d->bits[3] &= ~(1U << 31);
}

static inline void set_scale(s21_decimal *d, uint32_t scale) {
    d->bits[3] = (d->bits[3] & ~0xFF0000U) | ((scale & 0xFF) << 16);
}

static inline int is_zero_mantissa(s21_decimal d) {
    return (d.bits[0] == 0 && d.bits[1] == 0 && d.bits[2] == 0);
}

#endif