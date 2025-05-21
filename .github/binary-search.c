#include<stdio.h>
#include<stdlib.h>

//Binary Search
int list[10];

int search(int data){
    int right,left,mid;
    left=0;
    right=9;
    
    while(left<=right){
        mid=(left+right)/2;
        if(list[mid]==data){
            return mid;
        }
        else if(data>list[mid]) left=mid+1;
        
        else right=mid-1;
        
    }
    return -1;
}


int main(){
    int data;
    
    for(int i=0;i<10;i++){
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
