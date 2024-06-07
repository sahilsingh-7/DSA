#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
    struct bst *l;
    int info;
    struct bst *r;
}node;

void inserttree(node **root,int val){
    if(*root == NULL){
        node *temp = (node*)malloc(sizeof(node));
        temp->info = val;
        temp->l = NULL;
        temp->r = NULL;
        *root = temp;
    }

    else if(val < (*root)->info){
        inserttree(&((*root)->l),val);
    }

    else inserttree(&((*root)->r),val);
}



void inorder(node *root){
    if(!root) return;
    else{
        inorder(root->l);
        printf("%d ", root->info);
        inorder(root->r);
    }
}
void preorder(node *root){
    if(!root) return;
    else{
        printf("%d ", root->info);
        preorder(root->l);
        preorder(root->r);
    }
}
void postorder(node *root){
    if(!root) return;
    else{
        postorder(root->l);
        postorder(root->r);
        printf("%d ", root->info);
    }
}

int main(){
    node *root = NULL;
    int n,val;
    while(1){
        printf("\n\n1 -> Insert in tree\n");
        printf("2 -> Traverse tree inorder\n");
        printf("3 -> Traverse tree preorder\n");
        printf("4 -> Traverse tree postorder\n");
        printf("5 -> Exit\n\n");
        printf("Enter your choice\n\n");
        scanf("%d",&n);

        switch(n){
            case 1:
                printf("Enter value to be inserted : ");
                scanf("%d",&val);
                inserttree(&root,val);
                break;
            case 2:
                printf("Inorder Traversal of tree is :\n");
                inorder(root);
                break;
            case 3:
                printf("Preorder Traversal of tree is :\n");
                preorder(root);
                break;
            case 4:
                printf("Postorder Traversal of tree is :\n");
                postorder(root);
                break;
            case 5:
                printf("Program ended\n");
                return 0;
        }
    }


}