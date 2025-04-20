#include<stdio.h>

int stack[5];
int top=-1;

void push(int data){
    if(top==4){
        printf("\nStack is full\n");
    }
    else{
        stack[++top]=data;
    }
}

int pop(){
    if(top==-1){
        printf("\nIts empty\n");
        return 0;
    }
    else{
        int deleted=stack[top];
        --top;
        return deleted;
    }
}

void display(){
    if(top==-1){
        printf("\nUnderflow\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}

int main(){
    int data;
    int option;
    char conti;

    here:

    printf("choose one:\n1)Add\n2)Delete\n3)View\n");
    scanf("%d",&option);

    switch(option){
        case 1:
            do{
                printf("Enter data : ");
                scanf("%d",&data);
                push(data);
                printf("want to continue(y/n): ");
                scanf(" %c",&conti);
            }while(conti == 'y');
            break;

        case 2:
            do{
                pop();
                printf("want to continue(y/n): ");
                scanf(" %c",&conti);
            }while(conti == 'y');
            break;

        case 3:
            display();
    }

    printf("\nDoyou want to repeat this program (y/n): ");
    scanf(" %c",&conti);

    if(conti == 'y') goto here;
    
}