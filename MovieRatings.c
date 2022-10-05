#include <stdio.h>
#include <stdlib.h>
#include "MovieList.h"

void showMovies(Item item);
char * s_gets(char *st,int n);

static void List_Init(List *plist);
static bool ListIsEmpty(const List *plist);
static bool ListIsFull(const List *plist);
static unsigned int ListItemCount(const List *plist);
static bool AddItem(Item item, List *plist);
static void Traverse(const List* plist, void (*pfun)(Item item));
static void EmptyTheList(List *plist);


int main(void){

    List movies;
    Item temp;
    List_Init(&movies);
    if (ListIsFull(&movies)){
        fprintf(stderr, "ERROR: No memory available!\n");
        exit(1);
    }

    puts("First movie name: ");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0'){
        puts("Your rating (0-10): ");
        scanf("%d", &temp.rating);
        while (getchar() != '\n');
            continue;
        if (AddItem(temp, &movies) == false){
            fprintf(stderr, "ERROR: Memory allocation error!\n");
            break;
        }
        if (ListIsFull(&movies)){
            puts("List is full");
            break;
        }
        puts("Enter next movie name: (or empty string to finish)");

    }

    if (ListIsEmpty(&movies))
        printf("No data entered");
    else{
        printf("Movie list: \n");
        Traverse(&movies, showMovies);
    } 
    printf("You entered %d movies. \n", ListItemCount(&movies));

    EmptyTheList(&movies);
    printf("Done\n");
    return 0;

}

void showMovies(Item item){
    printf("Movie: %s Rating : %d", item.title, item.rating);
}

char * s_gets(char *st, int  n){
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');
        if (find){
            *find = '\0';

        } else {
            while (getchar() != '\n')
            continue;
        }
        return ret_val;
    }
}

//interface functions - should be in separate file, but I am lazy
static void CopyToNode(Item item, Node *pnode);
void List_Init(List *plist){
    *plist = NULL;
}

static bool ListIsEmpty(const List *plist){
    if (*plist == NULL)
        return true;
    else 
        return false;
}

static bool ListIsFull(const List* plist){
    Node *pt;
    bool full;
    pt = (Node*) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else 
        full = false;
    free(pt);
    return full;
}

static unsigned int ListItemCount(const List *plist){
    unsigned int count = 0;
    Node *pnode = *plist;
    while (pnode != NULL){
        ++count;
        pnode = pnode->next;
    }
    return count;

}

static bool AddItem(Item item, List *plist){
    Node *pnew;
    Node *scan = *plist;

    pnew = (Node*) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)
        *plist = pnew;
    else{
            while(scan->next != NULL)
                scan = scan->next;
            scan->next = pnew;
        }
    return true;
}

static void Traverse(const List* plist, void (*pfun)(Item item)){
    Node *pnode = *plist;
    while (pnode != NULL){
        (*pfun)(pnode->item);
        pnode = pnode->next;

    }
}

static void EmptyTheList(List *plist){
    Node *psave;
    while (*plist != NULL){
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

static void CopyToNode(Item item, Node* pnode){
    pnode->item = item;
}
