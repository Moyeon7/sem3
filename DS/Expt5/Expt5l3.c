#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev, *next;
    int info;
};

struct node *create(struct node *start);
struct node *addatend(struct node *start, int data);
void display(struct node *start);
struct node *add(struct node *start1, struct node *start2, struct node *start3);

int main() {
    int choice;
    struct node *start1 = NULL, *start2=NULL, *start3=NULL;
    while (1) {
        printf("\n\n1)Create List");
        printf("\n2)Display");
        printf("\n3)Add");
        printf("\n4)Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n1st:\n");
                start1 = create(start1);
                printf("\n2nd:\n");
                start2 = create(start2);
                break;
            case 2:
                printf("\n1st: ");
                display(start1);
                printf("\n2nd: ");
                display(start2);
                printf("\n3rd: ");
                display(start3);
                break;
            case 3:
                start3=add(start1, start2, start3);
                break;
            case 4:
                exit(1);
        }
        
    }

    return 0;
}

struct node *add(struct node *start1, struct node *start2, struct node *start3) {
    struct node *p1, *p2;
    p1 = start1;
    p2 = start2;
    start3 = NULL; // Initialize start3 to an empty list
    int carry = 0;

    while (p1 != NULL || p2 != NULL || carry != 0) {
        int sum = carry;

        if (p1 != NULL) {
            sum += p1->info;
            p1 = p1->next;
        }

        if (p2 != NULL) {
            sum += p2->info;
            p2 = p2->next;
        }

        carry = sum / 10;
        sum %= 10;

        start3 = addatend(start3, sum);
    }

    return start3;
}

struct node *addatend(struct node *start, int data) {
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = NULL;
    if (start == NULL) {
        tmp->prev = NULL;
        start = tmp;
    } else {
        p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
        tmp->prev = p;
    }
    return start;
}

void display(struct node *start) {
    struct node *p;
    if (start == NULL) {
        printf("\nList is empty");
        return;
    }
    p = start;
    printf("\nList Elements:\n");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }
}

struct node *create(struct node *start) {
    int i, n, data;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = n; i > 0; i/=10) {
        data=i%10;
        start = addatend(start, data);
    }
    return start; 
}