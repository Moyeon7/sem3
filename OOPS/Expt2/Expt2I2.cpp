#include<iostream>
using namespace std;
int main(){
    int n, reverse=0, temp;
    cout<<"Enter a number: ";
    cin>>n;
    temp=n;
    for(int i=n; i>0; i/=10){
        reverse= (reverse*10)+(i%10);
    }
    if(temp==reverse){
        cout<<"The enterd number is palindrome"<<endl;
    }else{
        cout<<"The entered number is not palindrome"<<endl;
    }
    return 0;
}