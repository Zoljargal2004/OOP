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
        return M_PI*this->r*this->r;
    }

    double perimeter() override{ 
        return 2*M_PI*this->r;
    }

    void show() override{
        cout <<"\nName: "<<this->name<<endl;
        cout <<"Tuviin coordinate: ("<<this->x<<", "<<this->y<<")\n";
        cout <<"Radius: "<<this->r<<endl;
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
        return this->a * this->a;
    }

    double perimeter() override{
        return 4 * this->a;
    }

    void show() override{
        cout<<"\nName: "<<this->name<<endl;
        cout<<"Shuluun: ("<<this->x<<","<<this->y<<")"
             <<"("<<this->x+this->a<<","<<this->y<<")"
             <<"("<<this->x+this->a<<","<<this->y-this->a<<")"
             <<"("<<this->x<<","<<this->y-this->a<<")"<<endl;
        cout<<"Side: "<<this->a<<endl;
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
        this->x2 = x - a/2;
        this->y2 = y - (sqrt(3)/2)*a;
        this->x3 = x + a/2;
        this->y3 = y - (sqrt(3)/2)*a;
    }

    double area() override {
        return (sqrt(3)/4) * this->a * this->a;
    }

    double perimeter() override {
        return 3 * this->a;
    }

    void show() override {
        cout << "\nName: " << this->name << endl;
        cout << "Points: ";
        cout << "("<<this->x<<","<<this->y<<") ";
        cout << "("<<this->x2<<","<<this->y2<<") ";
        cout << "("<<this->x3<<","<<this->y3<<")\n";
        cout << "Side: " << this->a << endl;
    }
};

#endif
