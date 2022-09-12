#ifndef STACKD_H
# define STACKD_H

typedef struct node Node;

struct node{
    int data;
    struct node  *next;
};

Node* createStack();
Node* create_node(int data);
void destroyStack(Node *top);
void push(Node **top, int item);
int pop(Node **top);
int peek(Node *top);
void display(Node *top);

int is_empty(Node *top);

#endif