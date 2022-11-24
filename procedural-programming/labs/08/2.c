#include <stdio.h>
#include <stdlib.h>

long getFileSize(char *fileName){
    FILE *file = fopen(fileName, "r");
    long size;
    if (file != NULL){
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fclose(file);
	return size;
    }
    else{
	return -1;
    }
}

char *getLargestFile(int fileCount, char **fileName){

    int maxSize = -1, maxIndex;
    for(int i = 1; i <= fileCount; ++i){
	int fileSize = getFileSize(fileName[i]);
	if (fileSize > maxSize){
	    maxSize = fileSize;
	    maxIndex = i;
	}
    }
    return fileName[maxIndex];
}

int main(int argc, char *argv[]){
    printf("%s\n", getLargestFile(argc - 1, argv));
}
