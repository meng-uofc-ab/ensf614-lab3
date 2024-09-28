/*
* File Name: Point.cpp
* Assignment: Lab 2 Exercise B
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Sept 25, 2024
*/

#include "Point.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int Point::nextId = 1001;
int Point::count = 0;

Point::Point(double x, double y) : x(x), y(y), id(nextId++) {
    count++;
}

Point::~Point() {
    count--;
}

void Point::display() const {
    cout << fixed << setprecision(2);
    cout << "X-coordinate: " << x << endl;
    cout << "Y-coordinate: " << y << endl;
}

double Point::get_x() const {
    return x;
}

double Point::get_y() const {
    return y;
}

int Point::get_id() const {
    return id;
}

void Point::set_x(double x) {
    this->x = x;
}

void Point::set_y(double y) {
    this->y = y;
}

int Point::counter() {
    return count;
}

double Point::distance(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx*dx + dy*dy);
}

double Point::distance(const Point& point1, const Point& point2) {
    double dx = point1.x - point2.x;
    double dy = point1.y - point2.y;
    return sqrt(dx*dx + dy*dy);
}
