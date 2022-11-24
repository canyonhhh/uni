#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACITY 1000

void generateArray(int data[], int size, int low, int high){
    for (int i = 0; i < size; ++i){
	data[i] = (rand() % (high + 1 - low)) + low;
    }
}

int main(){
    srand(time(NULL));

    int array[CAPACITY], size = 20, low = -5, high = 30;

    generateArray(array, size, low, high);

    for(int i = 0; i < size; ++i){
	printf("%d ", array[i]);
    }
    printf("\n");
}
