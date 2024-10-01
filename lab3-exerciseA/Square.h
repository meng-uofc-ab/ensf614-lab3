/*
* File Name: Square.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Oct 2, 2024
*/

#ifndef Square_h
#define Square_h

#include <stdio.h>
#include "Shape.h"

class Square : virtual public Shape{
protected:
    double side_a;

public:
    Square(double a, double x, double y, const char* name);
    // REQUIRES: Double values representing side of the square x and y coordinates of the origin point
    // Pointer to the char array that contains name of the square object
    // PROMISES: Creates a Square object with given side, origin point and name.
    
    const double area() const;
    // PROMISES: returns the area of the square
    
    const double perimeter() const;
    // PROMISES: returns the perimeter of the square
    
    void display() const;
    //PROMISES: displays the details of the square: name, x and y coordinates of the origin point, length of the side, area and perimeter
    
    void set_side_a(double a);
    // REQUIRES: A double value to set side a of the square
    // PROMISES: Updates the side a with the given value
};


#endif /* Square_h */
