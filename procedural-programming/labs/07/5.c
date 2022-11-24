#include <stdio.h>

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

int main(){
    printf("%ld\n", getFileSize("1.c"));
}
