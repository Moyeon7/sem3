#include<iostream>
using namespace std;

class temp{
    int x;
    public:
        temp(){ 
            x = 0; 
        }
        temp(int n){ 
            x = n; 
        }

        friend temp operator+(int n, temp t){ 
            return temp(n + t.x); 
        }
        friend temp operator*(temp t1, temp t2){ 
            return temp(t1.x * t2.x); 
        }
        friend temp operator-(temp t, int n){ 
            return temp(t.x - n); 
        }
        void display(void){ 
            cout << "Value of the object is: " << x << endl; 
        }
};

int main(){
    temp x, y(10);

    x = 5 + y;
    x.display();
    x = x * y;
    x.display();
    x = y - 5;
    x.display();

    return 0;
}