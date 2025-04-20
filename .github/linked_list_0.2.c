/*Creating linked list with insert and display function and inserting data in the middle of linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *address;
};

void insert(struct node **head,int value){
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));

    new->data=value;
    new->address=NULL;

    if(*head==NULL){
        *head=new;
    }
    else{
        struct node *x=*head;
        while(x->address != NULL){
            x=x->address;
        }
        x->address=new;
    }
}

void display(struct node **head){
    struct node* x=*head;
    printf("\nLinked List\n");
    while(x != NULL){
        printf("%d ",x->data);
        x=x->address;
    }
}

void join(struct node **head,int value,int place){
    struct node *x=*head,*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    int count=0;

    if(place==0){
        new->address=x;
        *head=new;
    }
    else{
        while(x != NULL && count<place-1){
            count++;
            x=x->address;
        }

        if(x == NULL){
            printf("Out of range");
            free(new);
        }
        else{
            new->address=x->address;
            x->address=new;
        }
    }
}

int main(){
    struct node *head=NULL;
    int data,position;
    char option;

    do{
        printf("Enter a data : ");
        scanf("%d",&data);
        insert(&head,data);
        printf("Do you want to continue(y/n) : ");
        scanf(" %c",&option); //scanf has in-built new line ,so space tells scanf to ignore any whitespace characters or use \n
    }while(option=='y');

    display(&head);
    
    do{
        printf("\nDo you want to insert in middle :");
        scanf("\n%c",&option);
        if(option=='y'){
            printf("Data and its position (start with 0)\n");
            scanf(" %d%d",&data,&position);
            join(&head,data,position);
        }
    }while(option=='y');

    display(&head);
}