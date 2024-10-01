/*
* File Name: iterator.cpp
* Assignment: Lab 3 Exercise B
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Oct 2, 2024
*/

#include <iostream>
#include <assert.h>
#include "mystring2.h"

using namespace std;

template <typename T>
class Vector {
public:

    class VectIter {
        friend class Vector;
    private:
        Vector *v; // points to a vector object of type T
        int index;    // represents the subscript number of the vector's
        // array.
    public:
        VectIter(Vector& x): v(&x), index(0){};
        
        T operator++();
        //PROMISES: increments the iterator's indes and return the
        //          value of the element at the index position. If
        //          index exceeds the size of the array it will
        //          be set to zero. Which means it will be circulated
        //          back to the first element of the vector.
        
        T operator++(int);
        // PRIMISES: returns the value of the element at the index
        //           position, then increments the index. If
        //           index exceeds the size of the array it will
        //           be set to zero. Which means it will be circulated
        //           back to the first element of the vector.
        
        T operator--();
        // PROMISES: decrements the iterator index, and return the
        //           the value of the element at the index. If
        //           index is less than zero it will be set to the
        //           last element in the aray. Which means it will be
        //           circulated to the last element of the vector.
        
        T operator--(int);
        // PRIMISES: returns the value of the element at the index
        //           position, then decrements the index. If
        //           index is less than zero it will be set to the
        //           last element in the aray. Which means it will be
        //           circulated to the last element of the vector.
        
        T operator *();
        // PRIMISES: returns the value of the element at the current index position.
    };

    Vector(int sz): size(sz), array(new T[sz]) {}
    ~Vector();                                      // destructor
    Vector(const Vector& other);                    //copy constructor
    Vector<T>& operator=(const Vector& other);      //assignment operator

    T& operator[](int i);
    // PRIMISES: returns existing value in the ith element of array or sets a new value to  the ith element in array.
  
    void ascending_sort();
    // PRIMISES: sorts the vector values in ascending order.
    
private:
    T *array;               // points to the first element of an array of T
    int size;               // size of array
    void swap(T& a, T& b);
    // PRIMISES: swaps the values of two elements in array
};

template <typename T>
T Vector<T>::VectIter::operator++() {
    if (++index >= v->size) index = 0;
    return v->array[index];
}

template <typename T>
T Vector<T>::VectIter::operator++(int){
    T temp = v->array[index];
    if (++index >= v->size) index = 0;
    return temp;
}

template <typename T>
T Vector<T>::VectIter::operator--(){
    if (--index < 0) index = v->size - 1;
    return v->array[index];
}

template <typename T>
T Vector<T>::VectIter::operator--(int){
    T temp = v->array[index];
    if (--index < 0) index = v->size - 1;
    return temp;
}

template <typename T>
T Vector<T>::VectIter::operator *() {
    return v->array[index];
}

template <typename T>
Vector<T>::~Vector(){ delete[] array; }

template <typename T>
Vector<T>::Vector(const Vector& other) : size(other.size), array(new T[other.size]) {
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] array;
        size = other.size;
        array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
T& Vector<T>::operator[](int i) {
    return array[i];
}

template <typename T>
void Vector<T>::ascending_sort() {
    for(int i=0; i< size-1; i++)
        for(int j=i+1; j < size; j++)
            if(array[i] > array[j])
                swap(array[i], array[j]);
}

template <typename T>
void Vector<T>::swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// Specialization for const char* to handle string comparisons correctly
template <>
void Vector<const char*>::ascending_sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j=i+1; j < size; j++) {
            if (strcmp(array[i], array[j]) > 0) {
                Vector::swap(array[i], array[j]);
            }
        }
    }
}


int main()
{

 Vector<int> x(3);
 x[0] = 999;
 x[1] = -77;
 x[2] = 88;

 Vector<int>::VectIter iter(x);

 cout << "\n\nThe first element of vector x contains: " << *iter;

 // the code between the  #if 0 and #endif is ignored by
 // compiler. If you change it to #if 1, it will be compiled
 
#if 1
    cout << "\nTesting an <int> Vector: " << endl;
    
    cout << "\n\nTesting sort";
    x.ascending_sort();
    
    for (int i=0; i<3 ; i++)
        cout << endl << iter++;
    
    cout << "\n\nTesting Prefix --:";
    for (int i=0; i<3 ; i++)
        cout << endl << --iter;
    
    cout << "\n\nTesting Prefix ++:";
    for (int i=0; i<3 ; i++)
        cout << endl << ++iter;
    
    cout << "\n\nTesting Postfix --";
    for (int i=0; i<3 ; i++)
        cout << endl << iter--;
    
    cout << endl;
    
    cout << "Testing a <Mystring> Vector: " << endl;
    Vector<Mystring> y(3);
    y[0] = "Bar";
    y[1] = "Foo";
    y[2] = "All";;
    
    Vector<Mystring>::VectIter iters(y);
    
    cout << "\n\nTesting sort";
    y.ascending_sort();
    
    for (int i=0; i<3 ; i++)
        cout << endl << iters++;
    
    cout << "\n\nTesting Prefix --:";
    for (int i=0; i<3 ; i++)
        cout << endl << --iters;
    
    cout << "\n\nTesting Prefix ++:";
    for (int i=0; i<3 ; i++)
        cout << endl << ++iters;
    
    cout << "\n\nTesting Postfix --";
    for (int i=0; i<3 ; i++)
        cout << endl << iters--;
    
    cout << endl; cout << "\nTesting a <char *> Vector: " << endl;
    Vector<const char*> z(4);
    z[0] = "Orange";
    z[1] = "Pear";
    z[2] = "Apple";
    z[3] = "Grapes";
    
    Vector<const char*>::VectIter iterchar(z);
    
    cout << "\nPrints unsorted vector z" << endl;
    for (int i=0; i<4 ; i++)
        cout << iterchar++ << endl;
    
    cout << "\n\nTesting sort" << endl;
    z.ascending_sort();
    
    for (int i=0; i<4 ; i++)
        cout << iterchar++ << endl;
    
#endif
    cout << "\nPrgram Terminated Successfully." << endl;
    
    return 0;
}












