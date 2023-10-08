#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};

struct node *addatend(struct node *start, int data){
    struct node *tmp, *p;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p->link!=NULL)
        p=p->link;
    tmp->link=NULL;
    p->link=tmp;
    return start;
}

void display(struct node *start) {
    struct node *p;
    if (start == NULL) {
        printf("List is empty: \n");
        return;
    }
    p = start;
    printf("is:\n");
    while (p!= NULL) {
        printf("%d", p->info);
        p = p->link;
    }
    printf("\n\n");
}

struct node * create(struct node *start){
    int i, n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    start=NULL;
    if(n==0)
        return start;
    
    for(i=1; i<=n; i++){
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        start=addatend(start, data);
    }
    return start;
}

void unionn(struct node *set1, struct node *set2){
    struct node *result=NULL;
    while(set1->link!=NULL || set2->link!=NULL){
        if(set1!=NULL && set2!=NULL && set1->info==set2->info){
            addatend(result, set1->info);
            set1=set1->link;
            set2=set2->link;
        }else if(set1!=NULL && (set2==NULL || set1->info < set2->info)){
            addatend(result, set1->info);
            set1=set1->link;
        }else{
            addatend(result, set2->info);
            set2=set2->link;
        }
    }
    display(result);
    return;
}

int main(){
    struct node *set1, *set2;
    int choice;

    printf("Set A:\n");
    set1=create(set1);
    printf("Set B:\n");
    set2=create(set2);

    while(1){
        printf("\n1)Union");
        printf("\n2)Interaction");
        printf("\n3)Difference");
        printf("\n4)Exit");
        printf("\nEnter choice");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                unionn(set1,set2);
                break;
            case 4:
                exit(1);
        }
    }


    return 0;
}