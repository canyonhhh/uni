#include <stdio.h>

#define CAPACITY 100

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg){
    int choice, correctInput = 0;

    do{
	printf("%s\n", menuTitle);
	for (int i = 0; i < menuSize; ++i){
	    printf("%d. %s\n", i, menuOptions[i]);
	}
	printf("\n%s\n", inputMsg);
	
	if (scanf("%d", &choice) == 1 && getchar() == '\n'){
	    correctInput = 1;
	}
	else{
	    while (getchar() != '\n')
		;
	}
    } while (choice < 0 || choice >= menuSize || !correctInput);

    return choice;
}

int main(){
    char title[] = "Best vegetable picker";
    int menuSize = 5;
    char *menuOptions[CAPACITY] = {"Potatoes", "Tomatoes", "Carrots", "Cucumbers", "Yams"};
    char message[] = "Indicate your favorite via the number:";

    printf("Choice: %d\n", showMenu(title, menuOptions, menuSize, message));

}
