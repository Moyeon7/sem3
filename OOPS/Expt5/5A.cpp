#include<iostream>
using namespace std;

//Base class 
class shape{
    public:
        string name;
        int sides;
        shape(string name, int sides){
            this->name=name;
            this->sides=sides;
        }
};

//Derived classes
class triangle : public shape{
    int base, height;
    public:
        triangle(string name, int sides, int base, int height) : shape(name, sides){
            this->base=base;
            this->height=height;
        }
        float area(){
            float a = 0.5*base*height;
            return a;
        }
        void display(){
            cout<<"Shape is "<<name<<endl;
            cout<<"No. of sides are "<<sides<<endl;
            cout<<"Base is "<<base<<endl;
            cout<<"Height is "<<height<<endl;
            cout<<"Area is "<<area()<<endl;
        }
};

class square : public shape{
    int length;
    public:
        square(string name, int sides, int length) : shape(name, sides){
            this->name=name;
            this->length=length;
        }
        int area(){
            int a = length*length;
            return a;
        }
        void display(){
            cout<<"\nShape is "<<name<<endl;
            cout<<"No. of sides are "<<sides<<endl;
            cout<<"Length is "<<length<<endl;
            cout<<"Area is "<<area()<<endl;
        }
};

int  main(){
    triangle t("triangle", 3, 2, 3);
    t.display();

    square s("square", 4, 2);
    s.display();

    return 0;
}