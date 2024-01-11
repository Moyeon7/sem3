#include<iostream>
using namespace std;

class complex{
    private:
        double real;
        double imag;

    public:
    complex(){
        real=0;
        imag=0;
    }
    complex(double r, double i){
        real=r;
        imag=i;
    }
    friend complex sum(complex, complex);

    void display(){
        cout<<"real="<<real<<" imaginary="<<imag<<endl;
    }
};

complex sum(complex A, complex B){
        complex result;
        result.real=A.real + B.real;
        result.imag=A.imag + B.imag;
        return result;
}

int main(){

    complex A(1.1,1.2);
    complex B = complex(1.3,1.4);
    complex c;
    c=sum(A,B);
    c.display();

    return 0;
}