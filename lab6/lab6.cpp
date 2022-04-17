#include <iostream>
#include "list.cpp"

using namespace std;

int foundMax(list_t* list) {
	if (list == NULL) return -1;
	list_t* tmp = list;
	int max = tmp->data;
	
	if (tmp->next == NULL) return max;
	
	tmp = tmp->next;
	
	while (tmp->next != NULL) {
		if (tmp->data > max) max = tmp->data;
		tmp = tmp->next;
	}
	
	if (tmp->data > max) max = tmp->data;
	
	return max;
	
}

int foundMin(list_t* list) {
	if (list == NULL) return -1;
	list_t* tmp = list;
	int min = tmp->data;
	
	if (tmp->next == NULL) return min;
	
	tmp = tmp->next;
	
	while (tmp->next != NULL) {
		if (tmp->data < min) min = tmp->data;
			tmp = tmp->next;
	}
	
	if (tmp->data < min) min = tmp->data;

	return min;
}

list_t* findptr_prev(list_t *list, int value) {
	list_t *ptr;
	list_t *tmp = list;
	
	if (tmp->data == value) {
		ptr = tmp;
		return ptr;
	}
	
	while (tmp->next != NULL) {
		if (tmp->next->data == value) {
			ptr = tmp;	
		}
		tmp = tmp->next;
	}
	
	return ptr;
}

int swap(list_t* list) {
	if (list == NULL) return -1;
	
	int min = foundMin(list);
	int max = foundMax(list);
	
	list_t* max_ptr_prev;
	list_t* min_ptr_prev;
	
	list_t* tmpmin = list;
	list_t* tmpmax = list;
	
	max_ptr_prev = findptr_prev(tmpmax, max);
	min_ptr_prev = findptr_prev(tmpmin, min);
	
	list_t* tmp_next;
	list_t* tmp;
		
	tmp_next = max_ptr_prev->next;
	max_ptr_prev->next = min_ptr_prev->next;
	min_ptr_prev->next = tmp_next;
			
	tmp = max_ptr_prev->next->next;
	max_ptr_prev->next->next = min_ptr_prev->next->next;
	min_ptr_prev->next->next = tmp;
			
	
	return 0;
}

void task() {
	
	printf("\n1 - insert new element\n2 - delete all key elements\n3 - find min and max\n4 - swap min and max\n5 - printf all the elements in derect order and backwards\n0 - END\n");
	
}

void menu(list_t* list) {
	task();
	
	while(1) {
			
		int choose;
		printf("\nChoose the option: ");
		scanf("%i", &choose);
		
		switch(choose) {
			case 1: {				
				int value;
				printf("\nEnter the value of the new element: ");
				scanf("%i", &value);
				push(*&list, value);
			    outListID(list);	
				break;					
			}			
			case 2: {			
				int key;
				printf("\nEnter the key: ");
				scanf("%i", &key);
				deleteElement(list, key);
				outListID(list);
				break;			
			}			
			case 3: {
				int max;
				max = foundMax(list);
				if (max == -1) printf("\nfoundMax error:no value\n");
				else printf("\n%s %i\n", "Max value is:",max);
				
				int min;
				min = foundMin(list);
				if (max == -1) printf("\nfoundMin error:no value\n");
				else printf("\n%s %i\n", "Min value is:",min);
				
				break;
			}
			case 4: {
				outListID(list);
				swap(list);
				outListID(list);
				break;
			}
			case 5: {
				outListID(list);	
				printf("\nBackwards list is: { ");
				outListB(list);
				printf("}\n");	
				break;
			}
			case 0: {		
				printf("\nEXIT\n");
				exit(0);
				break;	
			}	
		}
	}
}

int main() {
	list_t* l1 = NULL;
	menu(l1);
}
