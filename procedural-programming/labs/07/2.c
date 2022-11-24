#include <stdio.h>

int getFactorialRecursion(int number){
    if (number < 0){
	return 0;
    }
    if (number > 0){
	return number * getFactorialRecursion(number - 1);
    }
    else{
	return 1;
    }
}

int getFactorialIteration(int number){
    if (number < 0){
	return 0;
    }
    int factorial = 1;
    while (number > 0){
	factorial *= number--;
    }
    return factorial;
}

int main(){
    printf("%d\n", getFactorialIteration(10));
    printf("%d\n", getFactorialRecursion(10));
}
