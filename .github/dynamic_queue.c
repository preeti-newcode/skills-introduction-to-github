#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

struct queue *rear=NULL;
struct queue *front=NULL;

void inqueue(){
    struct queue *cell=(struct queue*)malloc(sizeof(struct queue));
    int data;
    
    printf("\nEnter an element : ");
    scanf("%d",&cell->data);
    
    if(rear==NULL){
        rear=cell;
        front=cell;
    }
    else{
        rear->next=cell;
        rear=cell;
    }
}

void dequeue(){
    if(front==NULL){
        printf("\nQueue is empty");
    }
    else{
        struct queue *deleted=front;
        printf("\nDeleted value : %d",deleted->data);
        front=front->next;
        free(deleted);
    }
}

void display(){
    struct queue *line=front;
    while(line != NULL){
        printf("%d ",line->data);
        line=line->next;
    }
}
int main(){
    int option;
        while(1){
            printf("\nChoose One\n1)Insert    2)Delete    3)Print   4)Exit\n");
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
            }
        }
}
