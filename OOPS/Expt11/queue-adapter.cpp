#include<iostream>
#include<conio.h>
#include<queue>
using namespace std;
int main()
{
	queue <double> q;

	q.push(1.1);
	q.push(2.2);
	q.push(3.3);

	cout<<"\n\nPopping elements from queue : ";
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}

	getch();
	return 0;
}