#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;


//Insert
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

//Display and its order
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);

void display(int info){
    if(root == NULL){
        printf("\nTree is empty\n");
    }
    else if(info==1){
        preorder(root);
    }
    else if(info ==2){
        inorder(root);
    }
    else{
        postorder(root);
    }
}

void preorder(struct node* x){
    if(x != NULL){
        printf("%d ",x->data);
        preorder(x->left);
        preorder(x->right);
    }
}

void inorder(struct node* x){
    if(x != NULL){
        inorder(x->left);
        printf("%d ",x->data);
        inorder(x->right);
    }
}

void postorder(struct node* x){
    if(x != NULL){
        postorder(x->left);
        postorder(x->right);
        printf("%d ",x->data);
    }
}

//search function
void search(int data){
    int found=0;
    if(root == NULL){
        printf("\nTree is Empty");
    }
    else{
        struct node* x=root;
        while(x != NULL && x->data != data){
            if(data < x->data){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        if(x != NULL && x->data == data){
            printf("\nNumber found");
        }
        else{
            printf("\nNumber not found");
        }
    }
}



//main body
int main(){
    int data,option;
    
    while(1){
        printf("\n1)insert    2)Display   3)search\n");
        printf("Choose : ");
        scanf("%d",&option);
        switch(option){
            case 1:
            printf("Enter : ");
            scanf("%d",&data);
            insert(data);
            break;
            
            case 2:
            int x;
            printf("1)preorder  2)inorder   3)postorder\n");
            scanf("%d",&x);
            display(x);
            break;
            
            case 3:
            printf("\nData to search : ");
            scanf("%d",&data);
            search(data);
            break;
            
            default:
            exit(1);
        }
    }
}
