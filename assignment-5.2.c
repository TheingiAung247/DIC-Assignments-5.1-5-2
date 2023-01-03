//
// Created by TheinGiAung on 1/1/2023.
// Stack Data Structure

#include "stdio.h"
#include "stdlib.h"
#define MAXOFSTACK 10

struct stack {
    int data[MAXOFSTACK];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *myStack) {
    myStack->top = -1;
}

int isStackEmpty(st *myStack) {
    if(myStack->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isStackFull(st *myStack) {
    if(myStack->top == MAXOFSTACK) {
        return 1;
    } else {
        return 0;
    }
}

void pushToStack(st *myStack, int value) {
    if(isStackFull(myStack)) {
        printf("Stack is full.");
    } else {
        myStack->top++;
        myStack->data[myStack->top] = value;
        printf("Actual data & Position inside the stack: %d at index %d\n", value, myStack->top );
    }
}

void popFromStack(st *myStack) {
    if(isStackEmpty(myStack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Pop from stack data is %d\n", myStack->data[myStack->top]);
        myStack->top--;
    }
}

int main() {
    st *myStack = malloc(sizeof(st));
    createEmptyStack(myStack);
    pushToStack(myStack, 10);
    pushToStack(myStack, 20);
    pushToStack(myStack, 40);
    pushToStack(myStack, 50);
    pushToStack(myStack, 30);
    pushToStack(myStack, 70);

    for(int i = 0; i < MAXOFSTACK; i++) {
        printf("%d stack: ", i);
        popFromStack(myStack);
    }

//    popFromStack(myStack);
//    popFromStack(myStack);
//    popFromStack(myStack);
//    popFromStack(myStack);
//
    return 0;
}