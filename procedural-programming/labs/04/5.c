#include <stdio.h>
#include <math.h>

int main(){
    printf("Si programa priima tris naturalius skaicius a, b, c ir atspausdina siu skaiciu DBD ir MBK\n");
    printf("Iveskite naturalu skaiciu n, tada iveskite n naturaliu  skaiciu seka:\n");
    int n;
    float temp, min = 2147483647.0, max = 0, suma = 0;

    if (scanf("%d", &n) != 1){
	printf("Ivestis neteisinga");
	return 1;
    }

    for (int i = 0; i < n; ++i){
	scanf("%f", &temp);
	suma += temp;
	if (temp > max){
	    max = temp;
	}
	if (temp < min){
	    min = temp;
	}
    }

    printf ("AVG=%f\n", (float)suma / n);
    printf ("MIN=%f\n", min);
    printf ("MAX=%f\n", max);
}
