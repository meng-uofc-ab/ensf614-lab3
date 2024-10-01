/*
* File Name: Circle.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Oct 2, 2024
*/

#define _USE_MATH_DEFINES

#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;


Circle::Circle(double r, double x, double y, const char* name): Shape(x, y, name), radius(r) {}

const double Circle::area() const {
    return M_PI * radius * radius;
}

const double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::display() const{
    cout << "Circle Name: " << shapeName << endl;
    origin.display();
    cout << "Radius: " << radius << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

 void Circle::set_radius(double r){
 radius = r;
 }
