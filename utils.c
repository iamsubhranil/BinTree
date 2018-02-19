#include <stdlib.h>
#include "utils.h"

static Node* node_new(void *data){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

static void node_free(Node *n){
    while(n != NULL){
        Node *bak = n->next;
        free(n);
        n = bak;
    }
}

Queue* queue_new(){
    Queue* q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void queue_free(Queue *q){
    node_free(q->front);
    free(q);
}

bool queue_isEmpty(Queue *q){
    return q->front == NULL;
}

void enque(Queue *q, void *data){
    Node *n = node_new(data);
    if(q->front == NULL){
        q->front = q->rear = n;
    }
    else{
        q->rear->next = n;
        q->rear = n;
    }
}

void* deque(Queue *q){
    if(q->front == NULL)
        return NULL;
    Node *bak = q->front;
    void *data = bak->data;
    q->front = bak->next;
    if(q->front == NULL)
        q->rear = NULL;
    free(bak);
    return data;
}

Stack* stack_new(){
    Stack* s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void stack_free(Stack *s){
    node_free(s->top);
    free(s);
}

bool stack_isEmpty(Stack *s){
    return s->top == NULL;
}

void push(Stack *s, void *data){
    Node *n = node_new(data);
    n->next = s->top;
    s->top = n;
}

void* pop(Stack *s){
    Node *bak = s->top;
    void* d = bak->data;
    s->top = bak->next;
    free(bak);
    return d;
}
