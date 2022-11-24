#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    double x, y;

} Point;

void printPoint(Point p){
    printf("%f %f\n", p.x, p.y);
}

Point createPoint(double x, double y){
    Point p;
    p.x = x, p.y = y;
    return p;
}

double getDistance(Point a, Point b){
    return sqrt(powf(a.x - b.x, 2) + powf(a.y - b.y, 2));
}

int main(){
    printf("%f\n", getDistance(createPoint(2, -2), createPoint(1, 5)));
}
