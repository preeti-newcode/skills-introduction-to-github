

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **head, int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;

    if(*head == NULL){
        newnode->next=newnode;
        *head=newnode;
    }
    else{
        struct node *x=*head;
        while(x->next != *head){
            x=x->next;
        }
        x->next = newnode;
        newnode->next = *head;
    }
}

int delete(struct node **head, int data){
    struct node *x=*head;
    int deletedNo;

    do{
        if(x->data == data){
            deletedNo=x->data;

            if(x == *head){
                *head=x->next;
                free(x);
            }
            else{
                struct node *loop=*head;
                while(loop->next != x){
                    loop=loop->next;
                }
                loop->next=x->next;
                free(x);
            }

            return deletedNo;
        }
        x=x->next;
    }
    while(x->data != data && x->next != head);

    printf("\nValue Not Found\n");
    return 0;
}

void display(struct node **head){
    struct node *x=*head;
    
    printf("\nCircular Linked List\n");
    do{
        printf("%d ->",x->data);
        x=x->next;
    }while(x != *head);
}


void main(){

}