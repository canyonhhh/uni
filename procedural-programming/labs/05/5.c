#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAD_INPUT "Incorrect input.\n"
#define GOOD_INPUT "Input received.\n"

#define CAPACITY 1000

int main(){
    srand(time(NULL));

    printf("This program takes the input x and n, then takes n positive integers and outputs if the entered positive integers can be made using the digits of the number x.\n");

    int x, num, n, numArray[CAPACITY];
    printf("Input x and n:\n");
    scanf("%d %d", &x, &n);

    int xArray[CAPACITY], xCopy = x, xLength = 0;
    while(xCopy > 0){
	xArray[xLength] = xCopy % 10 + 10; // Noredamas isvengti kopijavimo cia pridedu 10, kad pradejus skaiciuoti pirmas ciklas isliktu vienodas
	xCopy /= 10;
	++xLength;
    }

    //printf("Input n positive integers:\n");
    for (int i = 0; i < n; ++i){
	//numArray[i] = (rand() % 1000) + 1;
	if (scanf("%d", &num) == 1 && getchar() == '\n' && num >= 0){
	    printf(GOOD_INPUT);
	    numArray[i] = num;
	}
	else{
	    printf(BAD_INPUT);
	    --i;
	    while(getchar() != '\n')
		;
	}
    }

    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < xLength; ++j){
	    if (xArray[j] > 9) {
		xArray[j] -= 10; // skaiciaus x array atstatoma i pradini varianta
	    }
	}

	int temp = numArray[i];

	int possibleToConstruct = 1;
	while (numArray[i] > 0 && possibleToConstruct){
	    int j, digit = numArray[i] % 10;

	    for (j = 0; j < xLength; ++j){ // Ciklas yra nutraukiamas, jeigu randamas tinkamas skaitmuo
		if (digit == xArray[j]){
		    xArray[j] += 10; // Kad daugiau nebebutu naudojamas
		    break;
		}
	    }
	    if (j == xLength){
		possibleToConstruct = 0;
	    }
	    numArray[i] /= 10;
	}
	printf("%d %spossible to construct\n", temp, possibleToConstruct == 1 ? "" : "not "); 
    }
}
