#include<stdio.h>
#include<stdlib.h>
#define max 10
#define nil -1

typedef struct s{
        int ar[max];
        int top;
}stack;


int isfull(stack *s){
    if(s->top==max-nil){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(stack *s){
    if(s->top==nil){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack *s,int value){
    if(s->top!=max-1){
        (s->top)++;
        s->ar[s->top] = value;
        printf("Value Inserted\n\n");
    }
    else{
        printf("Your Stack becomes Full so new values can not be inserted \n\n");
    }
}

int pop(stack *s){
    int st;
    if(s->top!=nil){
        st = s->ar[s->top];
        (s->top)--;
        printf("%d is Popped from the stack\n\n",st);
    }
    else{
        printf("Your Stack becomes Empty so values can not be Popped\n\n");
    }
}

int main(){
    stack s;
    s.top = nil;    
    int n,value,disp;
    while(1){
        printf("1-> Check if stack is full\n");
        printf("2-> Check if stack is empty\n");
        printf("3-> Push value into stack\n");
        printf("4-> Pop value from stack\n");
        printf("5-> Exit\n\n");
        printf("Enter your choice :");
        scanf("%d",&n);
        switch(n){
            case 1:if(isfull(&s)==1){
                printf("Your Stack is Full\n\n");
                break;
            }
            else{
                printf("Your Stack is Not Full\n\n");
                break;
            }
            case 2:
                if(isempty(&s)==1){
                printf("Your Stack is Empty\n\n");
                break;
                }
                else{
                    printf("Your Stack is Not Empty\n\n");
                break;
                }

            case 3:
                printf("Enter Value to push into stack :");
                scanf("%d",&value);
                push(&s,value);
                break;
            case 4:
                pop(&s);
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Invalid Choice \n");
                break;
        }

    }
}