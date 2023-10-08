#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev, *next;
    int info;
};

struct node *create(struct node *start);
struct node *addatend(struct node *start, int data);
struct node *del(struct node *start, int data);
struct node *rev(struct node *start);
void display(struct node *start);
struct node *swap(struct node *start);

int main() {
    int choice, data, item;
    struct node *start = NULL;
    while (1) {
        printf("\n\n1)Create List");
        printf("\n2)Delete Element");
        printf("\n3)Reverse");
        printf("\n4)Display");
        printf("\n5)Swap adjacent element");
        printf("\n6)Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = create(start);
                break;
            case 2:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &data);
                start = del(start, data);
                break;
            case 3:
                start = rev(start);
                printf("\nList is reversed");
                break;
            case 4:
                display(start);
                break;
            case 5:
                start=swap(start);
                printf("\nAdjacent elements swapped");
                break;
            case 6:
                exit(1);
        }
    }

    return 0;
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

struct node *del(struct node *start, int data) {
    struct node *tmp;
    tmp = start; 
    if (start == NULL) {
        printf("\nEmpty\n");
        return start;
    }
    while (tmp != NULL) {
        if (tmp->info == data) {
            if (tmp->prev != NULL) {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next != NULL) {
                tmp->next->prev = tmp->prev;
            }
            if (tmp == start) {
                start = tmp->next;
            }
            free(tmp);
            return start;
        }
        tmp = tmp->next;
    }
    printf("\nElement not found\n");
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

struct node *rev(struct node *start) {
    struct node *p1, *p2;
    p1 = start;
    p2 = start->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL) {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    return start;
}

struct node *create(struct node *start) {
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter the %d element: ", i);
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start; 
}

struct node *swap(struct node *start){
    struct node *t1, *t2;
    if (start == NULL || start->next == NULL) {
        printf("Empty or only one node in the list. Nothing to swap.\n");
        return start;
    }
    t1 = start;
    t2 = start->next;

    while (t1 != NULL && t2 != NULL) {
        struct node *temp = t2->next;
        t2->next = t1;
        t2->prev = t1->prev;
        t1->prev = t2;
        t1->next = temp;

        if (t1->next != NULL) {
            t1->next->prev = t1;
        }

        if (t2->prev != NULL) {
            t2->prev->next = t2;
        }

        if (t1 == start) {
            start = t2;
        }

        t1 = temp;
        if (t1 != NULL) {
            t2 = t1->next;
        }
    }

    return start;
}
