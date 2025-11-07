#include "s21_utils.h"

int s21_floor(s21_decimal value, s21_decimal *result)
{

}

int s21_round(s21_decimal value, s21_decimal *result)
{

}

int s21_truncate(s21_decimal value, s21_decimal *result)
{

}

int s21_negate(s21_decimal value, s21_decimal *result)
{
	int return_value = 1;
    if (result != NULL) {
		*result = value;
        result->bits[3] ^= (1UL << 31); // ^ - исключающее или
        return_value = 0;
    }
    return return_value;
}

void decimal_to_long(s21_decimal src, s21_long_decimal *dst) {
    dst->bits[0] = (uint32_t)src.bits[0];
    dst->bits[1] = (uint32_t)src.bits[1];
    dst->bits[2] = (uint32_t)src.bits[2];
    dst->bits[3] = 0;
    dst->bits[4] = 0;
    dst->bits[5] = 0;
    dst->scale = get_scale(src);
    dst->sign = get_sign(src);
}

void normalize_long(s21_long_decimal *d) {
    while (d->scale > 0) {
        uint32_t remainder = 0;
        int divisible = 1;
        for (int i = 5; i >= 0; i--) {
            unsigned long long cur = ((unsigned long long)remainder << 32) | d->bits[i];
            d->bits[i] = (uint32_t)(cur / 10);
            remainder = (uint32_t)(cur % 10);
            if (remainder != 0) divisible = 0;
        }
        if (!divisible) break;
        d->scale--;
    }
}

int long_eq(s21_long_decimal a, s21_long_decimal b) {
    int result = TRUE;

    if (a.scale != b.scale || a.sign != b.sign) {
        result = FALSE;
    } else {
        for (int i = 0; i < 6 && result == TRUE; i++) {
            if (a.bits[i] != b.bits[i]) {
                result = FALSE;
            }
        }
    }

    return result;
}
//мона это вообще хер знает как будто бы говно
int long_less(s21_long_decimal a, s21_long_decimal b) {
    int result = FALSE;
    int a_zero = 1, b_zero = 1;
    for (int i = 0; i < 6; i++) {
        if (a.bits[i] != 0) a_zero = 0;
        if (b.bits[i] != 0) b_zero = 0;
    }

    if (!(a_zero && b_zero)) {
        if (a.sign != b.sign) {
            result = (a.sign == 1 && b.sign == 0);
        } else {
            normalize_long(&a);
            normalize_long(&b);

            if (a.scale == b.scale) {
                if (a.sign == 0) {
                    int i = 5;
                    int compared = 0; // 0 — не определено, 1 - меньше, 2 - больше, 3 - равно
                    while (i >= 0 && compared == 0) {
                        if (a.bits[i] < b.bits[i]) {
                            compared = 1;
                        } else if (a.bits[i] > b.bits[i]) {
                            compared = 2;
                        } else {
                            i--;
                        }
                    }
                    if (compared == 0) compared = 3; // все биты равны

                    if (compared == 1) {
                        result = TRUE;
                    }
                } else {
                    int i = 5;
                    int compared = 0;
                    while (i >= 0 && compared == 0) {
                        if (b.bits[i] < a.bits[i]) {
                            compared = 1;
                        } else if (b.bits[i] > a.bits[i]) {
                            compared = 2;
                        } else {
                            i--;
                        }
                    }
                    if (compared == 0) compared = 3;

                    if (compared == 1) {
                        result = TRUE;
                    }
                }
            }
            // Если масштабы разные — result остаётся FALSE (упрощение)
        }
    }

    return result;
}