#include<stdio.h>
#include<stdlib.h>

int queue[3];
int front=-1;
int rear=-1;

void insert(int data){
    if(rear == -1 && front == -1){
        queue[++rear]=data;
        ++front;
    }
    else if(rear==2){
        rear=-1;
        queue[++rear]=data;
        ++front;
    }
    else{
        queue[++rear]=data;
    }
}

void display(){
    int step=front;
    while(step != 3){
    printf("%d  ",queue[step]);
    ++step;
    }
    if(front != 0){
        step=0;
        while(step <= rear){
            printf("%d  ",queue[step]);
            ++step;
        }
    }
}


int math(int first, int second, char sign){
    switch(sign){
        case '+':
            return first+second;
        case '-':
            return first-second;
        case '*':
            return first*second;
        case '/':
            return first/second;
        case '%':
            return first%second;
        default:
            printf("\nSomethings Wrong");
    }
}

int main(){
    int val1,val2;
    char sign,option;
    printf("\nCALCULATOR");
    printf("\nEnter 1st Number : ");
    scanf("%d",&val1);
    here:
    printf("Enter 2nd Number : ");
    scanf("%d",&val2);
    printf("\nChoose : \n\t+ Addition           - Substraction\n\t* Multiplication     / Division\n\t%% Remainder\nChoice :");
    scanf(" %c",&sign);
    int result=math(val1,val2,sign);
    printf("\n%d",result);
    insert(result);
    
    printf("\nContinue(y/n)? : ");
    scanf(" %c",&option);
    if(option == 'y'){
        val1= result;
        goto here;
    }
    else{
        printf("\nStored Solution\n");
        display();
    }
}
