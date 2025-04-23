#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct guess{
    int data;
    struct guess *next;
};

struct guess *front=NULL;
struct guess *rear=NULL;
int count=0;

void insert(int data){
    struct guess *new=(struct guess*)malloc(sizeof(struct guess));
    new->data=data;
    new->next=NULL;
    if(front==NULL){
        rear=new;
        front=new;
    }
    else{
        rear->next=new;
        rear=new;
    }
}

void display(){
    struct guess *line=front;
    
    if(line==NULL){
        printf("\n\tYou guessed in Single Try\n\tBig Congratulation (^o^)\n");
    }
    else{
        printf("\nAll your guessed number\n");
        while(line != NULL){
            printf("%d\t",line->data);
            line=line->next;
        }
    }
}

int main(){
    srand(time(NULL));
    int data;
    int y=rand();
    while(y>101){
        y%=101;
    }
    printf("%d\n",y);
    do{
        printf("Guess the number : ");
        scanf("%d",&data);
        if(data == y){
            printf("Congratulation , YOU WON\n");
            display();
            printf("\nWrong guesses : %d",count);
        }
        else{
            printf("OH NO!,Try again\n");
            insert(data);
            ++count;
        }
    }while(data != y);
    //printf("%d\n",time());
    
    return 0;
}
