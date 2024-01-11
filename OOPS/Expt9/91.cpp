#include<iostream>
using namespace std;

template<class T>
void swap(T x, T y){
    T temp = x;
    x=y;
    y= temp;
    cout<<"x= "<<x<<"\ty= "<<y<<endl;
};

int main(){
    cout<<"Initial values:\nx= a    y= b\nx= 1    y= 2"<<endl;
    cout<<"\nAfter swaping:"<<endl;
    swap('a', 'b');
    swap('1', '2');
    return 0;
}