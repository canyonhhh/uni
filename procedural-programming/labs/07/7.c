#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long getFileSize(FILE *file){
    long size = 0;
    if (file != NULL){
	long int current = ftell(file), end;
	fseek(file, 0, SEEK_END);
	end = ftell(file);
	fseek(file, current, SEEK_SET);
	return end;
   }
    else{
	return -1;
    }
}

int getValue(FILE *file, long index){
    if ((index >= 0) && (index < getFileSize(file))){
	int value;
	fseek(file, index, SEEK_SET);
	fread(&value, 1, 1, file);
	return value;
    }
    else{
	return -1;
    }
    
    return 0;
}
int setValue(FILE *file, long index, int value){

    if (index >= 0 && index < getFileSize(file)){
	fseek(file, index, SEEK_SET);
	fwrite(&value, 1, 1, file);
	return 0;
    }
    else{
	return -1;
    }
}

int addValue(FILE *file, long index, int value){
    long fileSize = getFileSize(file);
    if (index >= 0 && index <= fileSize){
	char *buffer = malloc(fileSize - index);
	fseek(file, index, SEEK_SET);
	fread(buffer, 1, fileSize - index, file);
	fseek(file, index, SEEK_SET);
	fwrite(&value, 1, 1, file);
	fwrite(buffer, 1, fileSize - index, file);
	free(buffer);
	return 0;
    }
    else{
	return -1;
    }
}

int remValue(FILE *file, long index){
    long fileSize = getFileSize(file);
    if (index >= 0 && index < fileSize){
	char *readingBuffer = malloc(fileSize - 1), *writingBuffer = malloc(fileSize - 1);
	fseek(file, 0, SEEK_SET);
	fread(writingBuffer, 1, index, file);
	fseek(file, index + 1, SEEK_SET);
	fread(readingBuffer, 1, fileSize - index - 1, file);
	strcat(writingBuffer, readingBuffer);
	freopen(NULL, "wb+", file);
	fwrite(writingBuffer, 1, fileSize - 1, file);
	free(readingBuffer);
	free(writingBuffer);
	return 0;
    }
    else{
	return -1;
    }
}

int main(){
    FILE *input = fopen("in.bin", "rb+");
    printf("%x\n", getValue(input, 6));
    setValue(input, 8, 0x24);
    addValue(input, 6, 0x5a);
    remValue(input, 7);
    fclose(input);
}
