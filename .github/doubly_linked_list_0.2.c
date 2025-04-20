/*Doubly Linked List with insert(),join(),delete(),display() and displayReverse()*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *previous;
};

void insert(struct node **head,struct node **tail,int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=value;
    newnode->next=NULL;

    if(*head==NULL){
        *head=newnode;
        *tail=newnode;
        newnode->previous=NULL;
    }
    else{
        (*tail)->next=newnode;
        newnode->previous=*tail;
        *tail=newnode;
    }
}

void join(struct node **head, struct node **tail,int value, int place){
    struct node *new, *x=*head, *y=NULL;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;

    if (place == 0) {
        new->previous = NULL;
        new->next = *head;
    
        if (*head != NULL)
            (*head)->previous = new;
        else
            *tail = new;
    
        *head = new;
    }
    else{
        int count=0;
        while(x != NULL && count<place){
            count++;
            y=x;
            x=x->next;
        }

        if(x == NULL || count != place){
            printf("\nValue out of range\n");
        }
        else if(y->next==NULL){
            new->next=NULL;
            new->previous=y;
            y->next=new;
            *tail=new;
            //x->previous=new;
        }
        else{
            new->next=y->next;
            new->previous=y;
            y->next=new;
            x->previous=new;

        }
    }
}

int delete(struct node **head, struct node **tail, int value){
    struct node *x=*head,*y=*head;
    int deletedValue;

    while(x != NULL && x->data != value){
        x=x->next;
    }

    if(x->data != value){
        printf("Data not found");
        return 0;
    }
    else{
        deletedValue=x->data;

        if(x->next == NULL){
            *tail=x->previous;
            x->previous->next=NULL;
            free(x);
            return deletedValue;
        }
        else if(x->previous == NULL){
            *head=x->next;
            x->next->previous=NULL;
            free(x);
            return deletedValue;

        }
        else{
            x->previous->next=x->next;
            x->next->previous=x->previous;
            free(x);
            return deletedValue;
        }
    }
}
    

void display(struct node **head){
    struct node *x=*head;
    printf("\n\nDoubly Linked List\n");
    while(x != NULL){
        printf("%d ",x->data);
        x=x->next;
    }
}

void displayReverse(struct node **tail){
    struct node *x=*tail;
    printf("\n\nDoubly Linked List in Reverse\n");
    while(x != NULL){
        printf("%d ",x->data);
        x=x->previous;
    }
}

int main(){
    struct node *head=NULL,*tail=NULL;
    int data,option,place;

    here:

    printf("\nChoose any one\n1)Add data\n2)Insert data\n3)Delete\n4)Display\n5)Display in Reverse Order\n");
    scanf("%d",&option);

    switch(option){

        case 1:    
            do{
                printf("\nEnter data : ");
                scanf("%d",&data);
                insert(&head,&tail,data);
                printf("Do you want to continue: \n1)Yes\n2)No\n");
                scanf("%d",&option);
            }while(option==1);
            
            display(&head);
            break;
        
        case 2:
            do{
                printf("\n\nEnter data and it's position : ");
                scanf("%d%d",&data,&place);
                join(&head,&tail,data,place);
                printf("Do you want to continue: \n1)Yes\n2)No\n");
                scanf("%d",&option);
            }while(option==1);

            display(&head);
            break;

        case 3:
            do{
                int deleted;
                printf("\n\nEnter value to delete: ");
                scanf("%d", &data);
                deleted = delete(&head, &tail, data);
                if(deleted){
                    printf("Deleted: %d\n", deleted);
                }
                printf("Do you want to continue: \n1)Yes\n2)No\n");
                scanf("%d",&option);
            }while(option == 1);

            display(&head);
            break;

        case 4:
            display(&head);
            break;

        case 5:
            displayReverse(&tail);
            break;

        default:
            printf("\nYou have entered wrong option");

    }

    printf("\nDo you want to choose any more option\n1)Yes\n2)No\n");
    scanf("%d",&option);

    if(option==1){
        goto here;
    }
}