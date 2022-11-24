// Made by Joris Lisas
// This C program takes in a sequence of integers
// And outputs how many zeros, positive and negative integers were entered.
#include <stdio.h>

int main()
{
    int pos = 0, neg = 0, zero = 0, match = 0;
    long long int num, previous = 0;
    printf("Input a sequence of integers, marking the ending by entering two indentical numbers. The program count how many zeros, positive and negative integers you put in.\n");

    while (!match){
	if ((scanf("%19lld", &num) == 1) && (getchar() == '\n')){
	    printf("Input received.\n");
	    if (num > 0){
		++pos;
	    }
	    else if (num < 0){
		++neg;
	    }
	    else{
		++zero;
	    }
	    if (previous == num){
		match = 1; // If the current num matches the previous, the loop will not continue
	    }
	    else{
		previous = num;
	    }
	}
	else{
	    printf("Incorrect input.\n");
	    while (getchar() != '\n')
		;
	}
    }
    
    printf("Positive: %*d\n", 5, pos);
    printf("Negative: %*d\n", 5, neg);
    printf("Zeros: %*d\n", 5, zero);
    printf("Total: %*d\n", 5, pos + neg + zero);

    return 0;
}
