#include <stdio.h>
#include <stdlib.h>

typedef struct Point{
    double x, y;
} Point;

typedef struct List{
    Point value;
    struct List *next;
} List;

List *createList(Point value);
void printList(List *list);
int getListSize(List *list);
void insertElement(List **list, Point value);
Point deleteElement(List **list);
void destroyList(List **list);
Point createPoint(double x, double y);

List *createList(Point value){
    List *list = malloc(sizeof(List));
    list->value = value;
    list->next = NULL;
    return list;
}

void printList(List *list){
    if (list != NULL){
	printf("%f %f\n", list->value.x, list->value.y);
	printList(list->next);
    }
}

void insertElement(List **list, Point value){
    List *newList = createList(value);
    newList->next = *list;
    *list = newList;
}

Point getElement(List *list){
    return list->value;
}

Point deleteElement(List **list){
    Point topElement = getElement(*list);
    List *newTopElement = (*list)->next;

    free(*list);
    *list = newTopElement;
    
    return topElement;
}

void destroyList(List **list){
    List **tmp;
    while (*list != NULL){
	*tmp = *list;
	*list = (*list)->next;
	free(*tmp);
    }
}

Point createPoint(double x, double y){
    Point p;
    p.x = x, p.y = y;
    return p;
}

int main(){
    List *list = createList(createPoint(12, 5));
    insertElement(&list, createPoint(2, 5));
    printList(list);
    Point point = deleteElement(&list);
    printf("Pop: %f %f\n", point.x, point.y);
    insertElement(&list, createPoint(20, -2));
    printList(list);
    destroyList(&list);
}
