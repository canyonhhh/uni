#include <stdio.h>
#include <math.h>

int digitFinder(float num){
    int digits = 0, numCopy = num;

    if (num < 1){
	digits = 1;
    }

    while (fmod(num, 1) > 0){
	num *= 10;
    }

    while (num > 1){
	num /= 10;
	++digits;
    }

    return digits;
}

int main(){
    printf("Si programa priima teigiamu skaiciu seka, kurios pabaiga zymima neigiamu skaiciu, isveda daugiausiai skaitmenu turinti skaiciu.\n");
    printf("Iveskite skaiciu seka:\n");

    float num = 0, maxDigitsNum;
    int maxDigits = 0, digits;

    do{
	while (!scanf("%f", &num) && getchar() != '\n'){
	    printf("Ivestis neteisinga\n");
	}
	if (num > 0){
	    printf("Skaicius priimtas\n");

	    digits = digitFinder(num);
	    printf("%d\n", digits);

	    if (digits > maxDigits){
		maxDigits = digits;
		maxDigitsNum = num;
	    }
	}
    }while(num > 0);

    printf("Ilgiausias skaicius:\n%f\n", maxDigitsNum);
}
