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

void find(int y){
    int data;
    do{
        printf("Guess the number : ");
        scanf("%d",&data);
        if(data == -1){
            printf("You have chosen to quit this game");
            exit(1);
        }
        else if(data == y){
            printf("Congratulation , YOU WON\n");
            display();
            printf("\nWrong guesses : %d",count);
        }
        else{
            printf("\tOH NO!,Try again\n");
            insert(data);
            ++count;
            if(data>y){
                printf("\tGuess lower value\n");
            }
            else{
                printf("\tGuess higher value\n");
            }
        }
    }while(data != y);
}

void cleanup(){
    struct guess *x;
    while(front != NULL){
        x=front;
        front=front->next;
    }
}

int main(){
    
    int y;
    int level;
    printf("Welecome in a Guessing Game\n");

    here:
    printf("Please Choose a level\n");
    printf("\t1)Easy\n\t2)Medium\n\t3)Hard\n");
    scanf("%d",&level);
    switch(level){

        case 1:
            srand(time(NULL));
            y=rand();
            while(y>101){
                y%=101;
            }
            
            printf("Range 0:100\n");
            find(y);
            break;
        
        case 2:
            srand(time(NULL));
            y=rand();
            while(y>1001){
                y%=1001;
            }
            
            printf("Range 0:1000\n");
            find(y);
            break;
            
        case 3:
            srand(time(NULL));
            y=rand();
            while(y>5001){
                y%=5001;
            }
            
            printf("Range 0:5000\n");
            find(y);
    }

    char again;
    printf("\nWant to play again (y/n) : ");
    scanf(" %c",&again);

    cleanup();
    if(again == 'y'){
        goto here;
    }
    return 0;
}
