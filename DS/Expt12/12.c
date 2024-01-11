#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node{
	int info;
	struct node *link;
};

void insertion_sort(int arr[], int n);

struct node *create(int arr[], int n, struct node *start);
struct node *merge_sort(struct node *start);
struct node *divide(struct node *p);
struct node *merge(struct node *p1, struct node *p2);
void display_m(struct node *start);

void quick(int arr[], int low, int up);
int partition(int arr[], int low, int up);

void heap_sort(int arr[], int n);
void buildHeap(int arr[], int size);
int del(int arr[], int *size);
void restoredown(int ar[], int i, int size);

int main(){

	int choice,n, arr[MAX];
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter array elements: ");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	struct node *start=NULL;

	printf("\n");
	printf("\n1)Sorting using Insertion Sort");
	printf("\n2)Sorting using Merge Sort(linked list)");
	printf("\n3)Sorting using Quick Sort");
	printf("\n4)Sorting using Heap Sort");
	printf("\nSelect any one sorting method: ");
	scanf("%d", &choice);

	switch(choice){
		case 1:
			insertion_sort(arr,n);
			printf("\nList is Sorted");
			printf("\nList is: ");
			for(int i=0; i<n; i++){
				printf("%d ", arr[i]);
			}
			break;
		case 2:
			start=create(arr, n, start);
			start=merge_sort(start);
			display_m(start);
			break;
		case 3:
			quick(arr,0,n-1);
			printf("\nList is Sorted");
			printf("\nList is: ");
			for(int i=0; i<n; i++){
				printf("%d ", arr[i]);
			}
			break;
		case 4:
            heap_sort(arr,n);
            printf("\nList is Sorted");
			printf("\nList is: ");
			for(int i=0; i<n; i++){
				printf("%d ", arr[i]);
			}
            break;


	}

	return 0;
}

void insertion_sort(int arr[], int n){
	int i, j;
	for(i=1; i<n; i++){
		int current =arr[i];
		for(j=i-1; j>=0 && current<arr[j]; j--){
			arr[j+1]=arr[j];
		}
		arr[j+1]=current;
		for(int k=0; k<n; k++){
				printf("%d ", arr[k]);
		}
		printf("\n");
	}
}

struct node *create(int arr[], int n, struct node *start){
	struct node *tmp, *p;
	for(int i=0; i<n; i++){
		tmp=malloc(sizeof(struct node));
		tmp->info=arr[i];
		tmp->link=NULL;
		if(start==NULL)
			start=tmp;
		else{
			p=start;
			while(p->link!=NULL)
				p=p->link;

			p->link=tmp;
		}
	}
	return start;
}

struct node *merge_sort(struct node *start){
	struct node *start_first, *start_second, *start_merged;
	if(start!=NULL && start->link!=NULL){
		start_first=start;
		start_second=divide(start);
		printf("\nFirst Part: ");
        display_m(start_first);
        printf("Second Part: ");
        display_m(start_second);
		start_first=merge_sort(start_first);
		start_second=merge_sort(start_second);
		printf("\nMerging: ");
        display_m(start_first);
        display_m(start_second);
		start_merged=merge(start_first, start_second);
		return start_merged;
	}else
		return start;
}

struct node *divide(struct node *p){
	struct node *q, *start_second;
	q=p->link->link;
    while(q!=NULL){
		p=p->link;
		q=q->link;
		if(q!=NULL)
			q=q->link;
    }
    start_second=p->link;
    p->link=NULL;
    return start_second;
}

struct node *merge(struct node *p1, struct node *p2){
	struct node *start_merged, *q;
	if(p1->info<=p2->info){
		start_merged=p1;
		p1=p1->link;
	}else{
		start_merged=p2;
		p2=p2->link;
	}
	q=start_merged;
	while(p1!=NULL && p2!=NULL){
		if(p1->info<=p2->info){
			q->link=p1;
			q=q->link;
			p1=p1->link;
		}else{
			q->link=p2;
			q=q->link;
			p2=p2->link;
		}
	}
	if(p1!=NULL)
		q->link=p1;
	else
		q->link=p2;
	return start_merged;

}

void display_m(struct node *start){
	struct node *p;
	if(start==NULL){
		printf("\nEmpty\n");
		return;
	}
	p=start;
	printf("List is: ");
	while(p!=NULL){
		printf("%d ", p->info);
		p=p->link;
	}
	printf("\n");
}

void quick(int arr[], int low, int up){
	int pivloc;
	if(low>=up)
		return;
	pivloc=partition(arr,low, up);
	printf("\nPartitioned Array: ");
    for (int i = low; i <= up; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
	quick(arr, low, pivloc-1);
	quick(arr, pivloc+1, up);
}

int partition(int arr[], int low, int up){
	int temp,i,j,pivot;
	i=low+1;
	j=up;
	pivot=arr[low];
	while(i<=j){
		while((arr[i]<pivot)&&(i<up))
			i++;
		while(arr[j]>pivot)
			j--;
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;	j--;
		}else
			i++;
	}
	arr[low]=arr[j];
	arr[j]=pivot;
	return j;
}

void heap_sort(int arr[], int size){
	int max;
	printf("\nInitial Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
	buildHeap(arr, size);
	printf("Max Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

	while(size>0){
		max=del(arr, &size);
		arr[size+1]=max;
		printf("\nHeap after extracting max: ");
        for (int i = 0; i < size+1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
	}
}

void buildHeap(int arr[], int size){
	int i;
	for(i=size/2; i>=0; i--)
		restoredown(arr,i,size);
}

int del(int arr[], int *size){
	int max=arr[0];
	arr[0]=arr[*size];
	(*size)--;
	restoredown(arr, 0, *size);
	return max;
}

void restoredown(int arr[], int i, int size){
	int left=2*i, right=left+1;
	int num=arr[i];
	while(right<=size){
		if(num>=arr[left] && num>=arr[right]){
			arr[i]=num;
			return;
		}else if(arr[left]>arr[right]){
			arr[i]=arr[left];
			i=left;
		}else{
			arr[i]=arr[right];
			i=right;
		}
		left=2*i;
		right=left+1;
	}
	if(left==size && num<arr[left]){
		arr[i]=arr[left];
		i=left;
	}
	arr[i]=num;
}

