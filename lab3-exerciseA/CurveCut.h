//
//  CurveCut.hpp
//  lab3-exerciseA
//
//  Created by Abhilash Paul on 2024-09-28.
//

#ifndef CurveCut_h
#define CurveCut_h

#include "Rectangle.h"
#include "Circle.h"
#include <stdio.h>

class CurveCut : public Rectangle, public Circle{
public:
    CurveCut(double r, double x, double y,
             double length, double width, const char* name);
    // REQUIRES: Double values representing radius of the circe, x & y coordinates of the origin point, and the sides a & b of the rectangle
    // Pointer to the char array that contains name of the curvecut object
    // PROMISES: Creates a CurveCut object with given sides, radius, origin point and name.
    
    const double area() const;
    // PROMISES: returns the area of the curve cut
    
    const double perimeter() const;
    // PROMISES: returns the perimeter of the curve cut
    
    void display() const;
    //PROMISES: displays the details of the curve cut: name, x & y coordinates of the origin, width, length and radius of the cut
};

#endif /* CurveCut_h */
