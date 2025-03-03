#include <stdio.h>

#include <math.h>

#include <delta/fp32.h>

int main()
{
	float_t l_a = 1.0, l_b = 2.0, l_c = 0.0f;

	printf("Dividing X by 2, 32 times, starting with X being set to 1...\n");

	for(int l_i = 0; l_i < 32; l_i++)
	{
		fp32_div((fp32_t*)&l_c, *(fp32_t*)&l_a, *(fp32_t*)&l_b);

		printf("%.16f / %.16f = %.16f\n", l_a, l_b, l_c);

		l_a = l_c;
	}

	return 0;
}
