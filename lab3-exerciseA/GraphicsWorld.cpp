/*
* File Name: GraphicsWorld.cpp
* Assignment: Lab 2 Exercise B
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Sept 25, 2024
*/

#include "GraphicsWorld.h"
#include "Point.h"
#include "Square.h"
#include "Square.h"
#include "Rectangle.h"
#include "CurveCut.h"
#include <iostream>

using namespace std;

void GraphicsWorld::run() {
    cout << "Authored by Abhilash Paul & Seethal Elias\n" << endl;
#if 1 // Change 0 to 1 to test Point
    Point m(6, 8);
    Point n(6, 8);
    n.set_x(9);
    cout << "\nExpected to dispaly the distance between m and n is: 3";
    cout << "\nThe distance between m and n is: " << m.distance(n);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: "
         << Point::distance(m, n);
#endif // end of block to test Point

#if 1 // Change 0 to 1 to test Square
    cout << "\nTesting class Square:" << endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();
#endif // end of block to test Square

#if 1 // Change 0 to 1 to test Rectangle
    cout << "\nTesting Functions in class Rectangle:" << endl;
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();
    
    Rectangle b(16, 7, 8, 9, "RECTANGLE B");
    b.display();
    
    double d = a.distance(b);
    cout << "Distance between rectangles a and b is: " << d << endl;
    
    Rectangle rec1 = a;
    rec1.display();
    
    cout << "\nTesting assignment operator in class Rectangle:" << endl;
    Rectangle rec2(3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;
    a.set_side_b(200);
    a.set_side_a(100);
    
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5\n" << "Y-coordinate: 7\n"
    << "Side a: 12\n" << "Side b: 15\n" << "Area: 180\n" << "Perimeter: 54\n" ; cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl; 
    rec2.display();
    
    cout << "\nTesting copy constructor in class Rectangle:" <<endl; Rectangle rec3 (a);
    rec3.display();
    a.set_side_b(300);
    a.set_side_a(400);
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5\n" << "Y-coordinate: 7\n" << "Side a: 100\n" << "Side b: 200\n" << "Area: 20000\n" << "Perimeter: 600\n" ;
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl;
    rec3.display();
    
#endif // end of block to test Rectangle

#if 1 // Change 0 to 1 to test using array of pointers and polymorphism
    cout << "\nTesting array of pointers and polymorphism:" << endl;
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &b;
    sh[2] = &rec1;
    sh[3] = &rec2;
    
    for (int i = 0; i < 4; i++)
        sh[i]->display();
#endif // end of block to test array of pointers and polymorphism

#if 1
    cout << "\nTesting Functions in class Circle:" <<endl;
    Circle c(3, 5, 9, "CIRCLE C");
    c.display();
    cout << "the area of " << c.getName() <<" is: "<< c.area() << endl;
    cout << "the perimeter of " << c.getName() << " is: "<< c.perimeter() << endl; 
    d = a.distance(c);
    cout << "\nThe distance between rectangle a and circle c is: " << d << endl << endl;
    CurveCut rc (6, 5, 10, 12, 9, "CurveCut rc");
    rc.display();
    cout << "the area of " << rc.getName() <<" is: "<< rc.area() << endl;
    cout << "the perimeter of " << rc.getName() << " is: "<< rc.perimeter() << endl;
    d = rc.distance(c);
    cout << "\nThe distance between rc and c is: "<< d << endl << endl;
    // Using array of Shape pointers:
    Shape* shapes[4];
    shapes[0] = &s;
    shapes[1] = &a;
    shapes[2] = &c;
    shapes[3] = &rc;
    shapes[0]->display();
    cout << "the area of "<< shapes[0]->getName() << "is: "<< shapes[0] ->area();
    cout << "\nthe perimeter of " << shapes[0]->getName() << " is: "<< shapes[0]->perimeter() <<endl << endl;
    shapes[1]->display();
    cout << "the area of "<< shapes[1]->getName() << "is: "<< shapes[1] ->area();
    cout << "\nthe perimeter of " << shapes[0]->getName() << " is: "<< shapes[1]->perimeter() <<endl << endl;
    shapes[2]->display();
    cout << "the area of "<< shapes[2]->getName() << "is: "<< shapes[2] ->area();
    cout << "\nthe circumference of " << shapes[2]->getName()<< " is: "<< shapes[2]->perimeter() <<endl << endl;
    sh[3]->display();
    cout << "the area of "<< sh[3]->getName() << "is: "<< sh[3] ->area();
    cout << "\nthe perimeter of " << sh[3]->getName () << " is: "<< sh[3]->perimeter() << endl;
    cout << "\nTesting copy constructor in class CurveCut:" <<endl;
    CurveCut cc = rc;
    cc.display();
    cout << "\nTesting assignment operator in class CurveCut:" <<endl; 
    CurveCut cc2(2, 5, 100, 12, 9, "CurveCut cc2");
    cc2.display();
    cc2 = cc;
    cc2.display(); 
#endif
    
#if 0
    cout << "\nTesting multiple inherittance:" << endl;
    CurveCut cc1(5, 1, 0, 7, 9, "Curve cut - 1");
    cc1.display();
#endif // end of block to test multiple inherittance
    
#if 0
    cout << "Testing invalid inputs to curve cut:" << endl;
    CurveCut cc3(9, 1, 0, 7, 9, "Curve cut - 2");
#endif
    

}
