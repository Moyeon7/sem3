#include<iostream>
using namespace std;

void test(int x){
    try{
        if(x==0)
            throw x;
        else if(x==1)
            throw 'c';
        else    
            throw 2.2;
    }
    catch(int){
        cout<<"Exception int caught"<<endl;
    }
    catch(char){
        cout<<"Exception char caught"<<endl;
    }
    catch(double){
        cout<<"Exception double caught"<<endl;
    }
}

int  main(){

    test(1),test(0),test(-1);

    return 0;
}
