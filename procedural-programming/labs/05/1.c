#include <stdio.h>

#define CAPACITY 10

#define GOOD_INPUT "Input received.\n"
#define BAD_INPUT "The input is incorrect or the isn't enough space in the array. Skipping this step.\n"

void printArray(int arr[]){
    for (int i = 0; i < CAPACITY; ++i){
	printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int x, y, size = 0;

    // A
    int array[CAPACITY] = {0};
    size = 10;

    // B
    printArray(array);

    // C
    array[0] = 1;
    array[3] = 2;
    array[9] = 3;
    
    // D
    int posToDelete = 3;
    for (int i = posToDelete; i < CAPACITY; ++i){
	array[i - 1] = array[i];
    }
    --size;

    // E
    array[size++] = 4;
    int posToInsert = 7;
    for (int i = size - 1; i > posToInsert - 1; --i){
	int temp = array[i - 1];
	array[i - 1] = array[i];
	array[i] = temp;
    }

    // F
    printArray(array);

    // G
    printf("Input numbers x [0; %d) and y. The element at index x will be set to y.\n", size);
    if (scanf("%d %d", &x, &y) == 2 && getchar() == '\n' && x < size){
	printf(GOOD_INPUT);
	array[x] = y;
    }
    else{
	printf(BAD_INPUT);
    }

    // H
    printf("Input number x [0; %d). The element at index x will be deleted.\n", size);
    if (scanf("%d", &x) == 1 && getchar() == '\n' && x < size){
	printf(GOOD_INPUT);

	for (int i = x + 1; i < CAPACITY; ++i){
	    array[i - 1] = array[i];
	}
	--size;
    }
    else{
	printf(BAD_INPUT);
    }
     
    // I
    printf("Input number x [0; %d) and y. The element y will be inserted at index x.\n", size);
    if (scanf("%d", &x) == 1 && getchar() == '\n' && x < size && size < CAPACITY){
	printf(GOOD_INPUT);

	array[size++] = y;
	for (int i = size; i > x; --i){
	    int temp = array[i - 1];
	    array[i - 1] = array[i];
	    array[i] = temp;
	}
    }
    else{
	printf(BAD_INPUT);
    }

    // J
    printArray(array);
}
