#include<stdio.h>
#include<stdlib.h>

#define size 6

int hash[size];

void initial(){
    int x;
    while(x<size){
        hash[x++]=-1;
    }
}

void insert(int data){
    int index,x;
    
    index= data%size;
    
    if(hash[index] != -1){
        while(index<size && hash[index] != -1){
            index++;
        }
        if(index < size){
            hash[index]=data;
        }
        else{
            printf("No space found");
        }
    }
    else{
        hash[index]=data;
    }
    
}

void display(){
    printf("\nDisplaying\n");
    for(int x=0;x<size;x++){
        printf("%d  ",hash[x]);
    }
    printf("\n");
}

int main(){
    int data,option;
    initial();
    
    while(1){
        printf("1)Insert 2)Display 3)End\n");
        scanf("%d",&option);
        
        switch(option){
            case 1:
                printf("Data ");
                scanf("%d",&data);
                insert(data);
                break;
            
            case 2:
                display();
                break;
                
            case 3:
                exit(1);
                
        }
    }
    return 0;
}
