#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;
char a1[MAX], b2[MAX];

class String{
    int len;
    char *p;
    public:
        String(){
            len = 0;
            p = NULL;
        }
        friend String operator+(class String a, class String b);
        friend int operator<(class String a, class String b);
        String(char *p);
        friend ostream &operator<<(ostream &output, class String &s);
};

ostream &operator<<(ostream &output, class String &s){
    if (s.p == NULL){
        cout << "The string does not exist\n";
        return output;
    }
    cout << s.p;
}

String::String(char *s){
    len = strlen(s);
    p = new char[len];
    strcpy(p, s);
}

String operator+(class String a, class String b){
    String temp;
    temp.len = a.len + b.len;
    temp.p = new char[a.len + b.len];
    strcpy(temp.p, a.p);
    strcat(temp.p, b.p);
    return (temp);
}

int operator<(String a, String b){
    if (a.len < b.len)
        return 1;
    else if (a.len > b.len)
        return 2;
    return 3;
}

int main(int argc, char const *argv[]){
    cout << "Enter String 1: ";
    gets(a1);
    cout << "Enter String 2: ";
    gets(b2);
    String s1(a1), s2(b2), s3;
    cout<<"\nAdding two strings:\n";
    s3 = s1 + s2;
    cout<<"After Addition: "<<s3<<endl;
    cout<<"\nComparing 2 strings: "<<endl;
    if((s1 < s2) == 1)
        cout << "Length of \"" << s1 << "\" is less than \"" << s2 << "\"" << endl;
    else if((s1 < s2) == 2)
        cout << "Length of \"" << s2 << "\" is less than \"" << s1 << "\"" << endl;
    else
        cout << "Length of \"" << s1 << "\" is the same as \"" << s2 << "\"" << endl;
    return 0;
}