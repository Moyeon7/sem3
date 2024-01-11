#include<stdio.h>	//separate chaining
#include<stdlib.h>
#define MAX 11

struct Employee{
	int id;
	char name[20];
	int age;
};
struct Record{
	struct Employee info;
	struct Record *link;
};

void insert(struct Employee emprec, struct Record *table[]);
int search(int key, struct Record *table[]);
void del(int key, struct Record *table[]);
void display(struct Record *table[]);
int hash(int key);

int main(){
	struct Record *table[MAX];
	struct Employee emprec;
	int i, key, choice;

	for(i=0; i<=MAX-1; i++)
		table[i]=NULL;

	while(1){
		printf("\n1)Insert a record");
		printf("\n2)Search a record");
		printf("\n3)Delete a record");
		printf("\n4)Display table");
		printf("\n5)Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("\nEnter empid, name, age: ");
				scanf("%d%s%d", &emprec.id, emprec.name, &emprec.age);
				insert(emprec, table);
				break;
			case 2:
				printf("\nEnter key to be searched: ");
				scanf("%d", &key);
				i=search(key, table);
				if(i==-1)
					printf("\nKey not found");
				else
					printf("\nKey found in chain %d\n", i);
				break;
			case 3:
				printf("\nEnter key to be deleted: ");
				scanf("%d", &key);
				del(key, table);
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

void insert(struct Employee emprec, struct Record *table[]){
	int h, key;
	struct Record *tmp;
	key=emprec.id;

	if(search(key, table)!=-1){
		printf("\nDuplicate key\n");
		return;
	}
	h=hash(key);

	tmp=malloc(sizeof(struct Record));
	tmp->info=emprec;
	tmp->link=table[h];
	table[h]=tmp;
}

void display(struct Record *table[]){
	int i;
	struct Record *ptr;

	for(i=0; i<MAX; i++){
		printf("\n[%d] ", i);
		if(table[i]!=NULL){
			ptr=table[i];
			while(ptr!=NULL){
				printf("%d %s %d\t", ptr->info.id, ptr->info.name, ptr->info.age);
				ptr=ptr->link;
			}
		}
	}
	printf("\n");
}

int search(int key, struct Record *table[]){
	int h;
	struct Record *ptr;

	h=hash(key);
	ptr=table[h];
	while(ptr!=NULL){
		if(ptr->info.id==key)
			return h;
		ptr=ptr->link;
	}
	return -1;
}

void del(int key, struct Record *table[]){
	int h;
	struct Record *tmp, *ptr;
	h=hash(key);

	if(table[h]==NULL){
		printf("\nKey %d not found\n", key);
		return;
	}
	if(table[h]->info.id==key){
		tmp=table[h];
		table[h]=table[h]->link;
		free(tmp);
		return;
	}
	ptr=table[h];

	while(ptr->link!=NULL){
		if(ptr->link->info.id==key){
			tmp=ptr->link;
			ptr->link=tmp->link;
			free(tmp);
			return;
		}
		ptr=ptr->link;
	}
	printf("\nKey %d not found\n", key);
}

int hash(int key){
	return (key%MAX);
}