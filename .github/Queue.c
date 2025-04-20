#include<stdio.h>
#include<stdlib.h>

int queue[5];

int front=-1;
int rear=-1;

void inqueue(){
    if(rear>3){
        printf("\nQueue is full");
    }
    else{
        int data;
        printf("Enter data : ");
        scanf("%d",&data);
        queue[++rear]=data;
    }
}

void dequeue(){
    if(rear != -1){
        printf("\nDeleted Value : %d",queue[++front]);
        for(int x=0;x<=rear;x++){
            queue[x]=queue[x+1];
        }
        --front;
        --rear;
    }
    else{
        printf("\nQueue is Empty");
    }
}

void display(){
    for(int x=0;x<=rear;x++){
        printf("%d  ",queue[x]);
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
