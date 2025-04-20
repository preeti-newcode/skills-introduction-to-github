/*WAP to implement the following operations on a one-dimensional array: 
(i) Insertion 
(ii) Deletion 
(iii) Traversal 
(iv) Reverse 
(v) Merge*/

#include<stdio.h>

int array[5];
int place=-1;

void insert(int data){
    if(place==4){
        printf("\nArray is full");
    }
    else{
        array[++place]=data;
    }
}

void delete(int data){
    if(place==-1){
        printf("\nArray is empty");
    }
    else{
        for(int s=0;s<=place;s++){
            if(array[s]==data){
                printf("\nDelected element %d was at %dth position",data,s);
                if(s==place){
                    array[s]=0;
                }
                else{
                    while(s <= place){
                        array[s]=array[s+1];
                        ++s;
                    }
                }
                --place;
                break;
            }
        }
    }
}

int main(){

}