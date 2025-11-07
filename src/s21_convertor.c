#include "s21_convertor.h"
#include "s21_utils.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst)
{
	int return_value = 1;
    if (dst != NULL) {
        dst->bits[0] = 0;
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        dst->bits[3] = 0;
        if (src < 0) {
            set_sign(dst, 1);
            dst->bits[0] = (unsigned int)(-(long long)src);
        } else {
            dst->bits[0] = (unsigned int)src;
        }
        return_value = 0;
    }
    return return_value;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst)
{

}

int s21_from_decimal_to_int(s21_decimal src, int *dst)
{

}

int s21_from_decimal_to_float(s21_decimal src, float *dst)
{
	
}
