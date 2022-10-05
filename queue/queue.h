#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

#define MAXQUEUE 10
typedef int Item;

typedef struct node{
    Item item;
    struct node*next;
} Node;

typedef struct queue{
    Node* front;
    Node* rear;
    int items;
} Queue;

void queue_Init(Queue *pq);
bool queueIsFull(const Queue *pq);
bool queueIsEmpty(const Queue *pq);
int queueItemCount(const Queue *pq);
bool enQueue(Item item, Queue *pq);
bool deQueue(Item *pitem, Queue *pq);
void emptyQueue(Queue *pq);



#endif
