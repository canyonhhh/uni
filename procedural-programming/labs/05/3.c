#include <stdio.h>

#define BAD_INPUT "Input positive numbers.\n"
#define GOOD_INPUT "Input received.\n"

int main(){
    int s, n;
    printf("This program takes in two positive numbers - s and n, then takes in n new numbers, prints every pair of those numbers, whose multiplication results in the number s.\n");
    printf("\nInput s and n:\n");
    if (scanf("%d %d", &s, &n) && n > 0 && s > 0){
	printf(GOOD_INPUT);
    }
    else{
	printf(BAD_INPUT);
	return 1;
    }

    int x[n], counter = 0, temp;

    printf("Input %d positive numbers:\n", n);

    while (counter < n){
	if (scanf("%d", &temp) == 1 && getchar() == '\n' && temp > 0){
	    x[counter++] = temp;
	}
	else{
	    printf(BAD_INPUT);
	    while(getchar() != '\n')
		;
	}
    }

    printf("Results:\n");

    for (int i = 0; i < n - 1; ++i){
	for (int j = i + 1; j < n; ++j){
	    if (x[i] * x[j] == s){
		printf("%d %d\n", x[i], x[j]);
	    }
	}
    }
}
