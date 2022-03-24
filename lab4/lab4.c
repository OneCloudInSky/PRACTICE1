#include <stdio.h>
#include <stdlib.h>

#define SCANF_ERROR "ERROR:SCANF ERROR\n"
#define MALLOC_ERROR "ERROR:MALLOC ERROR\n"
#define REALLOC_ERROR "ERROR:REALLOC ERROR\n"
#define PUSH_ERROR "ERROR: STACK IS OUT OF RANGE\n"
#define POP_ERROR "ERROR: STACK IS OUT OF RANGE\n"
#define OPTION_CHOOSE_ERROR "ERROR:CHOOSE ANOTHER OPTION\n"
#define STACK_MAX_SIZE 20

typedef int* arr_t; 

typedef struct arr { //создание структуры
	arr_t ptr;
	int size;
} stack_t;

void realloc_data(stack_t *st) {
	int *tmp_ptr = (int*)realloc(st->ptr, sizeof(int) * st->size);
	if (tmp_ptr != NULL) {
		st->ptr = tmp_ptr;
	}
	else if (st->size == 0) {
		st->ptr = NULL;
	}
	else {
		printf(REALLOC_ERROR);
		free(st->ptr);
		exit(0);
	}
	
}

void create(stack_t *st) { //создание стэка
	st->size = 0;
	st->ptr = NULL;
}

void push(stack_t *st, int a) { //добавление элемента в стек
	if (st->size == STACK_MAX_SIZE) {
		printf(PUSH_ERROR);
	}
	else {
		st->size++;
		realloc_data(st);
		st->ptr[st->size - 1] = a;
	}
}

int pop (stack_t *st) { //извлечение верхушки стека
	if (st->size != 0) {
		int tmp = st->ptr[st->size - 1];
		st->ptr[st->size - 1] = -1;
		st->size--;
		realloc_data(st);
		return tmp;
	}
}

void task() { //список заданий
	printf("\nclear the stack(1)\nadd an element(2)\npop the element(3)\nswap 2 top elements(4)\ndelete the bottom element(5)\nswap top and bottom(6)\nend(0)\n\n");
}

void menu(stack_t *st) { //меню выбора заданий
	int choose;
	task();
	int new_element;
	int tmp_pop;
	int tmp_clean;
	while (choose != 0){
		int choose;
		printf("\nchoose the option(press 10 to show the task): ");
		int check = scanf("%i", &choose);
		while (check != 1) {
			printf(SCANF_ERROR);
			printf("\nchoose the option(press 10 to show the task): ");
			int check = scanf("%i", &choose);
		}
		switch(choose) {
			case 1:
				while (st->size != 0) {
					printf("\ndeleted element is: ");
					printf("%i\n", st->ptr[st->size - 1]);
					pop(st);
				}
				if (st->size == 0)
					printf("\n     #######\n     #CLEAN#\n     #######\n");
				break;
			case 2:
				printf("enter new element: ");
				scanf("%i", &new_element);
				push(st, new_element);
				break;
			case 3:
				if (st->size != 0) {
					printf("poped element is: ");
					printf("%i", st->ptr[st->size - 1]);
					pop(st);
				}
				else
					printf(POP_ERROR);
				break;
			case 4:
				//
				break;
			case 5:
				//
				break;
			case 6:
				//
				break;
			case 10:
				task();
				break;
			case 0:
				printf("#####END OF THE PROGRAM#####");
				free(st->ptr);
				exit(0);
			default:
				printf(OPTION_CHOOSE_ERROR);
				break;	
		}
	}
}


int main() {
	stack_t st1;	
	create(&st1);
	menu(&st1);
}
