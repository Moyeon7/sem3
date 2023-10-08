#include<stdio.h>
#include<stdlib.h>

struct node{
    int coefficient, exponent;
    struct node *link;
};

struct node *addatend(struct node *start, int c, int e){
    struct node *tmp2, *p;
    tmp2=(struct node *)malloc(sizeof(struct node));

    tmp2->coefficient=c;
    tmp2->exponent=e;
    
    if(start==NULL){
        tmp2->link=start;
        start=tmp2;
    }
    
    p=start;
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=tmp2;
    tmp2->link=NULL;
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
    while (p != NULL) {
        printf("%d*x^%d", p->coefficient, p->exponent);
        p = p->link;
        if(p!=NULL)
            printf(" + ");
    }
    printf("\n\n");
}

struct node* delete(struct node* start, int pos){
    if (pos == 1) {
        struct node* temp = start;
        start = start->link;
        free(temp);
    } else {
        struct node* current = start;
        int i;

        
        for (i = 1; i < pos - 1 && current != NULL; i++) {
            current = current->link;
        }

        if (current == NULL || current->link == NULL) {
            printf("Invalid position to delete.\n");
        } else {
            struct node* temp = current->link;
            current->link = temp->link;
            free(temp);
        }  
    }

    return start; 
}

void modify(struct node* start, char t) {
    struct node* ptr;
    int pos, c, e;
    ptr = start;

    if (t == 'a') {
        printf("Enter the new coefficient and exponent: ");
        scanf("%d %d", &c, &e);

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->coefficient = c;
        newNode->exponent = e;
        newNode->link = NULL;

        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = newNode;

        display(start); 
    } else if (t == 'b') {
        printf("Enter the position of the node you want to delete: ");
        scanf("%d", &pos);

        start=delete(start, pos);
        display(start);
    }
}

struct node* create(struct node* start, FILE* file) {
    int c, e;
    char line[100]; 

    if (file == NULL) {
        int n;
        printf("Enter the number of terms: ");
        scanf("%d", &n);

        start = NULL;
        if (n == 0) {
            return start;
        }

        for (int i = 1; i <= n; i++) {
            printf("Enter the coefficient and exponent to be inserted: ");
            scanf("%d %d", &c, &e);
            start = addatend(start, c, e);
        }
        
    } else {
        while (fgets(line, sizeof(line), file) != NULL) {
            sscanf(line, "%d %d", &c, &e);
            start = addatend(start, c, e);
        }
    }

    return start;
}


void multiplication(struct node *poly1, struct node *poly2){
    struct node *result;
    struct node *ptr=poly2;
    result=NULL;

    if(poly1==NULL || poly2==NULL){
        printf("Multiplied polynomial is zero polynomial\n");
        return;
    }
    while(poly1!=NULL){
        poly2=ptr;
        while(poly2!=NULL){
            result=addatend(result,poly1->coefficient*poly2->coefficient, poly1->exponent+poly2->exponent);
            poly2=poly2->link;
        }
        poly1=poly1->link;
    }
    printf("Multiplied polynomial is:\n");
    display(result);
}

void addition(struct node *poly1, struct node *poly2){
    struct node *result;
    result=NULL;
    while(poly1!=NULL && poly2!=NULL){
        if(poly1->exponent>poly2->exponent){
            result=addatend(result,poly1->coefficient,poly1->exponent);
            poly1=poly1->link;
        }else if(poly2->exponent>poly1->exponent){
            result=addatend(result,poly2->coefficient,poly2->exponent);
            poly2=poly2->link;
        }else if(poly1->exponent==poly2->exponent){
                result=addatend(result, poly1->coefficient+poly2->coefficient, poly1->exponent);
                poly1=poly1->link;
                poly2=poly2->link;
        }
    }
    while(poly1!=NULL){
        result=addatend(result, poly1->coefficient, poly1->exponent);
        poly1=poly1->link;
    }

    while(poly2!=NULL){
        result=addatend(result, poly2->coefficient, poly2->exponent);
        poly2=poly2->link;
    }

    printf("Added Polynomial is:\n");
    display(result);
}

int main(){
    FILE *fptr1, *fptr2;
    fptr1=fopen("pe.txt", "w");
    fprintf(fptr1,"4 3\n5 2\n-3 1\n"); 
    fclose(fptr1);
    fptr2=fopen("pe2.txt", "w");
    fprintf(fptr2,"2 5\n6 4\n1 2\n8 0"); 
    fclose(fptr2);
    struct node *poly1=NULL, *poly2=NULL;
    int choice, m;
    char t;
    while(1){
        printf("1) Create \n");
        printf("2) Accept 2 polynomials from a file \n");
        printf("3) Display\n");
        printf("4) Addition\n");
        printf("5) Multiplication\n");
        printf("6) Modify\n");
        printf("7) Exit\n");

        printf("Select: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                printf("For poly 1:\n");
                poly1=create(poly1, NULL);
                printf("For poly 2:\n");
                poly2=create(poly2, NULL);
                break;
            case 2:
                fptr1 = fopen("pe.txt", "r"); 
                poly1 = create(poly1, fptr1);
                fclose(fptr1); 
                fptr2 = fopen("pe2.txt", "r");
                poly2 = create(poly2, fptr2); 
                fclose(fptr2);
            case 3:
                printf("Poly 1:\n");
                display(poly1);
                printf("Poly 2:\n");
                display(poly2);
                break;
            case 4:
                printf("Addition: \n");
                addition(poly1, poly2);
                break;
            case 5:
                printf("Multiplication: \n");
                multiplication(poly1, poly2);
                break;
            case 6:
                printf("Enter which polynomial u need to modify(1 or 2): ");
                scanf("%d", &m);
                while (getchar() != '\n');
                printf("a)Insert Term \nb)Delete Term\n");
                scanf("%c", &t);
                if(m==1)
                    modify(poly1, t);
                else if(m==2)
                    modify(poly2, t);
                break;
            case 7:
                exit(1);
                
        }
    }

    return 0;
}