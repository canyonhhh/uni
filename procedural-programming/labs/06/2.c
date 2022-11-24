#include <stdio.h>
#include <string.h>

#define GOOD_INPUT "Input received.\n"
#define BAD_INPUT "Input is incorrect or out of bounds. Try a different file.\n"

int countDigits(int num){
    int digits = 0;
    while (num > 0){
	num /= 10;
	++digits;
    }
    return digits;
}

int main(){
    printf("In a file named in.txt, write a real number (decimal point indicated with a comma). The whole part should be in the range of [10; 1000], and the decimal part up to three digits in length.\n");

    int whole, decimal = 0, length = 0;
    char decimalString[4];

    FILE *inFile;
    inFile = fopen("in.txt", "r");

    if (fscanf(inFile, "%d", &whole) == 1 && whole < 1000 && whole > 9){
	char seperator = fgetc(inFile);
	// First read as string because of cases like 023 (otherwise it would be read as 23).
	if (seperator == ','){ 
	    if (fscanf(inFile, "%3[0-9]", decimalString) == 1 && fgetc(inFile) == '\n'){
		printf(GOOD_INPUT);
	    }
	    else{
		printf(BAD_INPUT);
		return 1;
	    }
	}
	else if (seperator == '\n'){
	    printf(GOOD_INPUT);
	}
	else{
	    printf(BAD_INPUT);
	    return 1;
	}
    }
    else{
	printf(BAD_INPUT);
	return 1;
    }

    length = countDigits(whole) + strlen(decimalString);

    printf("Length of the provided number:\n%d\n", length);
}
