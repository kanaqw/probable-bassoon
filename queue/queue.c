#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Queue line;
    Item temp;
    char ch;

    queue_Init(&line);
    //code for testing the functions
}

void queue_Init(Queue *pq){
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool queueIsFull(const Queue *pq){
    return pq->items == MAXQUEUE;
}

bool queueIsEmpty(const Queue *pq){
    return pq->items == 0;
}

int queueItemCount(const Queue *pq){
    return pq->items;
}

static void CopyToNode(Item item, Node *pnode);


bool enQueue(Item item, Queue *pq){
    Node* pnew;
    if (queueIsFull(pq))
        return false;
    pnew = (Node*)malloc(sizeof(Node));
    if (pnew == NULL){
        fprintf(stderr, "Cant allocate memory\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (queueIsEmpty(pq))
        pq->front = pnew;
    else
        pq->rear->next = pnew;
    pq->rear = pnew;
    pq->items++; 
}
bool deQueue(Item *pitem, Queue *pq){
    Node *pt;
    if(queueIsEmpty(pq))
        return false;
    copyToItem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;
    return true;
}
void emptyQueue(Queue *pq){
    Item dummy;
    while (!queueIsEmpty(pq))
        deQueue(&dummy, pq);
}

static void CopyToNode(Item item, Node* pnode){
    pnode->item = item;
}

