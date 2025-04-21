#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
    struct node *next;
};

struct node *rear=NULL;
struct node *front=NULL;

void inqueue(int data,int prio){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->priority=prio;
    
    if(rear==NULL){
            new->next=NULL;
            rear=front=new;
    }
    else{
        rear->next=new;
        rear=new;
    }
}

void dequeue(){
    if(front==NULL){
        printf("\nQueue is Empty");
    }
    else{
        if(rear==front){
            printf("\nDeleted Value : %d",front->data);
            free(front);
            rear=front=NULL;
        }
        else{
            
            struct node *com=front;
            struct node *max=front;
            struct node *pre=NULL;
            struct node *preMax=NULL;
            while(com != NULL){
                if(com->priority>max->priority){
                    max=com;
                    preMax=pre;
                }
                pre=com;
                com=com->next;
            }
            printf("\nDeleted Value : %d",max->data);
            if(max==front){
                front=front->next;
            }else{
                preMax->next=max->next;
            }
            
            if(max==rear){
                rear=preMax;
            }
            free(max);
        }
    }
}

void display(){
    struct node *line=front;
    if(front != NULL){
        printf("\npriority linked list queue\n");
        while(line != NULL){
            printf("%d  ",line->data);
            line=line->next;
        }
    }
    else{
        printf("\nIts empty");
    }
}

int main(){
    int data,option;
    int prior;
    while(1){
        printf("\nChoose : 1)Insert   2)Delete    3)Print    4)Exit\n");
        scanf("%d",&option);
        
        switch(option){
            case 1:
            printf("Enter a data and it's value according to importance : ");
            scanf("%d%d",&data,&prior);
            inqueue(data,prior);
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
