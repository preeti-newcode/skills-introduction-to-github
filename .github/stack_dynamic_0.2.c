#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

void push(int data){
    struct stack *cell=(struct stack*)malloc(sizeof(struct stack));

    cell->data=data;
    cell->next=top;
    top=cell;
}

void display(){
    struct stack *tem=top;
    if(top==NULL){
        printf("\nStack is emoty\n");
    }
    else{
        printf("\nStack List\n");
        while(tem != NULL){
            printf("%d\n",tem->data);
            tem=tem->next;
        }
    }
}

int pop(){
    if(top == NULL){
        printf("List is empty\n");
        return 0;
    }
    else{
        struct stack *x=top;
        top=top->next;
        int deletedNo=x->data;
        free(x);
        return deletedNo;
    }
}

int main(){
    int data;
    int option;

    here:

    printf("\nChoose One\n1)Push\n2)Pop\n3)Display\n");
    scanf("%d",&option);

    switch(option){
        case 1:
            printf("\nEnter data : ");
            scanf("%d",&data);
            push(data);
            break;

        case 2:
            printf("Deleted No : %d\n ",pop());
            break;

        case 3:
            display();
    }
    printf("Want to continue\n1)Yes\n2)No\n");
    scanf("%d",&option);

    if(option==1){
        goto here;
    }
}