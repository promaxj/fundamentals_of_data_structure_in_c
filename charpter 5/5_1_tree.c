#include<stdio.h>
#define MAX_STACK_SIZE 100

typedef struct node *treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
};

void inorder(treePointer ptr) 
{
    if(ptr) {
        inorder(ptr->leftChild);
        printf("%d", ptr->data);
        inorder(ptr->rightChild);
    }
}

void preorder(treePointer ptr)
{
    if(ptr) {
        printf("%d", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr)
{
    if(ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%d", ptr->data);
    }
}

void iterInorder(treePointer node)
{
    int top = -1;
    treePointer stack[MAX_STACK_SIZE];
    for(;;) (
        for(;node ; node = node->leftChild) (
            push(node);
        )
        node = pop();
        if (!node) (
            break;
        )
        printf("%d", node->data);
        node = node->rightChild;
    )
}