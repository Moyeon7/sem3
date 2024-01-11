#include<iostream>
using namespace std;

int main(){

    string s1, s2, s3;
    cout<<"\nSTRING ASSINGMENT"<<endl;
    s1="Apple";
    s2=" is a fruit.";
    cout<<"string 1: "<<s1<<endl;
    cout<<"string 2: "<<s2<<endl;

    cout<<"\nSTRING CONCATENATION"<<endl;
    s3=s1+s2;
    cout<<"The concatenation of string 1 and string 2 is: "<<s3<<endl;

    cout<<"\nSTRING COMPARISON"<<endl;
    if(s1>s2){
        cout<<"String 1 is greater than string 2"<<endl;
    }else{
        cout<<"String 2 is greater than string 1"<<endl;
    }

    cout<<"\nSEARCHING OF CHARACTERS AND SUBSTRINGS IN A STRING"<<endl;
    cout<<"Character 'l' in string 1 is at position: "<<s1.find('l')<<endl;
    cout<<"Character 'f' in string 2 is at position: "<<s2.find('f')<<endl;
    cout<<"Substring 'App' in string 3 is at position: "<<s3.find("App")<<endl;

    cout<<"\nSTRING SWAPPING"<<endl;
    string a1="Tea";
    string a2="Coffee";
    cout<<"Before swapping"<<endl;
    cout<<"string 1: "<<a1<<endl;
    cout<<"string 2: "<<a2<<endl;
    string a3;
    a3=a1;
    a1=a2;
    a2=a3;
    cout<<"After swapping"<<endl;
    cout<<"string 1: "<<a1<<endl;
    cout<<"string 2: "<<a2<<endl;


    return 0;
}