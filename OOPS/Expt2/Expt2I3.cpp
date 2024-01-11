#include<iostream>
using namespace std;
int main(){
    int n, a, b, c;
    cout<<"Enter the number of rows: ";
    cin>>n;    
    for(int i=1; i<=n; i++){
        a=0,b=1;
        for(int j=1; j<=i; j++){
            cout<<b;
            c=a+b;
            a=b;
            b=c;           
        }
        cout<<endl;
    }
    return 0;
}