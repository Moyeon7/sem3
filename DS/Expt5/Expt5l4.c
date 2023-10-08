#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *link;;
    int info;
};

struct node *create(struct node *last);
struct node *addatend(struct node *last, int data);
void display(struct node *last);
struct node *del(struct node *last);

int main() {
    int choice;
    struct node *last = NULL;;
    while (1) {
        printf("\n\n1)Create List");
        printf("\n2)Display");
        printf("\n3)Delete alternate nodes");
        printf("\n4)Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                last = create(last);
                break;
            case 2:
                display(last);
                break;
            case 3:
                last=del(last);
                printf("\nAlternate nodes are deleted");
                break;
            case 4:
                exit(1);
        }
        
    }

    return 0;
}

struct node *del(struct node *last) {
    if (last == NULL) {
        printf("\nList is empty"); 
        return last; 
    }

    struct node *current = last; 
    struct node *tmp;
    if(last->link==last){
        tmp=last;
        last=NULL;
        free(tmp);
        return last;
    }
    int flag=0;
    do {
        tmp = current->link;
        if(current->link==last){
            last=current;
            flag=1;
        }
        current->link = tmp->link;
        free(tmp);
        current = current->link;
    } while (current != last && flag==0);

    return last; 
}

struct node *addatend(struct node *last, int data) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link=last->link;
    last->link=tmp;
    last=tmp;
    return last;
}

struct node *addtoempty(struct node *last, int data){
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    last=tmp;
    last->link=last;
    return last;
}

void display(struct node *last) {
    struct node *p;
    if (last == NULL) {
        printf("\nList is empty");
        return;
    }
    p = last->link;
    printf("\nList Elements:\n");
    do {
        printf("%d ", p->info);
        p = p->link;
    }while (p != last->link);
    printf("\n");
}

struct node *create(struct node *last) {
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if(n==0)
        return last;
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    last = addtoempty(last, data);    
    for (i=2; i<=n; i++) {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        last = addatend(last, data);
    }
    return last; 
}