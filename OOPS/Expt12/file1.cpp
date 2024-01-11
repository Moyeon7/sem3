#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int num1[5], num2[3], num3[8];
    cout<<"Enter 5 elements: ";
    for(int i=0; i<5; i++){
        cin>>num1[i];
    } 

    cout<<"Enter 3 elements: ";
    for(int i=0; i<3; i++){
        cin>>num2[i];
    } 

    ofstream fout;
    fout.open("File1");
    for(int i=0; i<5; i++){
        fout<<num1[i]<<endl;
    }
    fout.close();

    fout.open("File2");
    for(int i=0; i<3; i++){
        fout<<num2[i]<<endl;
    }
    fout.close();

    const int n=50;
    char line[n];

    ifstream fin1, fin2;
    fin1.open("File1");
    cout<<"\nFile 1 contents: ";
    while(fin1){
        fin1.getline(line, n);
        cout<<line<<" ";
    }
    fin1.close();

    fin2.open("File2");
    cout<<"\nFile 2 contents: ";
    while(fin2){
        fin2.getline(line, n);
        cout<<line<<" ";
    }
    fin2.close();
    
    int k=0;
    for(int i=0; i<5; i++){
        num3[k]=num1[i];    k++;
    }
    for(int i=0; i<3; i++){
        num3[k]=num2[i];    k++;
    }

    for(int i=0; i<8-1; i++){
        for(int j=i+1; j<8; j++){
            if(num3[i]>num3[j]){
                int tmp=num3[j];
                num3[j]=num3[i];
                num3[i]=tmp;
            }
        }
    }

    fout.open("File3");
    for(int i=0; i<8; i++){
        fout<<num3[i]<<endl;
    }
    fout.close();

    fin1.open("File3");
    cout<<"\nFile 3 contents: ";
    while(fin1){
        fin1.getline(line, n);
        cout<<line<<" ";
    }
    fin1.close();

    cout<<endl;

    return 0;
}