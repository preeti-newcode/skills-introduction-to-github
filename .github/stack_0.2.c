#include<stdio.h>
#include<stdlib.h>

int main(){
    int stack[5];
    int data,top=-1;
    
    printf("\nStack\n");
    if(top==4){
        printf("Its full\n");
    }
    else{
        while(top != 4){
            printf("Data : ");
            scanf("%d",&data);
            ++top;
            stack[top]=data;
        }
    }
    
    printf("\nDisplay\n");
    for(int x=0;x<5;x++){
        printf("%d\n",stack[x]);
    }
    
    printf("\nPop\n");
    if(top==-1){
        printf("List is empty\n");
    }
    else{
        while(top>=0){
            printf("\nDeleted value : %d",stack[top]);
            top=top-1;
        }
    }
}