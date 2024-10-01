/*
* File Name: Point.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Oct 2, 2024
*/

#ifndef Point_h
#define Point_h

#include <stdio.h>

class Point {
private:
    double x;
    double y;
    int id;
    static int nextId; // Next available id
    static int count; // Count of Point objects

public:
    Point(double x, double y);
    // REQUIRES: Double values representing x and y coordinates of the point
    // PROMISES: Creates a Point object with given coordinates and a unique id.
    
    ~Point();
    // PROMISES: decreases the count of Point objects upon destruction
    
    double get_x() const;
    // PROMISES: returns the x coordinate of the point
    
    double get_y() const;
    // PROMISES: returns the y coordinate of the point
    
    int get_id() const;
    // PROMISES: returns the id of the point
    
    void set_x(double x);
    // REQUIRES: A double value to set x coordinate of the point
    // PROMISES: Updates the x coordiante with the given value
    
    void set_y(double y);
    // REQUIRES: A double value to set y coordinate of the point
    // PROMISES: Updates the y coordiante with the given value
    
    double distance(const Point& other) const;
    // REQUIRES: reference to another point on the cartesian plane
    // PROMISES: returns the distance between 'this' point and the given point
    
    static double distance(const Point& point1, const Point& point2);
    // REQUIRES: reference to two points on the cartesian plane
    // PROMISES: returns the distance between the given two points
    
    void display() const;
    //PROMISES: displays x, and y coordinates of the point
    
    static int counter();
    // PROMISES: returns the number of objects of class Point
};

#endif /* Point_h */
