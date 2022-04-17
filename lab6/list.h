#ifndef LIST_H
#define LIST_H

using namespace std;

struct list;
typedef struct list list_t;

void push(list_t *&list, int d);
int  deleteElement(list_t* list, int choose_el);
void outListID(list_t *list);
void outListB(list_t* list);

#endif
