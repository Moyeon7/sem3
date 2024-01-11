#include<iostream>
using namespace std;

class Temp{
    int n;

    public:
        Temp(){ 
            n = 0; 
        }
        Temp(int i){ 
            n = i; 
        }
        ~Temp(){
            //destructor
        }

        int operator++(){ 
            return ++n; 
        }
        int operator++(int){ 
            return n++; 
        }
        int operator--(){ 
            return --n; 
        }
        int operator--(int){ 
            return n--; 
        }

        int val(){
            return n;
        }
};

int main(){
    Temp a(10);
    
    cout << "The value of a is: " << a.val() << endl;
    cout << "Postincrement a: " << a++ << endl;
    cout << "Preincrement a: " << ++a << endl;
    cout << "Postdecrement a: " << a-- << endl;
    cout << "Predecrement a: " << --a << endl;

    return 0;
}