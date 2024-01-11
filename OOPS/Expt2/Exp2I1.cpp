#include<iostream>
using namespace std;
int main(){
    int arr[7]={1,2,3,44,5,6,7};
    int max=arr[0];
    for(int i=1; i<7; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"The maximum element in the array is "<<max<<endl;
    return 0;
}