#include <stdio.h>
#include <stdint.h>

int main( void )
{
    int32_t n = 123;

    const int32_t divisor = 10;
    const int64_t recp = ((int64_t)1 << 32) / divisor;
	printf("recp: %lld\n", recp);
    //000000000001 000000000000 <- (int64_t)1 << 32) //< make 1 to fixed_point
    //000000000000 000110011001 <- (1 / 10) in fixed_point

    int64_t tmp = n * recp;
    //000000001100 010010000011 <- High_32bit : 12   Low_32bit : 0.3

    int32_t result = tmp >> 32;

    printf("%d", result);

    return 0;
}