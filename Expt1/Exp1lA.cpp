#include<iostream>
using namespace std;

class student{
    char name[20];
    char branch[10];
    float total, percentage;
    int maths, ld, ds, oops, co;

    public:
        int input(int);
        void display();
        void marks();
        void compute();  
        int rollno=0;
};

int student :: input(int i){
    cout<<"\nEnter your name: ";
    cin.getline(name,20);
    rollno=rollno+1+i;
    cout<<"\nEnter your branch: ";
    cin>>branch;
    std::cin.ignore();
    cout<<endl;
    return 1;
}

void student :: display(void){
    cout<<"\nName = "<<name;
    cout<<"\nRoll.No = "<<rollno;
    cout<<"\nBranch = "<<branch<<"\n"<<endl;;
}

void student :: marks(){
    cout<<"\nEnter The marks of Maths: ";
    cin>>maths;
    cout<<"\nEnter The marks of ld: ";
    cin>>ld;
    cout<<"\nEnter The marks of ds: ";
    cin>>ds;
    cout<<"\nEnter The marks of oops: ";
    cin>>oops;
    cout<<"\nEnter The marks of co: ";
    cin>>co;
    cout<<endl;
    std::cin.ignore();
}

void student :: compute(void){
    total=maths+ld+ds+oops+co;
    percentage=(total/500)*100;
    cout<<"\n"<<name<<"'s Percentage = "<<percentage<<"%\n"<<endl;
    // std::cin.ignore();
}

int main(){
    int choice, rn, t, count=0;

    student s[3];

    while(1){
        cout<<"\n1) Details\n";
        cout<<"2) Display\n";
        cout<<"3) Compute\n";
        cout<<"4) Exit\n";

        cout<<"\nSelect your option: ";
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
                cout<<"Enter details of 3 student: \n";
                std::cin.ignore();
                for(int i=0; i<3; i++){
                    s[i].input(i);
                    s[i].marks();
                }
                count++;
                break;
            case 2:
                if(count==0){
                    cout<<"THERE ARE NO DETAILS TO BE DISPLAYED\n";
                    break;
                }
                cout<<"Enter your Roll No. to display details:\n";
                cin>>rn;
                s[rn-1].display();
                break;
            case 3:
                if(count==0){
                    cout<<"THERE ARE NO MARKS TO BE COMPUTED\n";
                    break;
                }
                cout<<"Enter your Roll No. to compute your marks:";
                cin>>rn;
                s[rn-1].compute();
                break;
            case 4:
                exit(1);
            default:
                cout<<"~Invalid choice~"<<endl;
                break;
        }
    }

    return 0;
}