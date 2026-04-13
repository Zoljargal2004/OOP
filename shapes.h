#ifndef SHAPES_H
#define SHAPES_H

#include <cmath>
#include "shape.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// 1.Тойрог класс
class toirog : public Shape2D{
private:
    double r; // радиус (x, y Shape2D-аас өвлөнө)

public:
    toirog(string n, double x, double y, double r)
        : Shape2D(n, x, y), r(r) {}

    double area() override{
        return M_PI*r*r;
    }

    double perimeter() override{ 
        return 2*M_PI*r;
    }

    void show() override{
        cout <<"\nName: "<<name<<endl;
        cout <<"Tuviin coordinate: ("<<x<<", "<<y<<")\n";
        cout <<"Radius: "<<r<<endl;
    }
};

// 2. Квадрат class
class kvadrat : public Shape2D{
private:
    double a; // талийн урт (x, y Shape2D-аас өвлөнө)

public:
    kvadrat(string n, double x, double y, double side)
        : Shape2D(n, x, y), a(side) {}

    double area() override{
        return a * a;
    }

    double perimeter() override{
        return 4 * a;
    }

    void show() override{
        cout<<"\nName: "<<name<<endl;
        cout<<"Shuluun: ("<<x<<","<<y<<")"
             <<"("<<x+a<<","<<y<<")"
             <<"("<<x+a<<","<<y-a<<")"
             <<"("<<x<<","<<y-a<<")"<<endl;
        cout<<"Side :"<<a<<endl;
    }
};

// 3. Зөв гурвалжин class
class zuvGurvaljin : public Shape2D{
private:
    double a;           // талийн урт (x, y Shape2D-аас өвлөнө)
    double x2, y2, x3, y3; // бусад оройнууд (1-р оройг Shape2D-аас авна)

public:
    zuvGurvaljin(string n, double x, double y, double a)
        : Shape2D(n, x, y), a(a) {
        // зөв гурвалжины бусад оройнуудыг тооцоолох
        x2 = x - a/2;
        y2 = y - (sqrt(3)/2)*a;
        x3 = x + a/2;
        y3 = y - (sqrt(3)/2)*a;
    }

    double area() override {
        return (sqrt(3)/4) * a * a;
    }

    double perimeter() override {
        return 3 * a;
    }

    void show() override {
        cout << "\nName: " << name << endl;
        cout << "Points: ";
        cout << "("<<x<<","<<y<<") ";
        cout << "("<<x2<<","<<y2<<") ";
        cout << "("<<x3<<","<<y3<<")\n";
        cout << "Side: " << a << endl;
    }
};

class Pentagon : public Shape2D{
private:
    double a;

public:
    Pentagon(string n, double x, double y, double a)
        : Shape2D(n, x, y), a(a) {}

    double area() override{
        return (1.0/4) * sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0))) * a * a;
    }

    double perimeter() override{
        return 5 * a;
    }

    void show() override{
        cout<< "\nName: " << name <<endl;
        cout<< "Side: " << a <<endl;
    }
};

#endif
