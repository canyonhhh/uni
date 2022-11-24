#include <stdio.h>
#include <math.h>

int main(){
    printf("Iveskite tris sveikus skaicius:\n");

    int a, b, c, discriminant;
    if(scanf("%d %d %d", &a, &b, &c) != 3){
	printf("Ivestis neteisinga\n");
	return 1;
    }

    printf("Ivestis priimta\n");

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0){
	printf("2\n");
	printf("%f %f\n", (-b + (float)sqrt(discriminant)) / 2 * a, (-b - (float)sqrt(discriminant)) / 2 * a);
    }
    else if (discriminant == 0){
	printf("1\n");
	printf("%f\n", (float)-b / (2 * (float)a));
    }
    else {
	printf("Sprendiniu neturi\n");
    }
}
