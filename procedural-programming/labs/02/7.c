#include <stdio.h>

int sortDigits(int num, int length)
{
    int naujasNum = 0, digit;

    for (int i = 9; i >= 0; i--)
    {
	int numCopy = num;
	while (numCopy > 0)
	{
	    digit = numCopy % 10;
	    if (digit == i)
	    {
		naujasNum *= 10;
		if (digit != 0)
		{
		    naujasNum += digit;
		}
	    }
	    numCopy /= 10;
	}
    }
    return naujasNum;
}

int main()
{
    int num = 234567890;
    printf("Irasykite skaiciu, bus isvesti isrikiuoti jo skaitmenys:\n");
    //scanf("%d", &num);
    int length = 1, numCopy = num;

    while (numCopy > 0)
    {
	for (length = 0; numCopy > 0; length++)
	{
	    numCopy /= 10;
	}
    }
    printf("%d\n", sortDigits(num, length));
}
