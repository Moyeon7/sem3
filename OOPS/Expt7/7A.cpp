#include<iostream>
using namespace std;

int main(){
    double sum=0;
    cout<<" n";
    cout.width(20);
    cout<<"Inverse_of_n";
    cout.width(20);
    cout<<"Sum_of_terms\n"<<endl;

    for(int i=1; i<=10; i++){
        cout.width(2);
        cout<<i;
        cout.setf(ios::showpoint);
        cout.precision(4);
        cout.setf(ios::scientific, ios::floatfield);
        cout.width(19);
        double soln = 1.0/i;
        cout<<soln;

        cout.unsetf(ios::scientific);
        cout.setf(ios::fixed, ios::floatfield);
        sum+=soln;
        cout.width(17);
        cout<<sum<<endl;
    }

    return 0;
}

