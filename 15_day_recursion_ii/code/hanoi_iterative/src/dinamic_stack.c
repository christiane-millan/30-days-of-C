#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stackd.h"

Node* createStack(){
    return NULL;
}

Node* create_node(int data){
    Node *new_node = (Node *) malloc (sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void destroyStack(Node *top){
    if(!is_empty(top))
        do {
            Node *temp = top->next;
            free(top);
            top = temp;
        } while(top != NULL);
}

void push(Node **top, int item){
    Node *new_node = create_node(item);
    new_node->next = *top;
    *top = new_node;
}

int pop(Node **top){
    if(is_empty(*top))
        return INT_MIN;
    Node *temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);

    return data;
}

int peek(Node *top){
    if(is_empty(top))
        return INT_MIN;
    return top->data;
}

void display(Node *top){
    if(is_empty(top))
        printf("\nLa pila esta vacía, no hay elementos que mostrar");
    else
        do {
            printf("\n%d", top->data);
            top = top->next;
        } while(top != NULL);
}

int is_empty(Node *top){
    return top == NULL;
}