#include <stdio.h>
#include <math.h>

int main(){
    printf("Si programa priima tris sveikus skaicius a, b, c ir c-ąjį skaičių fc, kur fc=fc-1+fc-2, o f0 = a ir f1 = b\n");
    printf("Iveskite tris sveikus skaicius:\n");
    int a, b, c;

    if(scanf("%d %d %d", &a, &b, &c) != 3){
	printf("Ivestis neteisinga\n");
	return 1;
    }

    printf("Ivestis priimta\n");

    printf("%d\n%d\n", a, b);

    for (int i = 1; i < c; ++i){
	b = a + b;
	printf("%d\n", b);
	a = b - a;
    }


}
