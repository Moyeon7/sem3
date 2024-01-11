#include<iostream>
#include<conio.h>
#include<deque>
using namespace std;
void display(deque <double> &);
int main()
{
	deque <double> d;

	d.push_front(2.2);
	d.push_front(3.5); 
	d.push_back(1.1);

	cout<<"\n\nDeque elements after insertion are as follows :";
	display(d);

	d.pop_front();

	cout<<"\n\nDeque elements after pop_front() are as follows :";
	display(d);

	d[1]=3.3;

	cout<<"\n\nDeque elements after subscript insertion using [] are as follows :";
	display(d);

	getch();
	return 0;
}
void display(deque <double> & d1)
{
	for(int i=0;i<d1.size();i++)
	{
		cout<<" "<<d1[i];
	}
}
