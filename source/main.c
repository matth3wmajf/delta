#include <stdio.h>

#include <math.h>

#include <delta/fp32.h>

int main()
{
	float_t l_a = 3.0f, l_b = 2.0f, l_c = 0.0f;

	printf("l_a = %f l_b = %f l_c = %f\n", l_a, l_b, l_c);

	fp32_mul((fp32_t*)&l_c, *(fp32_t*)&l_a, *(fp32_t*)&l_b);

	printf("l_a = %f l_b = %f l_c = %f\n", l_a, l_b, l_c);

	return 0;
}