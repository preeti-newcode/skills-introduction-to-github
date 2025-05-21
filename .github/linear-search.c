#include<stdio.h>
#include<stdlib.h>

//Linear search

int list[10];

int search(int data){
    for(int i=0;i<10;i++){
        if(data==list[i])
            return i;
    }
    return -1;
}


int main(){
    int data;
    
    for(int i=0;i<100;i++){
        list[i]=i+10;
    }
    
    int found=search(19);
    
    if(found==-1){
        printf("Data not found");
    }
    else{
        printf("data found in %dth index",found);
    }
    return 0;
}
