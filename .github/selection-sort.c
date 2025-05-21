#include<stdio.h>
#include<stdlib.h>

int main(){
    int list[10]={100,20,40,70,10,50,30,80,90,60};
    
    printf("\n\nBefore Sorted\n");
    for(int m=0;m<10;m++){
            printf("%d  ",list[m]);
    }
    printf("\n");
    
    int min;
    for(int i=0;i<9-1;i++){
        min=i;
        for(int j=i+1;j<10;j++){
            if(list[min]>list[j]){
                min=j;
            }
        }
        
        int temp=list[i];
        list[i]=list[min];
        list[min]=temp;
        
        printf("\nDisplay every Step\n");
        for(int m=0;m<10;m++){
            printf("%d  ",list[m]);
        }
        printf("\n");
       
    }
    
    printf("\n\nAfter Sorted\n");
    for(int m=0;m<10;m++){
            printf("%d  ",list[m]);
    }
        
    
}
