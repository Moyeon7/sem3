#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
void push(long int symbol);
long int pop();
int whitespaces(char symbol);
void infix_postfix();
int instack_priority(char symbol);
int incoming_priority(char symbol);
long int eval_post();
char infix[MAX], postfix[MAX];
long int stack[MAX];
int top=-1;
int call(int, char[]);

int main(){
		long int value;
        printf("Enter the infix: ");
        gets(infix);
        printf("\nSymbol\t\tStack\t\tPostfix\n");
        infix_postfix();
        printf("\nPostfix Expression: %s\n", postfix);

        printf("\nSymbol\t\tStack\n");
        value=eval_post();
        printf("Value of Expression: %d\n", value);

    return 0;
}

void push(long int symbol){
    if(top==MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=symbol;
}

long int pop(){
    if(top==-1){
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int whitespaces(char symbol){
    if((symbol==BLANK)||(symbol==TAB)){
        return 1;
    }
    else{
        return 0;
    }
}

int instack_priority(char symbol){
    switch(symbol){
        case '(':
        case ')':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':
        case '%':return 2;
        case '^':return 3;
    }
}

int incoming_priority(char symbol){
    switch(symbol){
        case '(':
        case ')':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':
        case '%':return 2;
        case '^':return 4;
    }
}

void infix_postfix(){
	int i, p=0;
	char symbol, next;
	for(i=0; i<strlen(infix); i++){
		symbol=infix[i];
        printf("%c", symbol);
        printf("\t\t");
		if(!whitespaces(symbol)){
			switch(symbol){
				case '(':
                        push(symbol); 
                        break;
				case ')':
                        while((next=pop())!='('){
						    postfix[p++]=next;
                        }
                        break;
				case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^': 
                        while((top!=-1)&&instack_priority(stack[top])>=incoming_priority(symbol))
						    postfix[p++]=pop();
					    push(symbol);
                        break;
				default:
                        postfix[p++]=symbol;		
			}		
		}
        for(int j=0; j<=top; j++){
            printf("%c", stack[j]);
        }
        printf("\t\t");
        for(int j=0; j<p; j++){
            printf("%c", postfix[j]);
        }
        printf("\n");
	}
	while(top!=-1)
		postfix[p++]=pop();   
	postfix[p]='\0';

    printf("\t\t\t\t");
    for(int j=0; j<p; j++){
        printf("%c", postfix[j]);
    }
    printf("\n");
}

int call(int i,char postfix[]){
    switch(postfix[i]){
        case 'A':return 3;
        case 'B':return 2;
        case 'C':return 2;
        case 'D':return 2;
        case 'E':return 2;
        case 'F':return 1;
        case '1':return 1;
        case '2':return 2;
        case '3':return 3;
        case '4':return 4;
        case '5':return 5;
        case '6':return 6;
        case '7':return 7;
        case '8':return 8;
        case '9':return 9;
        default:return 0;
    }
}

long int eval_post(){
    long int a,b,temp,result;
    int i;
    for(i=0; i<strlen(postfix); i++){
        printf("%c", postfix[i]);
        printf("\t\t");
        if((postfix[i]<='F' && postfix[i]>='A')  || postfix[i]<='9' && postfix[i]>='0'){
            push(call(i,postfix));
        }else{
            a=pop();
            b=pop();
            switch(postfix[i]){
                case '+':
                    temp=b+a; break;
                case '-':
                    temp=b-a; break;
                case '*':
                    temp=b*a; break;
                case '/': if(a==0){
                            printf("Operation not possible since a==0\n");
                        }
                    temp=b/a; break;
                case '%':
                    temp=b%a; break;
                case '^':
                    temp=(long int)pow(b,a); break;
            }
            push(temp);
        }
        for(int j=0; j<=top; j++){
            printf("%d,", stack[j]);
        }
        printf("\n");
    }
    result=pop();
    return result;
}
