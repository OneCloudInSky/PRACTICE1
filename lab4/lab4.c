#include <stdio.h>
#include <stdlib.h>

#define SCANF_ERROR "ERROR:SCANF ERROR\n"
#define MALLOC_ERROR "ERROR:MALLOC ERROR\n"
#define REALLOC_ERROR "ERROR:REALLOC ERROR\n"
#define PUSH_ERROR "ERROR: STACK IS OUT OF RANGE\n"
#define PEAK_ERROR "ERROR: STACK IS OUT OF RANGE\n"
#define OPTION_CHOOSE_ERROR "ERROR:CHOOSE ANOTHER OPTION\n"
#define STACK_MAX_SIZE 20

typedef int* arr_t; 

typedef struct arr { //создание структуры
	arr_t ptr;
	int size;
} stack_t;

void create(stack_t *st) { //создание стэка
	st->size = 0;
	st->ptr = (int*)malloc(sizeof(int) * st->size);
	if (st->ptr == NULL) {
		exit(MALLOC_ERROR);
	}
}

void clear(stack_t *st) { //очищение стека
	while (st->size != 0) {
		printf("\ndeleted element is: ");
		printf("%i", st->ptr[st->size - 1]);
		st->ptr[st->size - 1] = NULL;
		st->size--;
	}
	printf("no elements to delete\n#######\n#CLEAN#\n#######\n");
}

void check_scanf(int *a) { //проверка на корректность ввода
	if (a == NULL) {
		exit(SCANF_ERROR);
	}
}

int get_new_el() { //создание нового элемента для функции push
	int element;	
	printf("enter new element: ");
	scanf("%i", &element);
	check_scanf(&element);
	return element;	
}

void push(stack_t *st) { //добавление элемента в стек
	if (st->size == STACK_MAX_SIZE) {
		printf(PUSH_ERROR);
	}
	else {
		st->ptr[st->size] = get_new_el();
		st->size++;
	}
}

void peak(stack_t *st) { //извлечение верхушки стека
	if (st->size != 0) {
		printf("\npeak element is: ");
		printf("%i", st->ptr[st->size - 1]);
		st->ptr[st->size - 1] = NULL;
		st->size--;
	}
	else
		printf(PEAK_ERROR);
}

void task() { //список заданий
	printf("\nclear the stack(1)\nadd an element(2)\nget the peak of stack(3)\nswap 2 top elements(4)\ndelete the bottom element(5)\nswap top and bottom(6)\nend(0)\n\n");
}

void menu(stack_t *st) { //меню выбора заданий
	int choose;
	task();
	while (choose != 0){
		int choose;
		printf("\nchoose the option(press 10 to show the task): ");
		scanf("%i", &choose);
		check_scanf(&choose);
		switch(choose) {
			case 1:
				clear(st);
				break;
			case 2:
				push(st);
				break;
			case 3:
				peak(st);
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

