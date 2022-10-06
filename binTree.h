#ifndef _BINTREE_H_
#define _BINTREE_H_

#include <stdbool.h>

typedef struct item{
    char petname[20];
    char petkind[20];
} Item;

#define MAXITEMS    10

typedef struct trnode{
    Item item;
    struct trnode *left; 
    struct trnode *right;
} Trnode;

typedef struct tree{
    Trnode *root;
    int size;
} Tree;

void tree_Init(Tree *ptree);
bool treeIsEmpty(const Tree *ptree);
bool treeIsFull(const Tree *ptree);
int treeItemCount(const Tree *ptree);
bool addItem(const Item *pi, Tree *ptree);
bool inTree(const Item*pi, const Tree *ptree);
bool deleteItem(const Item *pi, Tree *ptree);
void traverse(const Tree *ptree, void (*pfun)(Item item));
void deleteAll(Tree *ptree);


#endif