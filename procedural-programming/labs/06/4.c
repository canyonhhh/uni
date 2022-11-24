#include <stdio.h>
#include <string.h>
#define GOOD_INPUT "Input received.\n"
#define BAD_INPUT "Incorrect input. Try again.\n"

int dayOfWeek(int y, int m, int d){
    int t[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3){
	--y;
    }

    return (y + y/4 - y/100 + y/400 + t[m-1] + d + 6) % 7 + 1;
}

int main(){
    int year, month, day, daysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, correctInput = 0;

    printf("This program takes in a date (YYYY-MM-DD) and outputs the day of the week.\n");
    printf("Input a date:\n");

    while(!correctInput){
	if (scanf("%4d-%2d-%2d", &year, &month, &day) == 3 && getchar() == '\n'){
	    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
		daysOfMonth[1] = 29;
	    }
	    if (year >= 1000 && month > 0 && day > 0 && month < 13 && day <= daysOfMonth[month - 1]){
		printf(GOOD_INPUT);
		correctInput = 1;
	    }
	    else{
		printf(BAD_INPUT);
		daysOfMonth[1] = 28;
	    }
	}
	else{
	    printf(BAD_INPUT);
	    while (getchar() != '\n')
		;
	}
    }

    FILE *daysFile;
    daysFile = fopen("week.txt", "r");

    char weekDay[10];
    if (daysFile != NULL){
	for (int i = 0; i < dayOfWeek(year, month, day); ++i){
	    fscanf(daysFile, "%s", weekDay);
	}
    }
    else{
	printf("Could not open week file.\n");
	return 1;
    }

    printf("%s\n", weekDay);
}
