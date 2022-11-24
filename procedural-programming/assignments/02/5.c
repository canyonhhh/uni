// Made by Joris Lisas
// This C program takes in a positive integer n,
// creates an n by n 2d array, filling it in a spiral
// with integers from 1 to n*n

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 32
#define BAD_INPUT "Enter a positive whole number up to %d\n", MAX_SIZE
#define ALLOCATION_ERROR "Could not allocate memory.\n"

int fillMatrixSpiral(int height, int width, int **matrix);
int getPositiveInt();
int **alloc2DArray(int height, int width);
int getIntLength();
void printMatrix();
void free2DArray(int **matrix, int rows);
void cleanBuffer();

int main(){

    printf("This program takes in a positive whole number n, generates an n*n matrix, filling it in a spiral, from 1 to n*n.\n");

    int n = getPositiveInt();

    int **matrix = alloc2DArray(n, n);
    
    if (matrix == NULL){
	printf(ALLOCATION_ERROR);
	return -1;
    }
    if (fillMatrixSpiral(n, n, matrix) == -1){
	printf(ALLOCATION_ERROR);
	return -1;
    }
    
    printMatrix(n, n, matrix);
    free2DArray(matrix, n);
    return 0;
}

int fillMatrixSpiral(int height, int width, int **matrix){
    int **seen = alloc2DArray(height, width);

    if (seen == NULL){
	return -1;
    }
    
    int newRow[4] = {0, 1, 0, -1};
    int newCol[4] = {1, 0, -1, 0}; // New coordinate arrays (index + 1 performs a 90 degree clockwise turn)

    int row = 0, col = 0, nextRow = 0, nextCol = 0, di = 0; // Direction Indicator
									 
    for(int i = 1; i <= height * width; ++i){
	matrix[row][col] = i;
	seen[row][col] = 1;

	nextRow = row + newRow[di];
	nextCol = col + newCol[di];

	if (nextCol < width && nextRow < height && nextCol >= 0 && nextRow >= 0 && !seen[nextRow][nextCol]){
	    row = nextRow;
	    col = nextCol;
	} else{
	    // If potential coordinates out of bounds or seen, perform clockwise turn
	    di = (di + 1) % 4;
	    row += newRow[di];
	    col += newCol[di];
	}
    }
    
    free2DArray(seen, height);
    return 0;
}

int getPositiveInt(){
    int n, inputCorrect = 0;
    while(!inputCorrect){
	printf(BAD_INPUT);
	if (scanf("%d", &n) == 1 && getchar() == '\n'){
	    if (n > 0 && n < MAX_SIZE){
		inputCorrect = 1;
	    }
	} else{
	    cleanBuffer();
	}
    }
    return n;
}

void cleanBuffer(){
    while (getchar() != '\n')
	;
}

int **alloc2DArray(int height, int width){
    int **array = calloc(height, sizeof(*array));

    if (array == NULL){
	return NULL;
    }

    for(int i = 0; i < width; ++i){
	array[i] = calloc(width, sizeof(int));
	if (*(array + i) == NULL){
	    return NULL;
	}
    }

    return array;
}

void free2DArray(int **matrix, int rows){
    for(int i = 0; i < rows; ++i){
	free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int height, int width, int **matrix){
    int printWidth = getIntLength(height * width) + 1; // So the longer numbers don't mess up the printing

    for (int i = 0; i < height; ++i){
	for (int j = 0; j < width; ++j){
	    printf("%*d", printWidth, matrix[i][j]);
	}
	printf("\n");
    }
}

int getIntLength(int n){
    int length = 0;
    while (n > 0){
	n /= 10;
	++length;
    }
    return length;
}
