#include<stdio.h>
#define MAX 20
struct Employee{
	int id;
	char name[20];
	char address[20];
}e[MAX];

void linear(int ID, int n){
	for(int i=1; i<=n; i++){
		if(ID==e[i].id){
			printf("\nFound\n\n");
			printf("ID: %d", e[i].id);
			printf("\nName: %s", e[i].name);
			printf("\nAddress:%s", e[i].address);
			return;
		}
	}
	printf("\nNot Found\n");
}

void binary(int ID, int n){
	int low=1, up=n, mid;
	for(int i=1; i<=n; i++){
		mid=(low+up)/2;
		if(ID<e[i].id)
			up=mid-1;
		else if(ID>e[i].id)
			low=mid+1;
		else{
			printf("\nFound\n\n");
			printf("ID: %d", e[i].id);
			printf("\nName: %s", e[i].name);
			printf("\nAddress:%s", e[i].address);
			return;
		}
	}
	printf("\nNot Found\n");
}

int main(){
	int ID, n ,check=0, choice;
	char Name[20], add[20];

	printf("Enter the No. of entries: ");
	scanf("%d", &n);

	printf("Enter the 1 for linear search and 2 for binary search\n");
	scanf("%d", &choice);

	if(choice==1){
		for(int i=1; i<=n; i++){
			printf("\nEnter the id: ");
			scanf("%d", &e[i].id);

			printf("Enter name: ");
			scanf("%s", e[i].name);

			printf("Enter address: ");
			scanf("%s", e[i].address);
		}
	}else{
		printf("Enter in a sequence\n");
		for(int i=1; i<=n; i++){
			printf("\nEnter the id: ");
			scanf("%d", &e[i].id);

			printf("Enter name: ");
			scanf("%s", e[i].name);

			printf("Enter address: ");
			scanf("%s", e[i].address);
		}
	}

	printf("\nEnter the ID to be searched: ");
	scanf("%d",&ID);

	if(choice==1){
		printf("\nUsing Linear Search\n");
		linear(ID, n);
	}else{
		printf("\nUsing Binary Search\n");
		binary(ID, n);
	}
	return 0;
}
