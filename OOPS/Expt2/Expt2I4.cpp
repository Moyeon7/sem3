#include<iostream>
using namespace std;
int main(){
    int n, count=0, digit;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=n; i>0; i/=10){
        count++;
    }
    int arr[count];
    for(int i=1; i<=count; i++){
        digit= n%10;
        arr[i] = {digit};
        n=n/10;
    }
    cout<<"The first digit of entered number is "<<arr[count]<<endl;
    cout<<"The last digit of entered number is "<<arr[1]<<endl;    
    return 0;
}