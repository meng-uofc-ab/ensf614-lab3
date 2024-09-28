/*
* File Name: Shape.cpp
* Assignment: Lab 2 Exercise B
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Sept 25, 2024
*/

#include "Shape.h"
#include "Point.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

Shape::Shape(double x, double y, const char* name ): origin(x,y){
    shapeName = new char[strlen(name)+1];
    if(shapeName == 0){
        cerr <<"Memory not available.";
        exit(1);
    }
    strcpy(shapeName, name);
}

Shape::~Shape(){
    delete[] shapeName;
}

const Point& Shape::getOrigin() const {
    return origin;
}

const char* Shape::getName() const {
    return shapeName;
}

void Shape::display() const{
    cout << "Shape Name: " << shapeName << endl;
    cout << "X-coordinate: " << origin.get_x() << endl;
    cout << "Y-coordinate: " << origin.get_y() << endl;
}

double Shape::distance(Shape& other) const {
    return Point::distance(this -> origin, other.origin);
}

double Shape::distance(const Shape& the_shape, const Shape& other){
    return Point::distance(the_shape.origin, other.origin);
}

void Shape::move (double dx, double dy){
    origin.set_x(origin.get_x()+dx);
    origin.set_y(origin.get_y()+dy);
}

Shape::Shape(const Shape& source) : origin(source.origin) {
    shapeName = new char[strlen(source.shapeName) + 1];
    strcpy(shapeName, source.shapeName);
}

Shape& Shape::operator=(const Shape& source) {
    if (this != &source) {
        origin = source.origin;
        delete[] shapeName;
        shapeName = new char[strlen(source.shapeName) + 1];
        strcpy(shapeName, source.shapeName);
    }
    return *this;
}
