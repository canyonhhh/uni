#include <stdio.h>

int main()
{
    int num[3] = {1, 2, 3}, max = 0, min = 0;
    printf("Irasykite tris skaicius:\n");
    //scanf("%d %d %d", &num[0], &num[1], &num[2]);
    

    num[0] > num[1] && num[0] > num[2] ? (max = 0) : (num[1] > num[2] ? (max = 1) : (max = 2));
    num[0] < num[1] && num[0] < num[2] ? (min = 0) : (num[1] < num[2] ? (min = 1) : (min = 2));
    printf("max: %d\n", num[max]);
    printf("min: %d\n", num[min]);
}
