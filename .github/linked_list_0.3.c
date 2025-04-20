/*Singly Linked list with insert(),join() to place data anywhere you want,delete(),dislpay() 
and these all will continue in loop unless and until user want to end it*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert(struct node** head,int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;

    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node *x=*head;
        while(x->next != NULL){
            x=x->next;
        }
        x->next=newnode;
    }
}

void display(struct node**head){
    struct node* x=*head;
    printf("\nLinked List\n");
    while(x != NULL){
        printf("%d ",x->data);
        x=x->next;
    }
}

void join(struct node**head,int value,int place){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=value;
    if(place==0){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        int count=0;
        struct node* x=*head;
        while(x != NULL && count<place-1){
            count++;
            x=x->next;
        }

        if(x == NULL){
            printf("OUT OF RANGE");
            free(newnode);
        }
        else{
            newnode->next=x->next;
            x->next=newnode;
        }
    }
}

int delete(struct node** head,int value){
    struct node* temp=*head;
    struct node* previous=NULL;
    int deleted;
    while(temp != NULL && temp->data != value){
        previous=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Linked List is empty");
        return -1;
    }
    else{
        deleted=temp->data;
        if(previous == NULL){
            *head=temp->next;
        }
        else{
            previous->next=temp->next;
        }
    }
    free(temp);
    return  deleted;
}

int main(){
    struct node*head=NULL;
    int option;
    char conti;
    int data;

    here:

    printf("Choose any one\n1)Add data\n2)Insert data\n3)Delete\n4)Display\n");
    scanf("%d",&option);

    switch(option){
        case 1:
        do{
            printf("Enter an element : ");
            scanf("%d",&data);
            insert(&head,data);
            printf("\nDo you want to continue : ");
            scanf("\n%c",&conti);
        }while(conti=='y');
        break;

        case 2:
        int position;
        do{
            printf("Enter an element and its position\n ");
            scanf("%d%d",&data,&position);
            join(&head,data,position);
            printf("\nDo you want to continue : ");
            scanf("\n%c",&conti);
        }while(conti=='y');
        break;

        case 3: 
        do{
            printf("Enter an element to be deleted : ");
            scanf("%d",&data);
            printf("\nList before deletion\n\n");
            printf("Deleted no : %d",delete(&head,data));
            printf("\n\nList after deletion\n\n");
            printf("\nDo you want to continue : ");
            scanf("\n%c",&conti);
        }while(conti=='y');
        break;

        case 4:
        display(&head);
        break;

    }

    printf("\nDo you want to continue this program\n1)yes\n2)no\n");
    scanf("%d",&option);

    if(option==1){
        goto here;
    }


    return 0;
}