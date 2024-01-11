#include<stdio.h>
#include<stdlib.h>
#define MAX 11
enum type_of_record{EMPTY, DELETED, OCCUPIED};

struct Employee{
	int id;
	char name[20];
	int age;
};
struct Record{
	struct Employee info;
	enum type_of_record status;
};

void insert(struct Employee emprec, struct Record table[], int method);
int search(int key, struct Record table[], int method);
void del(int key, struct Record table[], int);
void display(struct Record table[]);
int hash(int key);
int hash2(int key);

int main(){
	struct Record table[MAX];
	struct Employee emprec;
	int i, key, choice, method, n;

	printf("\nEnter 1-Linear Probing 2-Double Hashing, 3-Quadratic Probing: ");
		scanf("%d", &method);

	for(i=0; i<=MAX-1; i++)
		table[i].status=EMPTY;

	while(1){
		printf("1)Insert a record");
		printf("\n2)Search a record");
		printf("\n3)Delete a record");
		printf("\n4)Display table");
		printf("\n5)Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("\nEnter number of records: ");	scanf("%d", &n);
				for(i=0; i<n; i++){
					printf("\nEnter empid, name, age: ");
					scanf("%d%s%d", &emprec.id, emprec.name, &emprec.age);
					insert(emprec, table, method);
				}
				break;
			case 2:
				printf("\nEnter key to be searched: ");
				scanf("%d", &key);
				i=search(key, table, method);
				if(i==-1)
					printf("\nKey not found\n\n");
				else
					printf("\nKey found at index %d\n\n", i);
				break;
			case 3:
				printf("\nEnter key to be deleted: ");
				scanf("%d", &key);
				printf("\n");
				del(key, table, method);
				break;
			case 4:
				display(table);
				break;
			case 5:
				exit(1);
		}
	}

	return 0;
}

void insert(struct Employee emprec, struct Record table[], int method){
	int i, location, h1,h2;
	int key=emprec.id;
	h1=hash(key);
	h2=hash2(key);
	location=h1;

	for(i=1; i!=MAX-1; i++){
		if(table[location].status==EMPTY || table[location].status==DELETED){
			table[location].info=emprec;
			table[location].status=OCCUPIED;
			printf("\nRecord inserted\n\n");
			return;
		}
		if(table[location].info.id==key){
			printf("\nDuplicate key\n\n");
			return;
		}
		if(method==1)
			location=(h1+i)%MAX;
		else if(method==2)
			location=(h1+(i*h2))%MAX;
		else if(method==3)
			location=(h1+i*i)%MAX;
		else
			printf("\nerror\n");
	}
	printf("\nRecord can't be inserted: Table Overflow\n\n");
}

int search(int key, struct Record table[], int method){
	int i, h1,h2, location;
	h1=hash(key);
	h2=hash2(key);
	location=h1;

	for(i=1; i!=MAX-1; i++){
		if(table[location].status==EMPTY || table[location].status==DELETED)
			return -1;
		if(table[location].info.id==key)
			return location;

		if(method==1)
			location=(h1+i)%MAX;
		else if(method==2)
			location=(h1+(i*h2))%MAX;
		else if(method==3)
			location=(h1+i*i)%MAX;
		else
			printf("\nerror\n");
		
	}
	return -1;
}

void del(int key, struct Record table[], int method){
	int location=search(key, table, method);
	if(location==-1)
		printf("\nKey not found\n");
	else	
		table[location].status=DELETED;
}

void display(struct Record table[]){
	printf("\n");
	int i;
	for(i=0; i<MAX; i++){
		printf("[%d] : ",i);
		if(table[i].status==OCCUPIED)
			printf("Occupied:%d %s %d\n", table[i].info.id, table[i].info.name, table[i].info.age);
		else if(table[i].status==DELETED)
			printf("Deleted\n");
		else
			printf("Empty\n");
	}
	printf("\n");
}

int hash(int key){
	return (key%MAX);
}

int hash2(int key){
	return(7-(key%7));
}














