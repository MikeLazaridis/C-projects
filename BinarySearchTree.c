#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node *Pointer;
typedef struct Node {
    int data;
    Pointer Left, Right;
}Node;

Pointer createNode(int data){
    Pointer newNode = (Pointer)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data; 
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

void searchNode(Pointer root, Pointer *position, int data){
    Pointer currPtr = root;
    *position = NULL;
    if(root == NULL){
        printf("Binary tree is empty\n");
    }else{
        while(currPtr!=NULL){
            if(currPtr->data == data){
                *position = NULL;
                printf("Data is already in the tree\n");
                break;
            } else if(data < currPtr->data){
                *position = currPtr;
                currPtr = currPtr->Left;
            } else{
                *position = currPtr;
                currPtr = currPtr->Right;
            }
        }
    }
}

void insertNode(Pointer *root, int data){
    Pointer position;
    if(*root == NULL){
        *root = createNode(data);
        return;
    } else{
        searchNode(*root, &position, data);
        if(position != NULL){
            Pointer newNode = createNode(data);
            if(data < position->data){
                position->Left = newNode;
            } else{
                position->Right = newNode;
            }
        }
    }
}

void inOrder(Pointer root){
    if(root != NULL){
        inOrder(root->Left);
        printf("%d ", root->data);
        inOrder(root->Right);
    }
}

void preOrder(Pointer root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->Left);
        preOrder(root->Right);
    }
}

void postOrder(Pointer root){
    if(root != NULL){
        postOrder(root->Left);
        postOrder(root->Right);
        printf("%d ", root->data);
    }
}

int main(){
    Pointer root = NULL;
    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 10);
    insertNode(&root, 20);
    insertNode(&root, 8);
    insertNode(&root, 13);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 9);
    insertNode(&root, 12);
    insertNode(&root, 14);
    postOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    return 0;
}