#include <stdio.h>

int main()
{
    int num = 123, indicator;

    printf("Irasykite skaiciu:\n");
    //scanf("%d", &num);

    char result[2][10] = {"Lyginis", "Nelyginis"};
   
    num % 2 == 0 ? (indicator = 0) : (indicator = 1); 

    printf("%s\n", result[indicator]);
}
