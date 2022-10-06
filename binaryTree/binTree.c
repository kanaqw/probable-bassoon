#include "binTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct pair{
    Trnode *parent;
    Trnode *child;
} Pair;

static Trnode *makeNode(const Item *pi){
    Trnode *new_node;
    new_node = (Trnode*)malloc(sizeof(Trnode));
    if (new_node != NULL){
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static bool ToLeft(const Item *i1, const Item *i2){
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname))<0)
        return true;
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind)<0)
            return true;
    else 
        return false;
}

static bool ToRight(const Item *i1, const Item *i2){
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname))<0)
        return true;
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind)<0)
            return true;
    else 
        return false;
}

static Pair seekItem(const Item *pi, const Tree *ptree){
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    if (look.child == NULL)
        return look;
    while (look.child != NULL){
        if (ToLeft(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->right;
        } else 
        break; //same element
    }
    return look;
}

static void deleteNode(Trnode **ptr){
    Trnode *temp;
    if ((*ptr)->left == NULL){
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL){
        temp = *ptr;
        *ptr - (*ptr)->left;
        free(temp);
    } else {
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

bool deleteItem(const Item *pi, Tree *ptree){
    Pair look;
    look = seekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    if (look.parent == NULL)
        deleteNode(&ptree->root);
    else if (look.parent->left ==look.child)
        deleteNode(&look.parent->left);
    else 
        deleteNode(&look.parent->right);
    ptree->size--;
    return true;
}

bool inTree(const Item *pi ,const Tree *ptree){
    return (seekItem(pi, ptree).child == NULL) ? false : true; 
}

static void addNode(Trnode *new_node, Trnode *root){
    if (ToLeft(&new_node->item, &root->item)){
        if (root->left == NULL)
            root->left = new_node;
        else 
            addNode(new_node, root->left);
    }
    else if (ToRight(&new_node->item, &root->item)){
        if (root->right == NULL)
            root->right = new_node;
        else 
            AddNode(new_node, root->right);
    }
    else {
        fprintf(stderr, "Error placing AddNode\n");
        exit(1);
    }
}

void tree_Init(Tree *ptree);
bool treeIsEmpty(const Tree *ptree);
bool treeIsFull(const Tree *ptree);
int treeItemCount(const Tree *ptree);
bool addItem(const Item *pi, Tree *ptree){
    Trnode *new_node;
    if (treeIsFull(ptree)){
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if (seekItem(pi, ptree).child != NULL){
        fprintf(stderr, "trying to add existing element\n");
        return false;
    }
    new_node = makeNode(pi);
    if (new_node == NULL){
        fprintf(stderr, "Cant find the node\n");
        return false;
    }
    ptree->size++;
    if (ptree->root == NULL)
        ptree->root = new_node;
    else 
        addNode(new_node, ptree->root);
    return true;
}
bool inTree(const Item*pi, const Tree *ptree);
bool deleteItem(const Item *pi, Tree *ptree);
static void inOrder (const Trnode *root, void (*pfun)(Item item)){
    if (root!=NULL){
        inOrder(root->left, pfun);
        (*pfun)(root->item);
        inOrder(root->right, pfun);
    }
}
void traverse(const Tree *ptree, void (*pfun)(Item item)){
    if(ptree != NULL)
        inOrder(ptree->root, pfun);
}

static void deleteAllNodes(Trnode *root){
    Trnode *pright;
    if (root != NULL){
        pright = root->right;
        deleteAllNodes(root->left);
        free(root);
        deleteAllNodes(pright);
    }
}
void deleteAll(Tree *ptree){
    if (ptree != NULL)
        deleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}
