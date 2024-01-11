#include<iostream>
using namespace std;

class code{
    int id;
    public:
        code(){
            //default
        }
        code(int x){
            id=x;
        }
        code(code &y){
            id=y.id;
        }
        void display(){
            cout<<id<<endl;
        }
};

int main(){
    code A(400);
    code B(A);
    code C = A;

    cout<<"Id of A: "; 
    A.display();
    cout<<"Id of B: "; 
    B.display();
    cout<<"Id of C: "; 
    C.display();

    return 0; 
}