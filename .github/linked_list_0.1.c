/*Creating linked list with insert*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* address;
};

void insert(int **head,int value){
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=value;
    newnode->address=NULL;

    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node *temp=*head;
        while(temp->address!=NULL){
            temp=temp->address;
        }
        temp->address=newnode;
    }
}

void main(){
    struct node *head=NULL;
    char option;
    int data;

    do{
        printf("Enter a data : ");
        scanf("%d",&data);
        insert(&head,data);
        printf("Do you want to continue(y/n) : ");
        scanf(" %c",&option); //scanf has in-built new line ,so space tells scanf to ignore any whitespace characters or use \n
    }while(option=='y');

    while(head != NULL){
        printf("%d ",head->data);
        head=head->address;
    }
    
    return 0;
}