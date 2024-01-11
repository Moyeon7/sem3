#include<iostream>
using namespace std;
int count=0;

class temp{
    public:
        temp(){
            count++;
            cout<<"No. of object created: "<<count<<endl;
        }
        ~temp(){
            cout<<"No. of objects remaining: "<<count<<endl;
            count--;
        }
};

int main(){
    cout<<"\t ENTER MAIN"<<endl; 
    temp t1,t2,t3,t4;
    {
        cout<<"\n\t ENTER BLOCK1"<<endl;
        temp t5;
    }
    {
        cout<<"\n\t ENTER BLOCK2"<<endl;
        temp t6;
    }
    cout<<"\n\t RE-ENTER MAIN"<<endl;
    return 0;
}