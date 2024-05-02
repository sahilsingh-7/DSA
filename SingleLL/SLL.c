#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node* search(node **temp){
    node *loc = *temp;
    while(loc->next!=NULL){
        loc = loc->next;
    }
    return loc;
}

node* search2(node **temp, int value){
    node *loc = *temp;
    while(loc!=NULL){
        if(loc->info==value){
            return loc;
        }
        else{
            loc=loc->next;
        }
    }
    return NULL;
}


void deleteLL(node **head){
    node *temp = *head;
    while(temp!=NULL){
        temp =  temp->next;
        free(*head);
        *head = temp;
    }
    printf("List deleted Completely\n");
}


void deleteafter(node **head,int value){
    if(*head==NULL){
        printf("Linked List does not exist");
        return;
    }
        node *temp = search2(head,value);
        if(temp!=NULL){
            if(temp->next!=NULL){
                node *back = temp;
                temp = temp->next;
                back->next = temp->next; 
                free(temp);
                temp=NULL;
            }
            else{
                printf("Deletion is Not Possible");
                return;
            }
        }
        else{
            printf("Value Not Found");
            return;
        }
    
}


void deletefromend(node **head){
    node *temp = *head;
    if((*head)->next!=NULL){
        node *back = NULL;
        while(temp->next!=NULL){
            back = temp;
            temp = temp->next;
        }
    back->next = NULL;
    free(temp);
    temp = NULL;
    }
    else if((*head)->next==NULL){
        free(temp);
        temp = NULL;
    }
    else{
        printf("Your Linked List is Empty");
        return;
    }
}


void deletefrombeg(node **head){
    node *temp = *head;
    *head =temp->next;
    free(temp);
    temp=NULL;
}


void insertafter(node **head,int value){
    node *temp = NULL;
    printf("Enter value to be added :");
    int add;
    scanf("%d",&add);
    temp = (node *)malloc(sizeof(node));
    temp->info = add;
    if(*head!=NULL){
        node *loc = search2(head,value);
        if(loc!=NULL){
            temp->next = loc->next;
            loc->next = temp;
        }
        else{
            printf("Match not found");
        }
    }

}



void insertatend(node **head,int value){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = value;
    temp->next = NULL;
    if(*head != NULL){
        node *loc = search(head);
        loc->next = temp;
    }
    else{
        *head = temp;
    }
}



void insertatbeg(node **head,int value){
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->info = value;
    temp->next = NULL;
    if(*head!=NULL){
        temp->next = (*head);
        *head = temp;
    }
    else{
        *head = temp;
    }
}


void printlist(node **head){
    node *temp = NULL;
    temp=*head;
    while(temp!=NULL){
        printf("%d\t",temp->info);
        temp = temp->next;
    }
}

void reverseLL(node **head){
    node *fwdnode,*temp = NULL;
    while((*head)!=NULL){
        fwdnode = (*head)->next;
        (*head)->next = temp;
        temp = *head;
        *head = fwdnode;
    }
    *head = temp;
}

int main(){
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    head->info = 40;
    head->next = NULL;
    // node *head1 = NULL;
    // head1 = (node *)malloc(sizeof(node));
    // head1->info = 45;
    // head1->next = NULL;
    // head->next = head1;

    // head1 = (node *)malloc(sizeof(node));
    // head1->info = 32;
    // head1->next = NULL;
    // head->next->next = head1;


    // insertatbeg(&head,34);

    // insertatend(&head,89);
    // printing every element;
    // insertafter(&head,45);
    // deletefrombeg(&head);
    // deletefromend(&head);
    // deleteafter(&head,32);
    // deleteLL(&head);
    printlist(&head);
    printf("\n");
    reverseLL(&head);
    printlist(&head);

    // printf("%d",head->next->next->info);
    free(head);
    // free(head1);
    head = NULL;
    // head1 = NULL;
}