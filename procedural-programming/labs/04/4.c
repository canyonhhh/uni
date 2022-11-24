#include <stdio.h>
#include <math.h>

int main(){
    printf("Si programa priima tris naturalius skaicius a, b, c ir atspausdina siu skaiciu DBD ir MBK\n");
    printf("Iveskite tris sveikus skaicius:\n");
    int a, b, c;

    if (scanf("%d %d %d", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0){
	printf("Ivestis neteisinga\n");
	return 1;
    }

    printf("Ivestis priimta\n");

    for (int i = 1; i < a * b *c; ++i){// Breaks when MBK is found
	if (i % a == 0 && i % b == 0 && i % c == 0){
	    printf ("MBK=:%d\n", i);
	    break;
	}
    }
    for (int i = a; i > 0; i--){// Breaks when DBD is found
	if (a % i == 0 && b % i == 0 && c % i == 0){
	    printf("DBD=%d\n", i);
	    break;
	}
    }
}
