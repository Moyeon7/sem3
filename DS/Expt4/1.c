#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
}*front=NULL, *rear=NULL;

void insert(int item);
void del();
void peek();
int isEmpty();
void display();

int main(){
    int choice, item;
    while(1){
        printf("\n\n1)Insert");
        printf("\n2)Delete");
        printf("\n3)Peek");
        printf("\n4)Display");
        printf("\n5)Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                printf("\nEnter the element to be inserted in the queue: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                del();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("\nWrong choice");
        }
    }
    return 0;
}

void insert(int item){
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info = item;
    tmp->link=NULL;
    if(front==NULL){
        front=tmp;
    }else{
        rear->link=tmp;
    }
    rear=tmp;
}

void del(){
    struct node *tmp;
    if(isEmpty()){
        printf("\nQueue Undeflow");
        return;
    }
    tmp=front;
    printf("\nDeleted element is %d", tmp->info);
    front=front->link;
    free(tmp);
}

void peek(){
    if(isEmpty()){
        printf("\nQueue Underflow");
        return;
    }
    printf("\nElement at the front of the queue is %d", front->info);
}

void display(){
    struct node *p;
    if(isEmpty()){
        printf("\nQueue Underflow");
        return;
    }
    p=front;
    printf("\nQueue Elements:\n");
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->link;
    }
}

int isEmpty(){
    if(front==NULL){
        return 1;
    }else{
        return 0;
    }
}
