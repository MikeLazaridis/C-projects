#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node *Pointer;
typedef struct Node{
    int data;
    Pointer next;
}Node;

Pointer newNode(int data){
    Pointer new = (Pointer)malloc(sizeof(Node));
    if(new == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->data = data;
    new->next = NULL;
    return new;
}

bool isEmpty(Pointer root){
    return root == NULL;
}

bool exists(Pointer node, int data){
    if(node == NULL) 
        return false;
    return node->data == data;
}

void insertNode(Pointer *root, int data){
    Pointer new = newNode(data);
    Pointer currPtr = *root;
    Pointer prevPtr = NULL;
    if(isEmpty(*root)){
        *root = new;
        return;
    }
    while(currPtr != NULL){
        if(exists(currPtr, data)){
            printf("Data already exists\n");
            free(new);
            break;
        }
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }
    prevPtr->next = new;
}

void deleteNode(Pointer *root, int data){
    Pointer currPtr = *root;
    Pointer prevPtr = NULL;
    if(isEmpty(*root)){
        printf("List is empty\n");
        return;
    }
    while(currPtr != NULL && currPtr->data != data){
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }
    if (currPtr == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }
    if (prevPtr == NULL) {
        *root = currPtr->next;
    } else {
        prevPtr->next = currPtr->next;
    }
    free(currPtr);
}


void traverseList(Pointer root){
    Pointer currPtr = root;
    while(currPtr != NULL){
        printf("%d ", currPtr->data);
        currPtr = currPtr->next;
    }
}

int main(){
    Pointer root = NULL;
    Pointer position = NULL;
    insertNode(&root, 5);
    insertNode(&root, 10);
    insertNode(&root, 7);
    insertNode(&root, 3);
    insertNode(&root, 1);
    insertNode(&root, 9);
    insertNode(&root, 8);
    insertNode(&root, 6);
    insertNode(&root, 4);
    insertNode(&root, 2);
    traverseList(root);
    printf("\n");
    deleteNode(&root, 5);
    deleteNode(&root, 8);
    deleteNode(&root, 2);
    traverseList(root);
    return 0;
}