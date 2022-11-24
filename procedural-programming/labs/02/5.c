#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x = 1, y = 2, z = 3;

    printf("Irasykite tris realiuosius skaicius:\n");
    //scanf("%lf %lf %lf", &x, &y, &z);

    printf("%.3f\n", x + 4 * y + pow(z, 3));
    printf("%.3f\n", (x + sqrt(y)) * (pow(z, 4) - fabs(y) + 46.3));
}
