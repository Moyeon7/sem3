#include<iostream>
using namespace std;
int main(){
    int n, m, temp;
    cout<<"Enter order of matrix: ";
    cin>>n;
    int arr[n][n];
    cout<<"Enter the elements of matrix: \n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    } 
    int j=n;
    for(int i=1; i<=n; i++){           
            temp=arr[i][i];
            arr[i][i]=arr[i][j];
            arr[i][j]=temp;
            j--;
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}