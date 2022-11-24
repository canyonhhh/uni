#include <stdio.h>
#include <string.h>
#include <limits.h>

#define GOOD_INPUT "Input received.\n"
#define BAD_INPUT "Incorrect input. Try again.\n"

// Linux gcc string.h nera strrev, tai reikia naudoti savadarbi
char *strrev(char *str){
    if (!str || ! *str){
	return str;
    }

    int i = strlen(str) - 1, j = 0;
    char ch;
    while (i > j){
	ch = str[i];
	str[i] = str[j];
	str[j] = ch;
	i--;
	j++;
    }
    return str;
}

int median(int x, int y, int z){
    if (x <= y && y <= z)
	return y;
    if (z <= x && x <= y)
	return x;
    if (x <= z && z <= y)
	return z;
    if (z <= y && y <= x)
	return y;
    if (y <= x && x <= z)
	return x;
    if (y <= z && z <= x)
	return z;
    return y;
}

int main(){
    int x, y, z, correctInput = 0 , max = INT_MIN;
    char filename[20], testForTxt[5];

    printf("This program takes in three integers and outputs their median in a file the user provided.\n");
    printf("Input any three integers, seperated with semicolons:\n");
    while(!correctInput){
	if (scanf("%d;%d;%d", &x, &y, &z) == 3 && getchar() == '\n'){
	    printf(GOOD_INPUT);
	    correctInput = 1;
	}
	else{
	    printf(BAD_INPUT);
	    while (getchar() != '\n')
		;
	}
    }

    correctInput = 0;
    printf("Input output file name (.txt):\n");
    while(!correctInput){
	if(scanf("%19s", filename) != 1 || getchar() != '\n'){
	    printf(BAD_INPUT);
	    while (getchar() != '\n')
		;
	}
	else if(sscanf(strrev(filename), "%4s", testForTxt) == 1 && strlen(filename) > 4){
	    if (!strcmp(testForTxt, "txt.")){
		strrev(filename);
		printf(GOOD_INPUT);
		correctInput = 1;
	    }
	    else{
		printf(BAD_INPUT);
	    }
	}
	else{
	    printf(BAD_INPUT);
	}
    }

    FILE *outFile;
    outFile = fopen(filename, "w");
    
    if (outFile != NULL){
	printf("%s created successfuly.\n", filename);
	fprintf(outFile, "%d\n", median(x, y, z));
    }
    else{
	printf("Could not create %s\n", filename);
	return 1;
    }

}
