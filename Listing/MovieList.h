#ifndef MOVIELIST_H_
#define MOVIELIST_H_

#include <stdbool.h>
#include <string.h>

#define TSIZE   45

struct film {
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node{
    Item item;
    struct node *next;
} Node;

typedef Node* List;

//Functions prototypes


#endif
