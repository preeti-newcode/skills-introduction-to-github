#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

void push(int data){
    struct stack *new=(struct stack*)malloc(sizeof(struct stack));

    new->data=data;
    new->next=top;
    top=new;
}

void display(){
    struct stack *list=top;
    if(top==NULL){
        printf("\nits empty\n");
    }
    else{
        printf("\nStack\n");
        while(list != NULL){
            printf("%d\n",list->data);
            list=list->next;
        }
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    display();
    
}