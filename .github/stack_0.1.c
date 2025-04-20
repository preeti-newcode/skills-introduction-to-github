#include<stdio.h>

int stack[5];
int top=-1;

void push(int data){
    if(top==4){
        printf("Stack is full");
    }
    else{
        top=top+1;
        stack[top]=data;
        //printf("\nIts Done");
    }
}

int pop(){
    
    if(top==-1){
        printf("\nStack is empty");
        return 0;
    }
    else{
        int deletedNo=stack[top];
        --top;
        return deletedNo;
    }
}

void display(){
    if(top==-1){
        printf("\nIts Empty");
    }
    else{
        printf("\nStack\n");
        for(int x=0;x<=top;x++){
            printf("%d\n",stack[x]);
        }
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    printf("deleted value %d",pop());
    display();
}
