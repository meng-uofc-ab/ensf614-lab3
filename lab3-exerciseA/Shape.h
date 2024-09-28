/*
* File Name: Shape.h
* Assignment: Lab 2 Exercise B
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Sept 25, 2024
*/

#ifndef Shape_h
#define Shape_h

#include <stdio.h>
#include "Point.h"

class Shape {
protected:
    Point origin;
    char* shapeName;

public:
    Shape(double x, double y, const char* name);
    // REQUIRES: Double values representing x and y coordinates of the point
    // PROMISES: Creates a Point object with given coordinates and a unique id.
    
    virtual ~Shape();
    // PROMISES: de-allocates the memory space allocated dynamically for shapeName
    
    const Point& getOrigin() const;
    // PROMISES: returns the reference to origin point
    
    const char* getName() const;
    // PROMISES: returns the pointer to the name of the shape
    
    virtual void display() const;
    //PROMISES: displays name of the shape and x, and y coordinates of the origin point
    
    virtual const double area() const = 0;
    //Pure virtual function to calculate area. Derived class defines the implementation
    
    virtual const double perimeter() const = 0;
    //Pure virtual function to calculate perimeter. Derived class defines the implementation
    
    double distance(Shape& other) const;
    // REQUIRES: reference to another shape
    // PROMISES: returns the distance between the origin point of 'this' shape object and another given shape object
    
    static double distance(const Shape& the_shape, const Shape& other);
    // REQUIRES: reference to two points on the cartesian plane
    // PROMISES: returns the distance between the origin points othe two given shapes
    
    void move (double dx, double dy);
    // REQUIRES: two double values representing the displacement for x and y coordinates
    // PROMISES: Changes the position of the shape, the current x and y coordinates, to x+dx, and y+dx
    
    // Copy Constructor
    Shape(const Shape& source);
    // REQUIRES: A reference to another Shape object.
    // PROMISES: Creates a new Shape object that is a deep copy of the provided object.
    
    // Assignment Operator
    Shape& operator=(const Shape& source);
    // Requires: A reference to another Shape object.
    // Promises: Assigns the values from the provided object to this object, ensuring no resource leaks. Returns a reference to this object.
};


#endif /* Shape_h */
