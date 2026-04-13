#include <iostream>
#include "shapes.h"

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

