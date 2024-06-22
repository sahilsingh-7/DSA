#include<iostream>
using namespace std;

class Node{
    public:
    int info;
    int h;
    Node *l;
    Node *r;
    Node(int data){
        info = data;
        h = 1;
        l = r = NULL;
    }
};

int getHeight(Node *root){
    if(!root) return 0;

    return root->h;
}

int getBalance(Node *root){
    return getHeight(root->l) - getHeight(root->r);
}

Node* rightRotate(Node *root){
    Node *child = root->l;
    Node *childR = child->r;
    child->r = root;
    root->l = childR;
    root->h = 1 + max(getHeight(root->l),getHeight(root->r));
    child->h = 1 + max(getHeight(child->l),getHeight(child->r));
    return child;
}

Node* leftRotate(Node *root){
    Node *child = root->r;
    Node *childL = child->l;
    child->l = root;
    root->r = childL;
    root->h = 1 + max(getHeight(root->l),getHeight(root->r));
    child->h = 1 + max(getHeight(child->l),getHeight(child->r));
    return child;
}

Node* insertAVL(Node *root,int val) {
    if(!root) 
    return new Node(val);

    // existing 
    if(root->info < val) root->r = insertAVL(root->r,val);
    if(root->info > val) root->l = insertAVL(root->l,val);


    root->h = 1+max(getHeight(root->l),getHeight(root->r));
    int bf = getBalance(root);

    // LL unbalancing
    if(bf>1 && root->l->info > val) return rightRotate(root);
    // RR unbalancing 
    else if(bf < -1 && root->r->info < val) return leftRotate(root);
    // LR unbalancing 
    else if(bf >1 && root->l->info < val) {
        root->l = leftRotate(root->l);
        return rightRotate(root);
    }
    // RL unbalancing 
    else if(bf<-1 && root->r->info > val){
        root->r = rightRotate(root->r);
        return leftRotate(root);
    }
    // Already balanced
    return root;
}

void preorder(Node *root){
    if(!root) return;
    cout<<root->info;
    preorder(root->l);
    preorder(root->r);
}

int main(){
    int c,val;
    Node *root = NULL;
    while(1){
        cout<<endl<<"1-> Insert Data"<<endl;
        cout<<"2-> preorder"<<endl;
        cout<<"3-> Exit"<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>c;

        switch (c)
        {
        case 1:
            cout<<"Enter data : ";
            cin>>val;
            root = insertAVL(root,val);
            break;
        case 2:
            preorder(root);
            break;
        case 3: 
            return 0;
        
        default:
            break;
        }

    }
}