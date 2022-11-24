#include <stdio.h>
#include <math.h>

void decToBase(int number, int base)
{
    if (number > 1)
    {
	decToBase(number / base, base);
    }
    if (number % base > 9 && number != 0)
    {
	printf("%c", (char)(number % base + 55));
    }
    else if (number != 0)
    {
	printf("%d", number % base);
    }
}

void baseConversion(int sourceBase, int destBase, char num[10])
{
    // Tarpinis vertimas i base10
    int base10 = 0, counter = 0;

    for (int i = 9; i > -1; i--)
    {
	if (num[i] <= '9' && num[i] >= '0')
	{
	    base10 += ((int)num[i] - 48) * pow(sourceBase, counter);
	}
	else if (num[i] <= 'z' && num[i] >= 'a')
	{
	    base10 += ((int)num[i] - 87) * pow(sourceBase, counter);
	}
	else if (num[i] <= 'Z' && num[i] >= 'A')
	{
	    base10 += ((int)num[i] - 55) * pow(sourceBase, counter);
	}
	else
	{
	    continue;
	}
	counter++;
    }

    // Vertimas i norima base
    decToBase(base10, destBase);
    printf("\n");
}

int main()
{
    int x, y;
    char num[10];
    printf("Irasykite pradinio skaiciaus pagrinda (base)(2-36):\n");
    scanf("%d", &x);
    printf("Irasykite norima nauja skaiciaus pagrinda (base)(2-36):\n");
    scanf("%d", &y);
    printf("Irasykite skaiciu (be prierasu 0x)(didziosios ir mazosios raides laikomos vienodomis):\n");
    scanf("%s", num);

    baseConversion(x, y, num);
}
