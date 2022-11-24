#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACITY 1000

int main(){

    srand(time(NULL));

    int a, b, c, randArray[CAPACITY];
    printf("This program takes three numbers a, b and c [0; %d], generates %d random numbers [a; b], and then prints c such numbers.\n", CAPACITY, CAPACITY);
    printf("Input: \n");

    if(scanf("%d %d %d", &a, &b, &c) != 3 || c > CAPACITY || b < a){
	printf("Incorrect input.\n");
	return 0;
    }
    printf("Input received.\n");
    
    // Array generation
    for (int i = 0; i < CAPACITY; ++i){
	randArray[i] = (rand() % (b + 1 - a))  + a;
    }

    printf("Results:\n");
    // Output
    for (int i = 0; i < c; ++i){
	printf("%d\n", randArray[i]);
    }
}
