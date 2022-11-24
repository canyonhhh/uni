#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int *array, int size, int low, int high){
    srand(time(NULL));
    for(int i = 0; i < size; ++i){
	*(array + i) = (rand() % (high + 1 - low)) + low;
    }
}

int *createArray(int size, int low, int high){
    int *array = malloc(size * sizeof(int));

    generateArray(array, size, low, high);

    return array;
}

int main(){
    int size = 10, low = -20, high = 50;
    int *data = createArray(size, low, high);

    for(int i = 0; i < size; ++i){
	printf("%d ", *(data + i));
    }
    printf("\n");
    free(data);
}
