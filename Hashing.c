//This program implements a hash table using singly linked lists as chaining in C
// It allows insertion, deletion, and searching of items in the hash table.

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node *Pointer;
typedef struct Node{
    int data;
    Pointer next;
}Node;

typedef struct HashTable{
    Pointer table[10];
}HashTable;

int hash(int key){
    return (key % 10);
}

Pointer createNode(int data){
    Pointer new = (Pointer)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

HashTable *newTable(){
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    for(int i = 0; i<10; i++){
        table->table[i] = NULL;
    }
    return table;
}

bool searchItem(HashTable *table, int item){
    Pointer index = NULL;
    bool found = false;
    int i = hash(item);
    index = table->table[i];
    while(index != NULL && found == false){
        if(index->data == item){
            found = true;
        }else{
            index = index->next;
        }
    }
    return found;
}

void insertItem(HashTable *table, int item){
    Pointer position = NULL;
    int index = hash(item);
    if(searchItem(table, item) == false){
        Pointer newNode = createNode(item);
        if(table->table[index] == NULL){
            table->table[index] = newNode;
        }else{
            position = table->table[index];
            while(position->next != NULL){
                position = position->next;
            }
            position->next = newNode;
        }
    }
}

void deleteItem(HashTable *table, int item){
    Pointer prevPtr = NULL;
    int index = hash(item);
    Pointer currPtr = table->table[index];
    while(currPtr != NULL && currPtr->data != item){
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }
    if(currPtr == NULL){
        printf("%d not found\n", item);
    }else{
        if(prevPtr == NULL){
            table->table[index] = currPtr->next;
        }else{
            prevPtr->next = currPtr->next;
        }
        printf("%d deleted\n", item);
        free(currPtr);
    }
}

void traverseTable(HashTable *table){
    for(int i=0; i<10; i++){
        printf("Bucket %d: ", i);
        Pointer index = table->table[i];
        while(index != NULL){
            printf("%d ", index->data);
            index = index->next;
        }
        printf("\n");
    }
}

int generateRandomNumber(){
    return rand() % 501;
}

void fillTable(HashTable *table){
    for(int i=0; i<150; i++){
        int randomNum = generateRandomNumber();
        insertItem(table, randomNum);
    }
}

void deleteRandomItems(HashTable *table){
    srand(time(NULL));
    int numberOfItems = rand() % 31;
    for(int i=0; i<numberOfItems; i++){
        int randomItem = rand() % 501;
        deleteItem(table, randomItem);
    }
}

int main(){
    srand(time(NULL));
    HashTable *table = newTable();
    
    fillTable(table);
    traverseTable(table);
    deleteRandomItems(table);
    traverseTable(table);
    free(table);
    return 0;
}