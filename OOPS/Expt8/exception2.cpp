#include<iostream>
using namespace std;

void divide(int a, int b){
    try{
        if(b==0)
            throw b;
        else{
            cout<<"Solution is "<<a/b<<endl;
            return;
        }
    }
    catch(int){
        cout<<"Exception caught in divide function"<<endl;
        throw;
    }
}

int main(){
    try{
        cout<<"\n1st division\n";
        divide(10, 2);
        cout<<"\n2nd division\n";
        divide(10, 0);
    }
    catch(int){
        cout<<"Exception caught in main"<<endl;
    }

    return 0;
}