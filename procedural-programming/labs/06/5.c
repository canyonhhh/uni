#include <stdio.h>
#include <string.h>
#define GOOD_INPUT "Input received.\n"
#define BAD_INPUT "Incorrect input. Try again.\n"

char *strrev(char *str){
    char *p1, *p2;
    if (! str || ! *str){
	return str;
    }
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
	*p1 ^= *p2;
	*p2 ^= *p1;
	*p1 ^= *p2;
    }
    return str;
}


int main(){
    printf("This program takes in an email adress, checks if it is valid, and appends it to emails.txt.\n");
    printf("Input an email:\n");

    char email[50], domain[50], test1[50], test[50], ch;
    int correctInput = 0;
    FILE *outFile;

    while (!correctInput){
	ch = ' ';
	scanf("%s", email);
	if (sscanf(email, "%49[^\t\n@]@%49[^@]", test, domain) == 2){
	    strrev(domain);
	    if (sscanf(domain, "%[^@\t\n.].%[^@\t\n.]%c", test1, test, &ch) == 2 && ch != '.'){
		printf(GOOD_INPUT);
		correctInput = 1;
	    }
	    else{
		printf(BAD_INPUT);
	    }
	}
	else{
	    printf(BAD_INPUT);
	    while (getchar() != '\n')
		;
	}
    }

    printf("Domain name: %s\n", strrev(domain));

    outFile = fopen("emails.txt", "a");
    if (outFile != NULL){
	printf("Output file created, email appended.\n");
	fprintf(outFile, "%s\n", email);
    }
    else{
	printf("Could not open output file.\n");
    }
}
