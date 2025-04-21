#include<stdio.h>
#include<stdlib.h>

int queue[10];
int rare=-1;
int front=-1;

void inqueue(){
    if(rare==9){
        int found=-1;
        for(int x=0;x<10;x++){
            if(queue[x] == 0){
                found=x;
                break;
            }
        }
        if(found != -1){
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            queue[found]=data;
        }
        else{
            printf("\nQueue is Full");
        }
    }
    else{
        int data;
        printf("Enter data : ");
        scanf("%d",&data);
        queue[++rare]=data;
        if(front==-1){
            front=0;
        }
        
    }
}

void dequeue(){
    if(front == -1){
        printf("\nQueue is Empty");
    }
    else{
        if(front>9){
            front=0;
        }
        queue[front]=0;
        ++front;
    }
}

void display(){
    printf("\nQueue\n");
    for(int i=0;i<10;i++){
        printf("%d  ",queue[i]);
    }
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
