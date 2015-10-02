//
// Created by heath on 15-9-26.
//
#include <iostream>
#include <stdio.h>
#include <iomanip>

#define PI 3.1415927;

using namespace std;

int main() {
    double diameter, distance, speed, time;
    int revolutions;
    int count = 1;

    while(cin >> diameter >> revolutions >> time && revolutions) {
        diameter = diameter / 12 / 5280;
        distance = diameter * revolutions * PI;
        speed = distance / time * 3600;
        printf("Trip #%d: %.2f %.2f\n", count++, distance, speed);
    }
    return 0;
}


