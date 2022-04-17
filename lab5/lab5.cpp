#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;

void outqueue(queue_t* q) {
	printf("\n");
	for (int i = 0; i < q->size; i++) {
		printf("%i ", q->arr[i]);
	}
	printf("\n");	
}

void task() {
	printf("\n1 - Add one element to queue\n2 - Delete 1 element from queue\n3 - Clear queue\n4 - Add zeros\n5 - Delete the tail\n6 - Replace tail with head\n0 - END\n");
}

int getScanf() {
	int a; 
	int check = scanf("%i", &a);
	if (check != 1) {
		getScanf();
	}
	return a;
}

int inAdded() {
	printf("\nEnter the value of the element you want to add: ");
	int value = getScanf();
}

void outAdded(int value) {
	printf("\nAdded element is: ");
	printf("%i\n", value);
}

int outDeleted() {
	printf("\nDeleted element is: ");
}

void clean(queue_t* q) {
	try {		
		while (!isEmpty(q)) {	
			outDeleted();
			printf("%i", dequeue(q));
			printf("\n");
			
		}
		
	}
	catch (int error) {		
		throw DEQUEUE_ERROR;
		
	}
}
	

void addZero(queue_t* q) {
	queue_t new_q, copy_q;
	create(&new_q);
	create(&copy_q);
	
	try {
		createCopy(q, &copy_q);
		
		while (!isEmpty(&copy_q)) {
			enqueue(&new_q, dequeue(&copy_q));
			enqueue(&new_q, 0);
			
		}
	
		createCopy(&new_q, q);
		delete_q(&new_q);
		
	}
	
	catch(int error) {
		delete_q(&new_q);
		delete_q(&copy_q);
		throw UNDEFINED_ERROR;
		
	}
}

void deleteTail(queue_t* q) {

	queue_t new_q, copy_q;
	create(&new_q);
	create(&copy_q);

	try {

		createCopy(q, &copy_q);

		while (!isEmpty(&copy_q)) {

			int head = dequeue(&copy_q);
			if (!isEmpty(&copy_q)) enqueue(&new_q, head);

		}

		createCopy(&new_q, q);
		delete_q(&new_q);

	}
	catch (int error) {

		delete_q(&new_q);
		throw UNDEFINED_ERROR;

	}

}

void swapTailHead(queue_t* q) {

	queue_t new_q, copy_q;
	create(&new_q);
	create(&copy_q);

	try {

		createCopy(q, &copy_q);

		int tail, head = Peak(&copy_q);

		while (!isEmpty(&copy_q)) {

			tail = dequeue(&copy_q);

		}

		createCopy(q, &copy_q);
		enqueue(&new_q, tail);
		deleteTail(&copy_q);
		dequeue(&copy_q);

		while (!isEmpty(&copy_q)) {

			enqueue(&new_q, dequeue(&copy_q));

		}

		enqueue(&new_q, head);
		createCopy(&new_q, q);
		delete_q(&new_q);
		
	}
	catch (int error) {
		delete_q(&new_q);
		throw UNDEFINED_ERROR;

	}

}



void menu(queue_t* q) {
	task();	
	while(1) {
		printf("\nChoose the option: ");
		int choose = getScanf();
		switch(choose) {
			case 1: {
				int value = inAdded();
				enqueue(q, value);
				outAdded(value);
				outqueue(q);
				break;
				
			}
			case 2: {
				
				int deletedValue = dequeue(q);
				
				if (deletedValue != DEQUEUE_ERROR) {
					outDeleted();
					printf("%i\n", deletedValue);
					outqueue(q);
					
				}
				else {
					
					printf("\nDEQUEUE ERROR\n");
					
				}
				
				break;
				
			}
			
			case 3: {
				
				clean(q);
				
				break;
				
			}
			
			case 4: {
				
				addZero(q);
				outqueue(q);
				
				break;
				
			}
			
			case 5: {
				deleteTail(q);
				outqueue(q);
				
				break;
				
			}
			
			case 6: {
				
				swapTailHead(q);
				outqueue(q);
				
				break;
				
			}
			case 0: {
				
				free(q->arr);
				printf("\n     #####\n     #END#\n     #####\n");
				exit(0);
				
				break;
				
			}
			
			default: {
				
				menu(q);
				
				break;
				
			}
		}
	}
}

int main() {
	queue_t queue1;
	create(&queue1);
	menu(&queue1);
}

