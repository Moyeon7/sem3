#include<iostream>
using namespace std;

int main(){
    cout.width(28);
    cout<<"VALUE**********MULT OF VALUE"<<endl;
    double mult;
    for(int i=1; i<=4; i++){
        cout.setf(ios::showpos);
        cout.setf(ios::internal, ios::adjustfield);
        cout.fill('.');
        cout.width(5);
        cout<<i;

        cout.width(18);
        cout.precision(4);
        cout.unsetf(ios::showpos);
        cout.setf(ios::showpoint);
        mult= i*2;
        cout<<"+"<<mult<<endl;
    }


    return 0;
}