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

void traverse(){
    if(place==-1){
        printf("\nIts Empty");
    }else{
        for(int x=0;x<=place;x++){
            printf("\n%d  ",array[x]);
        }
    }
}

void reverse(){
    int reArr[place];
    printf("\nReverse Array");
    for(int x=0,y=place;x<=place;x++,y--){
        reArr[x]=array[y];
        printf("\n%d    ",reArr[x]);
    }
}

void merge(int arr[],int size,int arr2[],int size2){
    int new[size+size2];

    for(int x=0;x<size;x++){
        new[x]=arr[x];
    }
    for(int x=0;x<size2;x++){
        new[size+x]=arr2[x];
    }

    printf("\nMerged Array\n");
    for(int x=0;x<size+size2;x++){
        printf("%d  ",new[x]);
    }
}

int main(){
    int data,choice;
    char option;

    do{
        printf("Choose one\n1)Insert\n2)Delete\n3)Print\n4)Reverse\n5)Merge\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            do{
                printf("Enter data : ");
                scanf("%d",&data);
                insert(data);
                printf("Continue (y/n) :");
                scanf(" %c",&option);
            }while(option=='y');
            break;

            case 2:
                printf("Enter data : ");
                scanf("%d",&data);
                delete(data);
            break;

            case 3:
                traverse();
            break;

            case 4:
                reverse();
            break;

            case 5:
                int arr[3];
                printf("\nEnter data for second array of size 3\n");
                scanf("%d%d%d",&arr[0],&arr[1],&arr[2]);

                merge(array,place+1,arr,3);
            
        }

        printf("\nReplay program? (y/n): ");
        scanf(" %c",&option);
    }while(option=='y');

    return 0;

}
