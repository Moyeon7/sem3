#include<iostream>
using namespace std;

class student{
    protected:
    int roll_num;
    public:
        void get_num(int a){
            roll_num=a;
        }
        void put_num(){
            cout<<"Roll No.: "<<roll_num<<endl;
        }
};

class test : virtual public student{
    protected:
    float part1, part2;
    public:
        void get_marks(float x, float y){
            part1=x;
            part2=y;
        }
        void put_marks(){
            cout<<"\nMarks obtained: "<<endl;
            cout<<"Part1: "<<part1<<endl;
            cout<<"Part2: "<<part2<<endl;
        }
};

class sports : public virtual student{
    protected:
    float score;
    public:
        void get_score(float s){
            score=s;
        }
        void put_score(){
            cout<<"Sports wt: "<<score<<endl;
        }
};

class result : public test, public sports{
    float total;
    public:
        void display();
};

void result :: display(){
    total=part1 + part2 + score;
    put_num();
    put_marks();
    put_score();
    cout<<"\nTotal score: "<<total<<endl;
}

int main(){
    result student_1;
    student_1.get_num(666);
    student_1.get_marks(29.5, 34.6);
    student_1.get_score(7.0);
    student_1.display();
    return 0;
}