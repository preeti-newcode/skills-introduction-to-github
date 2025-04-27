#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

void insert(int data){
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    
    if(root == NULL){
        root=new;
    }
    else{
        struct node* parent;
        struct node* temp=root;
        while(temp != NULL){
            if(data < temp->data){
                parent=temp;
                temp=temp->left;
            }
            else {
                parent=temp;
                temp=temp->right;
                
            }
        }
        
        if(parent->data > data) parent->left=new;
        else parent->right=new;    
        
    }
}

void display(){
    if(root == NULL) printf("\nIts empty");
    else{
        preorder(root);
    }
}

void preorder(struct node* x){
    if(x != NULL){
        printf("%d ",x->data);
        preorder(x->left);
        preorder(x->right);
    }
}

int main(){
    int data,option;
    
    while(1){
        printf("Choose : ");
        scanf("%d",&option);
        switch(option){
            case 1:
            printf("Enter : ");
            scanf("%d",&data);
            insert(data);
            break;
            
            case 2:
            display();
            printf("\n");
            break;
            
            default:
            exit(1);
        }
    }
}
