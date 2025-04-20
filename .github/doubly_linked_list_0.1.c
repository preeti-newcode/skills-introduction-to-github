/*Doubly Linked List with insert(),display() and displayReverse()*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *previous;
};

void insert(struct node **head,struct node **tail,int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=value;
    newnode->next=NULL;

    if(*head==NULL){
        *head=newnode;
        *tail=newnode;
        newnode->previous=NULL;
    }
    else{
        (*tail)->next=newnode;
        newnode->previous=*tail;
        *tail=newnode;
    }
}

void display(struct node **head){
    struct node *x=*head;
    printf("\n\nDoubly Linked List\n");
    while(x != NULL){
        printf("%d ",x->data);
        x=x->next;
    }
}

void displayReverse(struct node **tail){
    struct node *x=*tail;
    printf("\n\nDoubly Linked List in Reverse\n");
    while(x != NULL){
        printf("%d ",x->data);
        x=x->previous;
    }
}

int main(){
    struct node *head=NULL,*tail=NULL;
    int data,option;

    do{
        printf("Enter data : ");
        scanf("%d",&data);
        insert(&head,&tail,data);
        printf("Do you want to continue: \n1)Yes\n2)No\n");
        scanf("%d",&option);
    }while(option==1);

    display(&head);
    displayReverse(&tail);
}