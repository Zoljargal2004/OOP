#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
using namespace std;

// Shape класс (base class)
class Shape{
protected:
    string name; 

public:
    Shape(string n){
        name=n;
    }

    virtual ~Shape() {}
    // Хийсвэр функцууд
    virtual double area() = 0;
    virtual double perimeter() = 0;

    virtual void show(){
        cout << "Shape: " << name << endl;
    }
};

// 2Dshape хүүхэд класс (derived from Shape)
class Shape2D : public Shape{
public:
    Shape2D(string n) : Shape(n){}
};

#endif
