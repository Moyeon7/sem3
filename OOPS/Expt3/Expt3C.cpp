#include<iostream>
#include<string.h>
using namespace std;

class temp{
    char *name;
    int len;
    public:
        temp(){
            name=NULL;
            len=0;
        }
        temp(const char *n){
            len=strlen(n);
            name= new char[len+1];
            strcpy(name,n);
        }
        void display(){
            cout<<"Output: "<<name<<endl;
        }

        void join(temp &n1, temp &n2){
            len=n1.len + n2.len;
            name= new char[len+1];
            strcpy(name,n1.name);
            strcat(name,n2.name);
        }
    
};

int main(){
    const char *f1="Goa";
    temp name1(f1), name2("College"),name3("Engineering"),s1,s2;  
    s1.join(name1,name2);
    s2.join(s1,name3);    
    s2.display();

    return 0;
}