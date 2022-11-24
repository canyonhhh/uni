#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAPACITY 100
#define SIZE 2

void swap(int array[], int i, int j);
int median(int array[], int low, int high);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);

int main(){

    srand(time(NULL));

    int array[CAPACITY];

    for(int i = 0; i < SIZE; ++i){
	array[i] = (rand() % (-100 + 1 - 100)) + 100;
    }

    for(int i = 0; i < SIZE; ++i){
	printf("%d ", array[i]);
    }
    printf("\n");

    quickSort(array, 0, SIZE - 1);

    for(int i = 0; i < SIZE; ++i){
	printf("%d ", array[i]);
    }
    printf("\n");
}

void quickSort(int array[], int low, int high){
    if (high > low){
	int j = partition(array, low, high);
	quickSort(array, low, j - 1);
	quickSort(array, j + 1, high);
    }
}

void swap(int array[], int i, int j){
    array[i] = array[i] ^ array[j];
    array[j] = array[i] ^ array[j];
    array[i] = array[j] ^ array[i];
}

int medianOfThree(int array[], int low, int high){
    int mid = (low + high) / 2;
    if (array[high] < array[low])
	swap(array, low, high);
    if (array[mid] < array[low])
	swap(array, mid, low);
    if (array[high] < array[mid])
	swap(array, high, mid);
    return mid;
}

int partition(int array[], int low, int high){
    if (high - low < 4){
	return medianOfThree(array, low, high);
    }
    else{
	swap(array, high - 1, medianOfThree(array, low, high));
    }

    int pivot = array[high - 1], i = low, j = high - 1;

    while (i < j) {
	do{
	    ++i;
	} while (array[i] <= pivot);
	do{
	    --j;
	} while (array[j] > pivot);
	if (i < j){
	    swap(array, i, j);
	}
    }

    swap(array, high - 1, i);

    return i;
}
