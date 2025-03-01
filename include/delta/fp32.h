#pragma once

#include <stdint.h>

/* Define the IEEE-754 floating-point type. */
typedef uint32_t fp32_t;

/* Compute the addition of two IEEE-754 floating-point numbers. */
int fp32_add(fp32_t *pt_c, fp32_t t_a, fp32_t t_b);

/* Compute the subtraction of two IEEE-754 floating-point numbers. */
int fp32_sub(fp32_t *pt_c, fp32_t t_a, fp32_t t_b);

/* Compute the multiplication of two IEEE-754 floating-point numbers. */
int fp32_mul(fp32_t *pt_c, fp32_t t_a, fp32_t t_b);

/* Compute the division of two IEEE-754 floating-point numbers. */
int fp32_div(fp32_t *pt_c, fp32_t t_a, fp32_t t_b);