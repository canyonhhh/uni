#include <stdio.h>

int isInRange(int number, int low, int high){
    return number >= low ? (number <= high ? 0: -1) : -1;
}

int main(){
    int num = 15, high = 20, low = 0;
    printf("%d\n", isInRange(num, low, high));
}
