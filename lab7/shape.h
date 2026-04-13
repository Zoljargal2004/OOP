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
        cout<<"Shape: "<<name<<endl;
    }
};

// 2D Shape хүүхэд класс (derived from Shape)
// Бүх 2D дүрсийн нийтлэг шинж: x, y coordinate
class Shape2D : public Shape{
protected:
    double x, y;

public:
    Shape2D(string n, double x, double y)
        : Shape(n), x(x), y(y) {}
};

#endif
