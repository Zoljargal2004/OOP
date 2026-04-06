#include <iostream>
#include <cmath> // pi bolon zereg ashiglah shaardlagatai tul duudsn
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

// 1.Тойрог класс
class toirog : public Shape2D{
private:
    double x, y; // төвийн координат
    double r; // радиус

public:
    toirog(string n, double x, double y, double r)
        : Shape2D(n){
        this->x = x;
        this->y = y;
        this->r = r;
    }

    double area() override{
        return M_PI*r*r; // toirgiin talbai oloh tomyo
    }

    double perimeter() override{ 
        return 2*M_PI*r; // toirgiin perimeter oloh tomyo
    }

    void show() override{
        cout <<": "<<name<<endl;
        cout <<"Tuviin coordinate: ("<<x<<", "<<y<<")\n";
        cout <<"Radius: "<<r<<endl;
    }
};

// 2. Квадрат class
class kvadrat : public Shape2D{
private:
    double x, y; //zuun deed talin tseg
    double a; //taliin urt

public:
    kvadrat(string n, double x, double y, double side)
        : Shape2D(n){
        this->x = x;
        this->y = y;
        a = side;
    }

    double area() override{
        return a * a;
    }

    double perimeter() override{
        return 4 * a;
    }

    void show() override{
        cout<<"Name:"<<name<<endl;
        cout<<"Shuluun:("<<x<<","<<y<<")"
             <<"("<<x+a<<","<<y<<")"
             <<"("<<x+a<<","<<y-a<<")"
             <<"("<<x<<","<<y-a<<")"<<endl;
        cout<<"Side:"<<a<<endl;
    }
};

// 3. Зөв гурвалжин class
class zuvGurvaljin : public Shape2D{
private:
    double x, y, a;

    double x2, y2, x3, y3;

public:
    zuvGurvaljin(string n, double x, double y, double a)
        : Shape2D(n), x(x), y(y), a(a) {

        // зөв гурвалжин
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
        cout << "\n[Zuv Gurvaljin] " << name << endl;
        cout << "Points: ";
        cout << "("<<x<<","<<y<<") ";
        cout << "("<<x2<<","<<y2<<") ";
        cout << "("<<x3<<","<<y3<<")\n";
        cout << "Side: " << a << endl;
    }
};

int main(){
    Shape* shapes[3];

    shapes[0] = new toirog("Toirog", 0, 0, 8);
    shapes[1] = new kvadrat("kvadrat", 0, 0, 5);
    shapes[2] = new zuvGurvaljin("Zuv Gurvaljin", 0, 5, 6);

    for (int i = 0; i < 3; i++){
        shapes[i]->show();
        cout<<"Talbai: "<<shapes[i]->area()<<endl; 
        cout<<"Perimeter: "<<shapes[i]->perimeter()<<endl;
    }

    // санах ойг чөлөөлөх
    for (int i=0; i<3; i++){
        delete shapes[i];
    }
    return 0;
}
