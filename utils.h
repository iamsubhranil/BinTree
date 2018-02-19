#pragma once

#include <stdbool.h>

typedef struct Node{
    void *data;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *front;
    Node *rear;
} Queue;

typedef struct Stack{
    Node *top;
} Stack;

Queue* queue_new();
void queue_free(Queue *q);
bool queue_isEmpty(Queue *q);
void enque(Queue *q, void *data);
void* deque(Queue *q);

Stack* stack_new();
void stack_free(Stack *s);
bool stack_isEmpty(Stack *s);
void push(Stack *s, void *data);
void* pop(Stack *s);
