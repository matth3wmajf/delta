#include <delta/fp32.h>

/* ... */
int fp32_add(fp32_t *pt_c, fp32_t t_a, fp32_t t_b)
{
/* Extract the sign from the first operand. */
	uint32_t l_a_sign = (t_a & 0b10000000000000000000000000000000) >> 31;

/* Extract the sign from the second operand. */
	uint32_t l_b_sign = (t_b & 0b10000000000000000000000000000000) >> 31;

/* Extract the exponent from the first operand. */
	uint32_t l_a_exponent = (t_a & 0b01111111100000000000000000000000) >> 23;

/* Extract the exponent from the second operand. */
	uint32_t l_b_exponent = (t_b & 0b01111111100000000000000000000000) >> 23;

/* Extract the mantissa from the first operand. */
	uint32_t l_a_mantissa = t_a & 0b00000000011111111111111111111111;

/* Extract the mantissa from the second operand. */
	uint32_t l_b_mantissa = t_b & 0b00000000011111111111111111111111;

/* Handle special cases for the first operand. */
	if(l_a_exponent == 0b00000000000000000000000011111111)
	{
/* Set the result to the first operand. */
		*pt_c = t_a;

/* Return with success. */
		return 0;
	}

/* Handle special cases for the second operand. */
	if(l_b_exponent == 0b00000000000000000000000011111111)
	{
/* Set the result to the second operand. */
		*pt_c = t_b;

/* ... */
		return 0;
	}

/*
 *	Add an implicit set bit to mantissa, but only for non-zero exponents.
 *	Apply this for the first & second operands' mantissas.
 */
	if(l_a_exponent != 0) l_a_mantissa |= 0b00000000100000000000000000000000;
	if(l_b_exponent != 0) l_b_mantissa |= 0b00000000100000000000000000000000;

/* Align the exponents, to ensure compatibility. */
	if(l_a_exponent > l_b_exponent)
	{
		l_b_mantissa >>= (l_a_exponent - l_b_exponent);
		l_b_exponent = l_a_exponent;
	}
	else if(l_b_exponent > l_a_exponent)
	{
		l_a_mantissa >>= (l_b_exponent - l_a_exponent);
		l_a_exponent = l_b_exponent;
	}

/*
 *	The mantissa & sign of the result, which'll be incorporated into the final
 *	result.
 */
	uint32_t l_c_mantissa;
	uint32_t l_c_sign;

/* Handle the addition or the subtraction, depending on the signs. */
	if(l_a_sign == l_b_sign)
	{
/* If the signs are the same, then add the mantissas. */
		l_c_mantissa = l_a_mantissa + l_b_mantissa;
		l_c_sign = l_a_sign;
	}
	else
	{
/* If the signs are different, then subtract the mantissas. */
		if(l_a_mantissa > l_b_mantissa)
		{
/*
 *	If the first operand's mantissa is larger than the second operand's
 *	mantissa, then set the result's mantissa to the difference between the
 *	first operand's mantissa and the second operand's mantissa.
 *	After that, set the result's sign to the first operand's sign.
 */
			l_c_mantissa = l_a_mantissa - l_b_mantissa;
			l_c_sign = l_a_sign;
		}
		else
		{
/*
 *	Otherwise, then we subtract the first operand's mantissa from the first
 *	operand's mantissa.
 */
			l_c_mantissa = l_b_mantissa - l_a_mantissa;
			l_c_sign = l_b_sign;
		}
	}

/* Normalize the result's mantissa, if necessary. */
	if(l_c_mantissa & 0b00000001000000000000000000000000)
	{
		l_c_mantissa >>= 1;

/* If that's the case, then we increment the exponent. */
		l_a_exponent++;
	}

/* Clear the implicit bit from the mantissa. */
	l_c_mantissa &= 0b00000000011111111111111111111111;

/* Set the result, by incorporating the computed sign, exponent & mantissa. */
	*pt_c = (l_c_sign << 31) | (l_a_exponent << 23) | l_c_mantissa;

/* Return with success. */
	return 0;
}

/* ... */
int fp32_sub(fp32_t *pt_c, fp32_t t_a, fp32_t t_b)
{
/* Invert the sign of the second operand. */
	fp32_t l_d = (fp32_t)(t_b) ^ 0b10000000000000000000000000000000;

/* Call the addition function. */
	fp32_add(pt_c, t_a, l_d);

/* Return with success. */
	return 0;
}