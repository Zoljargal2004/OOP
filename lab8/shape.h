#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
using namespace std;

// Shape класс (base class)
class Shape{
protected:
    string name; 
    static int count; //dursuudiin too
public:
    Shape(string n){
        this->name = n;
        count++; //object uuseh burt 1 eer nemegduulne
    }

    virtual ~Shape() {}

    static int getCount(){
        return count;
    }

    static void resetCount(){
        count = 0;
    }
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

    // Хийсвэр функцууд
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

#endif
