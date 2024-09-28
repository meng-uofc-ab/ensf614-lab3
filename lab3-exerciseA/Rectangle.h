/*
* File Name: Rectangle.h
* Assignment: Lab 2 Exercise B
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Sept 25, 2024
*/

#ifndef Rectangle_h
#define Rectangle_h

#include <stdio.h>
#include "Square.h"

class Rectangle : public Square{
protected:
    double side_b;

public:
    Rectangle(double side_a, double side_b, double x, double y, const char* name);
    // REQUIRES: Double values representing width and height of a rectangle and x and y coordinates of the origin point
    // Pointer to the char array that contains name of the rectangle object
    // PROMISES: Creates a Rectangle object with given height, width, origin point and name.
    
    const double area() const;
    // PROMISES: returns the area of the rectangle
    
    const double perimeter() const;
    // PROMISES: returns the perimeter of the rectangle
    
    void display() const;
    //PROMISES: displays the details of the rectangle: name, x and y coordinates of the origin point, height(aka side a), width(aka side b), area and perimeter
    
    void set_side_b(double b);
    // REQUIRES: A double value to set side b of the rectangle
    // PROMISES: Updates the side b with the given value
    
};


#endif /* Rectangle_h */
