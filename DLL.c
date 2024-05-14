#include<stdio.h>
#include<stdlib.h>

typedef struct DLL
{
    struct DLL *prev;
    int info;
    struct DLL *next;
}node;


void insertatbeg(node **head,node **tail,int value){
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->info = value;
    temp->prev = NULL;
    temp->next = NULL;
    if(*head != NULL){
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp; 
    }
    else{
        *head = temp;
        *tail = temp;
    }
}

void insertend(node **head,node **tail,int value){
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->info = value;
    temp->next = NULL;
    temp->prev = NULL;
    if(*head!=NULL){
        temp->prev = *tail;
        (*tail)->next = temp;
        *tail = temp;
    }
    else{
        *head = temp;
        *tail = temp;
    }
}


void insertafter(node **head,node **tail,int value,int pv){
    node *temp = NULL,*trav = *head;
    temp = (node *)malloc(sizeof(node));
    temp->info = value;
    temp->next = NULL;
    temp->prev = NULL;
    while(trav!=NULL){
        if(trav->info == pv){
            temp->prev = trav;
            temp->next = trav->next;
            if(trav->next==NULL){
                *tail = temp;
            }
            trav->next = temp;
            return; 
        }
        else{
            trav = trav->next;
        } 
    }
    printf("value not found so node can not inserted \n");
    free(temp);
    temp = NULL;
}


void insertbefore(node **head,int value,int s){
    node *temp = NULL,*trav = *head;
    temp = (node *)malloc(sizeof(node));
    temp->info = value;
    temp->next = NULL;
    temp->prev = NULL;
    while(trav!=NULL){
        if(trav->info == s){
            temp->prev = trav->prev;
            temp->next = trav;
            if(trav->prev==NULL){
                trav->prev = temp;
                *head = temp;
                return;
            }
            else{
                trav->prev->next = temp;
                trav->prev = temp;
                return;
            }
        }
        else{
            trav = trav->next;
        }
    }
    printf("Value not found so node can not inserted\n");
    free(temp);
    temp = NULL;
}


void deletebeg(node  **head){
    if(*head!=NULL){
        node *temp = *head;
        *head = (*head)->next;
        if(*head !=NULL)
            (*head)->prev = NULL;
        free(temp);
        temp=NULL;
        return;
    }
    else{
        printf("No node available to delete\n");
        return;
    }
}


void deleteend(node **head,node **tail){
    node *temp = *tail;
    if(temp!=NULL){
        if(temp->prev != NULL){
            *tail = temp->prev;
            (*tail)->next = NULL;  
            free(temp);
            temp = NULL;
            return;
        }
        else{
            free(temp);
            temp = NULL;
            *tail = NULL;
            *head = NULL;
            return;
        }
    }
    else{
        printf("List Already Empty\n");
    }
}



void deleteany(node **head, node**tail,int value){
    node *temp = *head;
    if(*head != NULL){
        while(temp!=NULL){
            if(temp->info == value){
                if(temp->next != NULL && temp->prev != NULL){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                    temp = NULL;
                    return;
                }
                else if(temp->prev == NULL){
                    *head = temp->next;
                    (*head)->prev = NULL;
                    free(temp);
                    temp = NULL;
                    return;
                }
                else if(temp->next == NULL){
                    *tail = temp->prev;
                    (*tail)->next = NULL;
                    free(temp);
                    temp = NULL;
                    return;
                }
            }
            else{
                temp = temp->next;
            }
        }
        printf("Value not found so deletion not posible\n");
        return;
    }
    else{
        printf("List is already empty\n");
    }
}


void traverseLL(node **head){
    node *temp = *head;
    if(temp==NULL){
        printf("Your list is empty\n");
        return;
    }
    printf("Your List is :");
    while(temp!=NULL){
        printf("%d->",temp->info);
        temp = temp->next;
    }
} 


int main(){
    node *head = NULL;
    node *tail = NULL;
    int n,value,s;
    while(1){
        printf("\n\nDoubly Linked List\n\n");
        printf("1-> Insert at Begening\n");
        printf("2-> Insert at End\n");
        printf("3-> Insert After\n");
        printf("4-> Insert Before\n");
        printf("5-> Delete from Begening\n");
        printf("6-> Delete from End\n");
        printf("7-> Delete Perticular Node\n");
        printf("8-> Delete Entire LL\n");
        printf("9-> Traversing\n");
        printf("10-> Reverse Linked List\n");
        printf("11-> Exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&n);
        if(n==11){
            printf("You are out of program now\n");
            return 0;
        }
        switch(n){
            case 1:
                printf("Enter value to be inserted :");
                scanf("%d",&value);
                insertatbeg(&head,&tail,value);
                break;
            case 2:
                printf("Enter value to be inserted :");
                scanf("%d",&value);
                insertend(&head,&tail,value);
                break;
            case 3:
                printf("Enter value to be inserted :");
                scanf("%d",&value);
                printf("Enter position's value :");
                scanf("%d",&s);
                insertafter(&head,&tail,value,s);
                break;
            case 4:
                printf("Enter value to be inserted :");
                scanf("%d",&value);
                printf("Enter position's value :");
                scanf("%d",&s);
                insertbefore(&head,value,s);
                break;
            case 5:
                deletebeg(&head);
                break;
            case 6:
                deleteend(&head,&tail);
                break;
            case 7:
                printf("Enter position's value :");
                scanf("%d",&s);
                deleteany(&head,&tail,s);
                break;
            case 8:
                while(head != NULL){
                    deletebeg(&head);
                }
                printf("List Deleted Successfully\n");
                break;
            case 9:
                traverseLL(&head);
                break;
            case 10:
                printf("done it in sll\n");
                break;
            default:
                printf("Invalid Choice \n");
                break;
        }
    }
}