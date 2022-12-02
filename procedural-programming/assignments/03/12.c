/*
 *Made by Joris Lisas
 *This program takes in an input file and
 *Outputs the found palindromes either in a provided output file or stdout
 *Usage: ./12 in.txt out.txt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAX_PATH_LENGTH 260

#define MALLOC_ERR "Could not allocate memory. Exiting.\n"

void cleanBuffer();
int getFileStream(char *mode, FILE **fileStream);
int checkFiles(int argc, char **argv, FILE **inFile, FILE **outFile);
int checkIfPalindrome(char *string);
void partialReadCleanup(char *readingBuffer, char *extraBuffer, int *offset);

void cleanBuffer(){
    while (getchar() != '\n')
	;
}

void partialReadCleanup(char *readingBuffer, char *extraBuffer, int *offset){
    *offset = BUFFER_SIZE - (strrchr(readingBuffer, ' ') - readingBuffer + 1);
    memcpy(extraBuffer, readingBuffer + BUFFER_SIZE - *offset, sizeof(char) * (*offset));
    *(readingBuffer + BUFFER_SIZE - *offset) = '\0';
}

int getFileStream(char *mode, FILE **fileStream){
    int inputIsCorrect = 0;
    char *filename = calloc(sizeof(char), MAX_PATH_LENGTH);
    char *formatString = calloc(sizeof(char), 6);

    if (filename == NULL || formatString == NULL){
	return 1;
    }
    
    sprintf(formatString, "%%%ds", MAX_PATH_LENGTH);

    while (!inputIsCorrect){
	printf("Please input the filename:\n");
	if (scanf(formatString, filename) != 1 || getchar() != '\n'){ 
	    cleanBuffer();
	}
	else if ((*fileStream = fopen(filename, mode)) != NULL){
	    inputIsCorrect = 1;
	}
    }
    free(filename);
    free(formatString);
    return 0;
}

int checkFiles(int argc, char **argv, FILE **inFile, FILE **outFile){
    if (argc < 4){
	if (argc == 1 || (*inFile = fopen(argv[1], "r")) == NULL){
	    printf("Could not open input file.\n");
	    if (getFileStream("r", inFile) == 1){
		return 1;
	    }
	}
	if (argc < 3 || (*outFile = fopen(argv[2], "w")) == NULL){
	    printf("No output file provided, writing to stdout.\n");
	    *outFile = stdout;
	}
	return 0;
    } else{
	printf("Usage: ./12 inputfile.txt outputfile.txt\n");
	return 1;
    }
}

int checkIfPalindrome(char *string){
    int len = strlen(string);
    char *p;
    if (len < 1){
	return 0;
    }
    
    for (p = string + len - 1; string < p; ++string, --p){
	if (*p != *string){
	    return 0;
	}
    }
    return 1;
}

int main(int argc, char **argv){

    FILE *inFile, *outFile;
    char *readingBuffer = calloc(BUFFER_SIZE, sizeof(char)), *extraBuffer = calloc(BUFFER_SIZE, sizeof(char));
    char *word = calloc(BUFFER_SIZE, sizeof(char));

    int offset, partialRead = 0;

    if (readingBuffer == NULL || extraBuffer == NULL || word == NULL || checkFiles(argc, argv, &inFile, &outFile) == 1){
	printf(MALLOC_ERR);
	return 1;
    }

    while (!feof(inFile)){

	int elementsRead = fread(readingBuffer + offset, sizeof(char), BUFFER_SIZE - offset, inFile);

	if (feof(inFile) && elementsRead != BUFFER_SIZE){
	    *(readingBuffer + offset + elementsRead) = '\0';
	}

	if (!feof(inFile) && readingBuffer[BUFFER_SIZE - 1] != ' '){
	    partialReadCleanup(readingBuffer, extraBuffer, &offset);
	    partialRead = 1;
	} else{
	    partialRead = 0;
	    offset = 0;
	}

	int totalRead = 0, bytesRead;
	while (sscanf(readingBuffer + totalRead, "%s%n", word, &bytesRead) == 1){
	    totalRead += bytesRead;
	    if (checkIfPalindrome(word)){
		fwrite(word, sizeof(char), strlen(word), outFile);
		fwrite("\n", sizeof(char), strlen("\n"), outFile);
	    }
	}
	if (partialRead){
	    memcpy(readingBuffer, extraBuffer, sizeof(char) * offset);
	}
    }
    
    free(readingBuffer);
    free(extraBuffer);
    free(word);

    fclose(outFile);
    fclose(inFile);
}
