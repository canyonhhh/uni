#include <stdio.h>

#define BAD_INPUT "Incorrect input.\n"
#define GOOD_INPUT "Input received.\n"

#define CAPACITY 1000

int main(){
    printf("This program takes in a sequence of positive integers, until a negative integer is entered\n");
    printf("It then prints every unique prime the user entered.\n");

    int array[CAPACITY] = {0}, counter = 0, num;

    printf("Input the sequence:\n");
    // Input
    do{
	if (scanf("%9d", &num) == 1 && getchar() == '\n'){
	    printf(GOOD_INPUT);
	    if (num > 0){
		array[counter++] = num;
	    }
	}
	else{
	    printf(BAD_INPUT);
	    while (getchar() != '\n')
		;
	}
    } while (num > 0);
    
    int primes[CAPACITY], primeCounter = 0;


    // Finding and storing primes
    for (int i = 0; i < counter; ++i){

	num = array[i];
	int divisors = 0;

	for (int j = 1; j < num; ++j){
	    if (num % j == 0){
		++divisors;
	    }
	}
	if (divisors == 1){
	    primes[primeCounter++] = num;
	}
    }

    printf("Primes:\n");
    // Printing non duplicate primes
    for (int i = 0; i < primeCounter; ++i){
	for (int j = i + 1; j < primeCounter; ++j){
	    if (primes[i] == primes[j]){
		primes[j] = 0;
	    }
	}
	if (primes[i] != 0){
	    printf("%d\n", primes[i]);
	}
    }
}
