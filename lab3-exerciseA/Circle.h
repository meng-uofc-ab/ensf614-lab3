//
//  Circle.hpp
//  lab3-exerciseA
//
//  Created by Abhilash Paul on 2024-09-28.
//

#ifndef Circle_h
#define Circle_h

#include "Shape.h"
#include <stdio.h>


class Circle : virtual public Shape{
protected:
    double radius;
public:
    Circle(double r, double x, double y, const char* name);
    // REQUIRES: Double values representing radius of the circle, and x and y coordinates of the origin point
    // Pointer to the char array that contains name of the circle object
    // PROMISES: Creates a Circle object with given radius, origin point and name.
    
    const double area() const;
    // PROMISES: returns the area of the circle
    
    const double perimeter() const;
    // PROMISES: returns the perimeter of the circle
    
    void display() const;
    //PROMISES: displays the details of the circle: name, x and y coordinates of the origin point, radius, area and perimeter
    
    void set_radius(double r);
    // REQUIRES: A double value representing the radius of the circle
    // PROMISES: Updates the radius of the circle object with the given value
    
    const double get_radius();
    // PROMISES: returns the radius of the circle
};

#endif /* Circle_h */
