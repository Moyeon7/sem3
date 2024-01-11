#include<iostream>
using namespace std;

template<class T>
class vector{
    T *v; int size;
    public:
        vector(T a){
            size=a;
            v=new T[size];
            for(int i=0; i<size; i++){
                v[i]=0;
            }
        }

        void getdata();
        void modify(T c);
        void display();
};

template<class T>
void vector <T> :: getdata(){
    for(int i=0; i<size; i++){
        cin>>v[i];
    }
}

template<class T>
void vector <T> :: modify(T c){
    T n;
    for(int i=0; i<size; i++){
        if(c==v[i]){
            cout<<"Enter the new element: ";
            cin>>n;
            v[i]=n;
            return;
        }
    }
    cout<<"Element not found"<<endl;
    return;
}

template<class T>
void vector <T> :: display(){
    cout<<"(";
    for(int i=0; i<size; i++){
        cout<<v[i]<<" ";
    }
    cout<<")"<<endl;
}

int main(){
    int n,mod;
    cout<<"Enter the size of vectors: ";
    cin>>n;

    cout<<"Vector1: ";
    vector <int> v1(3);
    v1.getdata();

    cout<<"Vector2: ";
    vector <int> v2(3);
    v2.getdata();

    cout<<"\nDisplaying:"<<endl;
    v1.display();
    v2.display();

    cout<<"\nModify:"<<endl;
    cout<<"Enter the element you want to modify in vector1: ";
    cin>>mod;
    v1.modify(mod);
    cout<<"Enter the element you want to modify in vector2: ";
    cin>>mod;
    v2.modify(mod);

    cout<<"\nDisplaying:"<<endl;
    v1.display();
    v2.display();

    return 0;
}