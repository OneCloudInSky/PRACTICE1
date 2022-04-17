#include <malloc.h>
#include <iostream>
#include "queue.h"

using namespace std;

#define QUEUE_SIZE 3
#define INC_QUEUE 2
#define ALLOC_ERROR -1
#define REALLOC_ERROR -2
#define ENQUEUE_ERROR -3
#define DEQUEUE_ERROR -4
#define COPY_ERROR -5
#define PEAK_ERROR -6
#define UNDEFINED_ERROR -7
#define OK 1

typedef int* arr_t;

struct queue {
    arr_t arr;
    int size;
    
    int head;
    int tail;
};

void makeRealloc(queue_t* q, int new_size) {
		arr_t temp = (arr_t)realloc(q->arr, new_size * sizeof(int));

	if (temp == NULL && new_size != 0) {

		throw REALLOC_ERROR;

	}
	else {

		q->arr = temp;

		for (int i = q->size; i < new_size; ++i) {

			q->arr[i] = 0;

		}

		q->size = new_size;
		
	}
}

int create(queue_t *q) {
	q->arr =(int*)malloc(QUEUE_SIZE * sizeof(int));
	
	if (q->arr == NULL) {
		return ALLOC_ERROR;
		
	}
	
	q->size = QUEUE_SIZE;
	
	q->head = -1;
	
	q->tail = -1;
	
	for (int i = 0; i < q->size; i++) {
		q->arr[i] = -1;
		
	}
}

int Peak(queue_t *q) {

	if (q->head < 0) { 

		throw PEAK_ERROR;

	}

	return q->arr[q->head];

}

void createCopy(queue_t *old_q, queue_t* new_q) {
	try {
		makeRealloc(new_q, old_q->size);
		
		for (int i = 0; i < new_q->size; i++) {
			new_q->arr[i] = old_q->arr[i];
			
		}		
		new_q->head = old_q->head;
		new_q->size = old_q->size;
		new_q->tail = old_q->tail;

	}
	catch (int error) {
		throw COPY_ERROR;

	}
}

bool isEmpty(queue_t* q) {

	try {

		int temp = Peak(q);
		return false;

	}
	catch (int error) {		

		return true;

	}

}

int delete_q(queue_t* q) {
	free(q->arr);
	q->arr = NULL;
	q->size = 0;
	q->head = -1;
	q->tail = -1;
	
	return OK;
	
}


int enqueue(queue_t* q, int value) {
	try {
		if (q->tail == q->head - 1 || (q->head == 0 && q->tail == q->size - 1)) {
			
			int old_size = q->size;
			int new_size = q->size * INC_QUEUE + 1;
			makeRealloc(q, new_size);
	
			q->size = new_size;
			
			if (q->head != 0) {
				
				for (int i = 0; i < new_size - old_size;  i++){
					for (int j = new_size - 1; j >= q->head; j--) {
						q->arr[j + 1] = q->arr[j];
						
					}
					q->head = (q->head + 1) % q->size;
					
				}
				
				for (int i = q->tail + 1; i < q->head; i++) {
					q->arr[i] = -1;
					
				}
				
			}
			else {
				for (int i = q->tail + 1; i < q->size; i++) {
					q->arr[i] = -1;
					
				}
				
			}
			
		}
		
		q->tail = (q->tail + 1) % q->size;
	    q->arr[q->tail] = value;
	    
	    if (q->head == -1) {
	        q->head = 0;
	        
	    }
	    
	}
	catch (int error) {
		
		throw ENQUEUE_ERROR;
		
	}
	
}

int dequeue(queue_t* q) {
	try {
		int tmp; 
		if (q->head == -1 && q->tail == -1) return DEQUEUE_ERROR;	
		
		if (q->head != q->tail) {
			
			tmp = q->arr[q->head];
			q->arr[q->head] = -1;
			q->head = (q->head + 1) % q->size;
			
		}
		else {
			
			tmp = q->arr[q->head];
			for (int i = 0; i < q->size; i++) {
				q->arr[i] = -1;
				
			}
			
			q->head = -1;
			q->tail = -1;
			return(tmp);
			
		}
		
		return tmp;
	}
	catch(int error) {
		
		throw DEQUEUE_ERROR;
	}
		
}



