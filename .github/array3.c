#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[5];
    int option,index=-1,data,x,found=0;
    
    while(1){
        printf("\n1)Insert    2)Delete    3)Display   4)Exist   5)Linear Search     6)Sorting\n");
        scanf("%d",&option);
        
        switch(option){
            case 1:
                if(index==5){
                    printf("Array is Full\n");
                }
                else{
                    while(index<4){
                        printf("Data ");
                        scanf("%d",&data);
                        arr[++index]=data;
                    }
                    printf("Completed\n");
                }
                break;
            
            case 2:
                if(index==-1){
                    printf("Array is empty\n");
                }
                else{
                    printf("Enter position/index you want to delete : ");
                    scanf("%d",&data);
                    if(data>=5){
                        printf("Index Out of range\n");
                    }
                    else{
                        while(data != 4){
                            arr[data]=arr[data+1];
                            data++;
                        }
                        arr[4]=0;
                        --index;
                        printf("Value deleted\n");
                    }
                }
                break;
                
            case 3:
                printf("\nDisplay\n");
                if(index==-1){
                    printf("No data\n");
                }
                else{
                    for(x=0;x<5;x++){
                        printf("%d  ",arr[x]);
                    }
                }
                break;
                
            case 4:
                exit(0);
                break;
                
            case 5:
                printf("Value you want to search : ");
                scanf("%d",&data);
                
                if(index==-1){
                    printf("Array is EMPTY\n");
                }
                else{
                    for(x=0;x<5;x++){
                        if(arr[x]==data){
                            printf("Data found in %d index\n",x);
                            found=1;
                        }
                    }
                    if(found != 1){
                        printf("Data not found\n");
                    }
                }
                
            case 6:
        }
    }
}
