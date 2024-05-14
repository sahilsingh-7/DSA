#include<stdio.h>
#include<stdlib.h>

#define max 10
#define nil -1

typedef struct s {
    int arr[10];
    int front;
    int rear;
} queue;

void insert(queue *q, int value) {
    if(q->rear < max-1) {
        q->rear++;
        q->arr[q->rear] = value;
    } else {
        printf("Queue is Full \n");
    }
}

void removve(queue *q) {
    int s;
    if(q->front < q->rear) {
        q->front++;
        s = q->arr[q->front];
        printf("%d is removed from queue\n", s);
    } else {
        printf("Queue is Empty \n");
        q->front = nil;
        q->rear = nil;
    }
}

int main() {
    int value, n;
    queue q;
    q.front = nil;
    q.rear = nil;
    
    while(1) {
        printf("1-> insert into queue\n");
        printf("2-> delete from queue\n");
        printf("3-> Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &n);

        switch(n) {
            case 1:
                printf("Enter value to be inserted :");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                removve(&q);
                break;
            case 3:
                exit(1);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
