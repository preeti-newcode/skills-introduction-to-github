/*
Write a C program to create two linked lists from a given list in the following way: 
INPUT List: 1 2 3 4 5 6 7 8 9 10 
OUTPUT: 
First List: 1 3 5 7 9
Second List: 2 4 6 8 10
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **head,int data){
    struct node *newnode,*odd,*even;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;

    if(*head==NULL){
        newnode->next=NULL;
        *head=newnode;
    }
    else{
        struct node *third=*head;
        while(third->next != NULL){
            third=third->next;
        }
        third->next=newnode;
    }
}


void display(struct node **head){
    struct node *x=*head;
    
    printf("\nLinked List\n");
    while(x != NULL){
        printf("%d ->",x->data);
        x=x->next;
    }
    printf("NULL");
}


int main(){

    struct node *head=NULL, *Evenhead=NULL, *Oddhead=NULL;
    int data;
    char option;

    do{
        printf("Enter a data : ");
        scanf("%d",&data);
        insert(&head,data);

        if(data % 2 == 0){
            insert(&Evenhead,data);
        }
        else{
            insert(&Oddhead,data);
        }

        printf("Want to continue (y/n) :");
        scanf(" %c",&option);
    }while(option=='y');

    display(&head);
    printf("Odd ");
    display(&Oddhead);
    printf("Even ");
    display(&Evenhead);

    return 0;
}