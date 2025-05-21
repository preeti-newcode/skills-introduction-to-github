#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *head=NULL;
struct node *tail=NULL;

void insert(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        newNode->next=head;
        tail=newNode;
    }
}

void selection(){
    struct node *i,*j,*min;
    int temp;
    printf("\n Selection Sort\n");
    i=head;
    do{
        min=i;
        j=i->next;
        while(j != head){
            if(j->data < min->data){
                min=j;
            }
            j=j->next;
        }
        temp=i->data;
        i->data=min->data;
        min->data=temp;
        
        i=i->next;
    }while(i != head);

    
    struct node* sorted=head;
    do{
        printf("%d ->",sorted->data);
        sorted=sorted->next;
    }while(sorted != head);
    printf("NULL");
}

void display(){
    struct node* x=head;
    printf("Circular Linked List\n");
    do{
        printf("%d ->",x->data);
        x=x->next;
    }while(x != head);
    printf("NULL");
}

int main(){
    while(1){
        int value;
        printf("Data :");
        scanf("%d",&value);
        if(value == -1){
            break;
        }
        else{
            insert(value);
        }
    }
    display();
    selection();
    
}
