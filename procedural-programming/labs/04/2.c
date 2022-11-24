#include <stdio.h>
#include <math.h>

int main(){
    printf("Si programa priima tris sveikus skaicius a, b, c ir atspausdina visus skaicius intervale (a; b], kurie dalinasi is skaiciaus c, su liekana 1\n");
    printf("Iveskite tris sveikus skaicius:\n");

    int a, b, c;

    if (scanf("%d %d %d", &a, &b, &c) != 3){
	printf("Ivestis neteisinga\n");
	return 1;
    }

    printf("Ivestis priimta sekmingai\n");

    for (int i = a + 1; i <= b; ++i){
	if (i % c == 1){
	    printf("%d\n", i);
	}
    }
}
