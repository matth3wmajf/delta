#include <stdio.h>

#include <math.h>

#include <delta/fp32.h>

int main()
{
	float_t l_a, l_b, l_c;

	l_a = 0.0f, l_b = 0.1f, l_c = 0.0f;

        printf("Adding 0.1 to X, 32 times, starting with X being set to 0...\n");

        for(int l_i = 0; l_i < 32; l_i++)
        {
                fp32_add((fp32_t*)&l_c, *(fp32_t*)&l_a, *(fp32_t*)&l_b);

                printf("%.16f + %.16f = %.16f\n", l_a, l_b, l_c);

                l_a = l_c;
        }

        l_a = 1.0f, l_b = 0.1f, l_c = 0.0f;

        printf("Subtracting 0.1 from X, 32 times, starting with X being set to 1...\n");

        for(int l_i = 0; l_i < 32; l_i++)
        {
                fp32_sub((fp32_t*)&l_c, *(fp32_t*)&l_a, *(fp32_t*)&l_b);

                printf("%.16f - %.16f = %.16f\n", l_a, l_b, l_c);

                l_a = l_c;
        }

	l_a = 1.0f, l_b = 0.1f, l_c = 0.0f;

        printf("Multiplying X by 0.1, 32 times, starting with X being set to 1...\n");

        for(int l_i = 0; l_i < 32; l_i++)
        {
                fp32_mul((fp32_t*)&l_c, *(fp32_t*)&l_a, *(fp32_t*)&l_b);

                printf("%.16f / %.16f = %.16f\n", l_a, l_b, l_c);

                l_a = l_c;
        }

	l_a = 1.0f, l_b = 2.0f, l_c = 0.0f;

	printf("Dividing X by 2, 32 times, starting with X being set to 1...\n");

	for(int l_i = 0; l_i < 32; l_i++)
	{
		fp32_div((fp32_t*)&l_c, *(fp32_t*)&l_a, *(fp32_t*)&l_b);

		printf("%.16f * %.16f = %.16f\n", l_a, l_b, l_c);

		l_a = l_c;
	}

	return 0;
}
