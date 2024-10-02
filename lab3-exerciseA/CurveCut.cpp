/*
* File Name: CurveCut.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Oct 2, 2024
*/

#include "CurveCut.h"
#include "Circle.h"
#include "Rectangle.h"

#include <algorithm>
#include <iostream>

using namespace std;

CurveCut::CurveCut(double r, double x, double y, double length, double width, const char* name):
Shape(x, y, name), Rectangle(length, width, x, y, name), Circle(r, x, y, name)
{
    if (radius > min(length, width)) {
        cerr << "Radius must be less than or equal to the smallest value of length and width of the rectangle." << endl;
        exit(1);
    }
}

const double CurveCut::area() const {
    return (side_a * side_b) - (M_PI * radius * radius/4);
}

const double CurveCut::perimeter() const {
    return 2 * (side_a + side_b - radius) + (M_PI * radius/2);
}

void CurveCut::display() const{
    cout << "CurveCut Name: " << shapeName << endl;
    origin.display();
    cout << "Width: " << side_a << endl;
    cout << "Length: " << side_b << endl;
    cout << "Radius of the cut: " << radius << endl;
}
