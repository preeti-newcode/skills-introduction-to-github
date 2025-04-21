//deque
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *rear=NULL;
struct node *front=NULL;

void inqueue(int data,int position){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    
    if(rear==NULL){
        rear=front=new;
        rear->next=NULL;
    }
    else if(position==-1){
        new->next=front;
        front=new;
    }
    else{
        rear->next=new;
        new->next=NULL;
        rear=new;
    }
}

void dequeue(int position){
    struct node *del,*pre;
    if(front == NULL){
        printf("\nQueue is empty");
    }
    else if(position == -1){
        del=front;
        while(del->next != rear){
            pre=del;
            del=del->next;
        }
        pre->next=NULL;
        rear=pre;
        printf("\nDeleted Value from Rear side : %d",del->data);
        free(del);
    }
    else{
        del=front;
        front=front->next;
        printf("\nDeleted Value from Front side : %d",del->data);
        free(del);
    }
}

void display(){
    struct node *dis=front;
    while(dis != NULL){
        printf("%d  ",dis->data);
        dis=dis->next;
    }
}

int main(){
    int data,option;
    int position;
    while(1){
        printf("\nChoose : 1)Insert   2)Delete    3)Print    4)Exit\n");
        scanf("%d",&option);
        
        switch(option){
            case 1:
            printf("Enter a data and it's position (-1:Left/1:Right) : ");
            scanf("%d%d",&data,&position);
            inqueue(data,position);
            break;
            
            case 2:
            printf("Enter position (1:Left/-1:Right) : ");
            scanf("%d",&position);
            dequeue(position);
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            exit(1);
        }
    }
    return 0;
}
