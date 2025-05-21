#include<stdio.h>
#include<stdlib.h>

int main(){
    int list[10]={100,20,40,70,10,50,30,80,90,60};
    printf("Before Sorted\n");
    for(int m=0;m<10;m++){
        printf("%d  ",list[m]);
    }
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9-i;j++){
            if(list[j]>list[j+1]){
                int temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
        
    }
    
    printf("\n\nAfter Sorted\n");
    for(int m=0;m<10;m++){
            printf("%d  ",list[m]);
    }
        
    
}
