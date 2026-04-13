#include <iostream>
#include <algorithm>
#include "shapes.h"

using namespace std;

int main(){
    const int N = 6;
    Shape* shapes[N];

    shapes[0] = new toirog("Toirog-A", 0, 0, 3);        
    shapes[1] = new toirog("Toirog-B", 1, 2, 7);        
    shapes[2] = new kvadrat("Kvadrat-A", 0, 0, 4);       
    shapes[3] = new kvadrat("Kvadrat-B", 2, 2, 9);       
    shapes[4] = new zuvGurvaljin("Gurvaljin-A", 0, 5, 6); 
    shapes[5] = new zuvGurvaljin("Gurvaljin-B", 3, 3, 10);

    // Талбайгаар өсөх дарааллаар эрэмбэлэх (bubble sort)
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(shapes[i]->area() > shapes[j]->area()){
                swap(shapes[i], shapes[j]);
            }
        }
    }

    cout<<"=== Дүрсүүд талбайгаар эрэмбэлэгдсэн (өсөх дараалал) ==="<<endl;
    for(int i = 0; i < N; i++){
        shapes[i]->show();
        cout<<"  Talbai   : "<<shapes[i]->area()<<endl;
        cout<<"  Perimeter: "<<shapes[i]->perimeter()<<endl;
    }

    // Санах ойг чөлөөлөх
    for(int i = 0; i < N; i++){
        delete shapes[i];
    }

    return 0;
}
