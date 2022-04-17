#include <iostream>
#include "list.h"

using namespace std;

struct list {
	int data;
	struct list* next;
};

void push(list_t *&list, int d) {
	
	list_t *newnode = new list_t;
	
	if (newnode != NULL) {
		
		newnode->data = d;
		newnode->next = NULL;
		
		if (list == NULL) {
			
			list = newnode;
			
		}
		
		else {
			
			list_t *tmp = list;
			while (tmp->next != NULL){
				
				tmp = tmp->next;
				
			}
			
			tmp->next = newnode;
			
		}
		
	}
	
}

int  deleteElement(list_t *list, int choose_el) {
	int flag = 0;
	list_t *tmp = list;
	while (tmp->data == choose_el && tmp->next != NULL) {
		list = tmp->next;
		tmp = list;
	}
	if (tmp->next == NULL && tmp->data == choose_el) {
		list = NULL;
		return 0;
	}
	while (tmp->next != NULL and tmp != NULL) {
		if (tmp->data != choose_el) {
			flag++;
			tmp = tmp->next;
		}
		else {
			tmp = tmp->next;
			list_t *tmp2 = list;
			for (int i = 0; i < flag - 1; i++) {
				tmp2= tmp2->next;			
			}
			tmp2->next = tmp;
		}
	}
	if (tmp->data == choose_el) {
		list_t* tmp2 = list;
		for (int i = 0; i < flag - 1; i++) {
			tmp2 = tmp2->next;
		}
		tmp2->next = NULL;
	}
	return 0;
}

void outListID(list_t *list) {
	
	list_t *tmp = list;
	
	printf("\nThe new list is: { ");
	
	while (tmp!= NULL) {
		
		cout << tmp->data << ' ';
		tmp = tmp->next;
		
	}
	
	printf("}\n");
	
}

void outListB(list_t* list) {
	
	list_t* tmp = list;
	
	if (tmp->next != NULL) {
		outListB(tmp->next);
		printf("%i", tmp->data);
		printf(" ");
	}
	else {
		printf("%i", tmp->data);
		printf(" ");
	}
}

