#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

struct queue *rear=NULL;
struct queue *front=NULL;

void inqueue(){
    int data;
    struct queue *new=(struct queue*)malloc(sizeof(struct queue));
    printf("Enter a data : ");
    scanf("%d",&data);
    new->data=data;
    if(rear==NULL){
        new->next=new;
        rear=front=new;
    }
    else{
        rear->next=new;
        rear=new;
        rear->next=front;
    }
}

void dequeue(){
    if(front==NULL){
        printf("\nQueue is empty");
    }
    else{
        struct queue *del=front;
        
        if(rear==front){
            free(front);
            rear=front=NULL;
        }
        else{
            front=front->next;
            rear->next=front;
        }
        free(del);
    }
}

void display(){
    struct queue *line=front;
    if(line==NULL){
        printf("\nIts Empty");
        return;
    }
    do{
        printf("%d  ",line->data);
        line=line->next;
    }while(line != front);
}

int main(){
    int option;

    while(1){

        printf("\nChoose One\n1)Insert\n2)Delete\n3)Display\n4)Exit\n");
        scanf("%d",&option);
    
        switch(option){
            case 1:
                inqueue();
                break;
    
            case 2:
                dequeue();
                break;
    
            case 3:
                display();
                break;
                
            case 4:
                exit(1);
                break;
                
            default:
                printf("Invalid");
        }
    
    }
    return 0;
}
