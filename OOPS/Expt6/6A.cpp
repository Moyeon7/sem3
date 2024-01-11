#include<iostream>
using namespace std;

class Base{
    public:
        void display(){
            cout<<"\nDisplay Base ";
        }
        virtual void show(){
                cout<<"\nShow Base ";
        }
};

class Derived : public Base{
    public:
        void display(){
            cout<<"\nDisplay Derived ";
        }
        virtual void show(){
                cout<<"\nShow Derived ";
        }
};

int main(){
    Base B;
    Derived D;
    Base *bptr;

    cout<<"\nbptr point to Base"<<endl;
    bptr=&B;
    bptr->display();
    bptr->show();
    
    cout<<"\n\nbptr points to Derived"<<endl;
    bptr=&D;
    bptr->display();
    bptr->show();

    return 0;
}