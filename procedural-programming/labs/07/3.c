#include <stdio.h>

int getPositiveNumber(char *msg){
    int number, inputCorrect = 0;
    do{
	printf("%s", msg);
	if (scanf("%d", &number) == 1 && getchar() == '\n'){
	    inputCorrect = 1;
	}
	else{
	    while (getchar() != '\n')
		;
	}
    } while (!inputCorrect);
    return number;
}

int main(){
    int number = getPositiveNumber("Enter a postive integer.\n");
}
