#include <stdio.h>
#include <stdlib.h>

int splitData(int *data, int size, int firstPartSize, int **firstPart, int **secPart){
    if (data == NULL || firstPartSize >= size || size < 2 || *firstPart != NULL || *secPart != NULL){
	return -1;
    }

    *firstPart = malloc(firstPartSize * sizeof(int));
    *secPart = malloc((size - firstPartSize) * sizeof(int));

    if (*firstPart == NULL || *secPart == NULL){
	return -1;
    }

    for(int i = 0; i < firstPartSize; ++i){
	*(*firstPart + i) = data[i];
    }
    for(int i = firstPartSize; i < size; ++i){
	*(*secPart + i - firstPartSize) = data[i];
    }

    return 0;
}

int main(){
    int size = 10, firstPartSize = 5;
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *first = NULL, *second = NULL;

    if (splitData(array, size, firstPartSize, &first, &second) == 0){
	for(int i = 0; i < firstPartSize; ++i){
	    printf("%d ", first[i]);
	}
	printf("\n");
	for(int i = 0; i < size - firstPartSize; ++i){
	    printf("%d ", second[i]);
	}
	printf("\n");
	free(first);
	free(second);
    }
}
