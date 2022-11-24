#include <stdio.h>

void decimalToBinary(int num)
{
    if (num > 1)
    {
	decimalToBinary(num / 2);
    }
    printf("%i", num % 2);
}

void binaryToDecimal(long num)
{
    int counter = 1, decimal = 0;
    while (num > 0)
    {
	decimal += (num % 10) * counter;
	num /= 10;
	counter *= 2;
    }
    printf("%d", decimal);
}

int main()
{
    binaryToDecimal(11011);
    printf(" ");

    binaryToDecimal(10010100);
    printf(" ");

    binaryToDecimal(11001011010101);
    printf("\n");

    decimalToBinary(37);
    printf(" ");

    decimalToBinary(241);
    printf(" ");

    decimalToBinary(2487);
    printf("\n");

    printf("%i %i %i\n", 0x6E2, 0xED33, 0x123456);
    printf("0x%X 0x%X 0x%X\n", 243, 2483, 4612);
}



