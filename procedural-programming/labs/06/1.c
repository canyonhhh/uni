#include <stdio.h>

#define GOOD_INPUT "Input received.\n"
#define BAD_INPUT "Only positive whole numbers up to 20 are allowed!\n"

int main(){

    FILE *outFile;
    outFile = fopen("out.txt", "w");
    long long int factorial = 1, inputIsCorrect = 0;
    int num;
    
    printf("Input a positive integer, its factorial will be output to out.txt, in the working directory.\n");

    // Input
    while (!inputIsCorrect){
	if (scanf("%d", &num) != 1 || getchar() != '\n'){
	    printf(BAD_INPUT);
	    while (getchar() != '\n')
		;
	}
	else if(num < 0 || num > 20){
	    printf(BAD_INPUT);
	}
	else{
	    inputIsCorrect = 1;
	    printf(GOOD_INPUT);
	}
    }
    
    // Factorial Calculation
    while (num > 0){
	factorial *= num--;
    }

    // Output
    if (outFile != NULL){
	fprintf(outFile, "%lld", factorial);
	printf("File created, factorial output succesfully\n");
    }
    else{
	printf("Could not create output file.\n");
    }
    fclose(outFile);
}
