#include<iostream>
using namespace std;

int fact(int store){
    int factorial=1;
    for(int i=1; i<=store; i++){
        factorial*=i;
    }
    return factorial;
}

int k_num(int &n){
    int store, add=0;
    cout<<n<<endl;
    for(int i=n; i>0; i/=10){
        store=i%10;
        add+=fact(store);
    }
    return add;
}

int main(){

    int n, temp, ans;
    cout<<"Enter a number: ";
    cin>>n;
    temp=n;

    ans = k_num(n); 

    cout<<ans<<endl;

    if(ans==temp){
        cout<<"Is k num:\n";
    }else{
        cout<<"not\n";
    }

    return 0;
}