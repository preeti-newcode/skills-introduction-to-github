/* Circular Linked List with insert and display ()*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **head, int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;

    if(*head == NULL){
        *head=newnode;
        newnode->next=newnode;
    }
    else{
        struct node* x=*head;
        while(x->next != *head){
           x=x->next; 
        }
        x->next=newnode;
        newnode->next=*head;
    }
}

void display(struct node **head){
    struct node *x=*head;

    printf("\nCircular Linked List\n");

    if(x == NULL){
        printf("List is empty");
    }
    
    do{
        printf("%d -> ",x->data);
        x=x->next;
    }while(x != *head);

    printf(".....");
}

int main(){
    struct node *head=NULL;
    int  data=0;
    char option;

    do{
        printf("Enter a data : ");
        scanf("%d",&data);
        insert(&head,data);
        printf("Do you want to continue(y/n) : ");
        scanf(" %c",&option); //scanf has in-built new line ,so space tells scanf to ignore any whitespace characters or use \n
    }while(option=='y');

    display(&head);
    return 0;
    
}