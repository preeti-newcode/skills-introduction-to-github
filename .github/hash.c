#include <stdio.h>
#include<stdlib.h>

int hash[6];  // global hash table

// Initialize the hash table
void initial() {
    int x = 0;
    while (x < 6) {
        hash[x] = -1;
        x++;
    }
}

// Insert function (hashing using modulo)
void insert(int data) {
    int index;
    index = data % 6;
    if (hash[index] != -1) {
        printf("Already number Exist\n");
    } else {
        hash[index] = data;
    }
}

// Display the hash table
void display() {
    int x = 0;
    printf("\nDisplaying Hash\n");
    while (x < 6) {
        if(hash[x]==-1){
            printf(" NULL ");
        }
        else{
        printf("%d ", hash[x]);
        }
        x++;
        
    }
    printf("\n");
}

// Main function with menu
void main() {
    int data, option;
    initial();      // Initialize hash table
    
    while (1) {
        printf("\n1) Insert\t2) Display\t3) End\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
                display();
                break;

            case 3:
                exit(1);  // Exit the program

            default:
                printf("Invalid Option\n");
        }
    }

}
