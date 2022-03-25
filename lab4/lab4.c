#include <stdio.h>
#include <stdlib.h>


#define SUCCES 1
#define REALLOC_ERROR 2
#define SCANF_ERROR "ERROR:SCANF ERROR\n"
<<<<<<< HEAD
=======
#define MALLOC_ERROR "ERROR:MALLOC ERROR\n"
#define REALLOC_ERROR "ERROR:REALLOC ERROR\n"
#define PUSH_ERROR "ERROR: STACK IS OUT OF RANGE\n"
>>>>>>> ce1c11d00dd1c5c76bb8234cf3747f7d001320ac
#define POP_ERROR "ERROR: STACK IS OUT OF RANGE\n"
#define OPTION_CHOOSE_ERROR "ERROR:CHOOSE ANOTHER OPTION\n"

int succes_code = SUCCES;

typedef int* arr_t; 

typedef struct arr { //structure
	arr_t ptr;
	int size;
} stack_t;

<<<<<<< HEAD
void clean(stack_t *st) {   // ГЋГ·ГЁГ±ГІГЄГ  ГЇГ Г¬ГїГІГЁ

	free(st->ptr);
	st->ptr = NULL;
	st->size = 0;

}

void realloc_data(stack_t *st, int newsize) { // reallocation
	int *tmp_ptr = (int*)realloc(st->ptr, sizeof(int) * newsize);
	if (tmp_ptr != NULL || newsize == 0) {
        st->ptr = tmp_ptr;
        st->size = newsize;
        succes_code = SUCCES;
    } 
    else {
    	succes_code = REALLOC_ERROR;
	}	
}

void create(stack_t *st) { //create structure
	st->size = 0;
	st->ptr = NULL;
}

void createcopy(stack_t* st, stack_t* new_st) {	// copy

	realloc_data(new_st, st->size);

	for (int i = 0; i < new_st->size; ++i) {

		new_st->ptr[i] = st->ptr[i];

	}
	
}

int push(stack_t *st, int a, int *push_Size) { //push element to stack
	(*push_Size)++;
	st->size++;
	realloc_data(st, st->size);
	st->ptr[st->size - 1] = a;
	
}

int pop (stack_t *st,int *pop_Size) { //pop element to stack
	if (st->size != 0) {
		int tmp = st->ptr[st->size - 1];
		st->ptr[st->size - 1] = -1;
		(*pop_Size)--;
		st->size--;
		realloc_data(st, st->size);
		return tmp;
	}
}

void swap_TOP2(stack_t *st, int *tmp_Size) { // swap top two elements of stack
	if (*tmp_Size == 1) {
		printf("\nno need in swap\n");

	}
	else if (*tmp_Size == 0) {
		printf(POP_ERROR);

	}
	else {

		int tmp;

		stack_t st2;
		int st2_size = 0;
		create(&st2);

		stack_t st3;
		int st3_size = 0;
		create(&st3);

		tmp = pop(st, tmp_Size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			exit(0);
		}
		push(&st2, tmp, &st2_size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			exit(0);
		} 

		printf("Swapped elements are:");
		printf("%i and ", tmp);

		tmp = pop(st, tmp_Size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			exit(0);
		}
		push(&st3, tmp, &st3_size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			exit(0);
		}

		printf("%i", tmp);

		tmp = pop(&st2, &st2_size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
		}
		push(st, tmp, tmp_Size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
			exit(0);
		}

		tmp = pop(&st3, &st3_size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
		}

		push(st, tmp, tmp_Size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
			exit(0);
		}

		clean(&st2);
		clean(&st3);

=======
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
>>>>>>> ce1c11d00dd1c5c76bb8234cf3747f7d001320ac
	}

}

<<<<<<< HEAD
void delete_BOTTOM(stack_t *st, int *tmp_Size) { // delete bottom element of stack
	if (*tmp_Size == 1) {
		printf("\nno need in swap\n");

	}
	else if (*tmp_Size == 0) {
		printf(POP_ERROR);

	}
	else {

		int tmp;

		stack_t st2;
		int st2_size = 0;
		create(&st2);

		while (*tmp_Size != 1) {
			tmp = pop(st, tmp_Size);
			if (succes_code == REALLOC_ERROR){
				clean(st);
				exit(0);
			} 
				push(&st2, tmp, &st2_size);
			if (succes_code == REALLOC_ERROR) {
				clean(st);
				clean(&st2);
			}

		}

		printf("Deleted element is: ");
		printf("%i", pop(st, tmp_Size));

		while (st2_size != 0) {
			tmp = pop(&st2, &st2_size);
			if (succes_code == REALLOC_ERROR) {
				clean(st);
				clean(&st2);
				exit(0);
			}
			push(st, tmp, tmp_Size);
			if (succes_code == REALLOC_ERROR) {
				clean(st);
				clean(&st2);
				exit(0);
			}
		}

		clean(&st2);

	}


}

void swap_TOPBOTTOM(stack_t *st, int *tmp_Size) { // swap top and bottom element
	if (*tmp_Size == 1) {
		printf("\nno need in swap\n");

	}
	else if (*tmp_Size == 0) {
		printf(POP_ERROR);

	}
	else {

		int tmp;

		stack_t st2;
		int st2_size = 0;
		create(&st2);

		stack_t st3;
		int st3_size = 0;
		create(&st3);

		stack_t st4;
		int st4_size = 0;
		create(&st4);

		tmp = pop(st, tmp_Size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			exit(0);
		}
		push(&st2, tmp, &st2_size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			exit(0);
		}
		printf("Swapped elements are: ");
		printf("%i and ", tmp);

		while (*tmp_Size != 1) {
			tmp = pop(st, tmp_Size);
			if (succes_code == REALLOC_ERROR){
				clean(st);
				clean(&st2);
				clean(&st3);
				exit(0);
			}
			push(&st3, tmp, &st3_size);
			if (succes_code == REALLOC_ERROR) {
				clean(st);
				clean(&st2);
				clean(&st3);
				exit(0);
			}

		}

		tmp = pop(st, tmp_Size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
			exit(0);
		}
		push(&st4, tmp, &st4_size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
			exit(0);
		}

		printf("%i", tmp);

		tmp = pop(&st2, &st2_size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
			clean(&st4);
			exit(0);
		}
		push(st, tmp, tmp_Size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
			clean(&st4);
			exit(0);
		}

		while (st3_size != 0) {
			tmp = pop(&st3, &st3_size);
			if (succes_code == REALLOC_ERROR) {
				clean(st);
				clean(&st2);
				clean(&st3);
				clean(&st4);
				exit(0);
			}
			push(st, tmp, tmp_Size);
			if (succes_code == REALLOC_ERROR) {
				clean(st);
				clean(&st2);
				clean(&st3);
				clean(&st4);
				exit(0);
			}
		}

		tmp = pop(&st4, &st4_size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
			clean(&st4);
			exit(0);
		}
		push(st, tmp, tmp_Size);
		if (succes_code == REALLOC_ERROR) {
			clean(st);
			clean(&st2);
			clean(&st3);
			clean(&st4);
			exit(0);
		}

		clean(&st2);
		clean(&st3);
		clean(&st4);
	}

=======
int pop (stack_t *st) { //извлечение верхушки стека
	if (st->size != 0) {
		int tmp = st->ptr[st->size - 1];
		st->ptr[st->size - 1] = -1;
		st->size--;
		realloc_data(st);
		return tmp;
	}
}

void swap_top2(stack_t *st) {
	if (st->size == 1) {
		printf("no need in swap");
	}
	else if (st->size == 0) {
		printf(POP_ERROR);
	}
	else {
		stack_t st2;
		create(&st2);
		int tmp1;
		tmp1 = pop(st);
		push(&st2, tmp1);
		stack_t st3;
		create(&st3);
		int tmp2;
		tmp2 = pop(st);
		push(&st3, tmp2);
		push(st, st2.ptr[0]);
		push(st, st3.ptr[0]);
		printf("\nswaped elements are: ");
		printf("%i  ", tmp1);
		printf("%i\n", tmp2);
	}

}

void delete_bottom(stack_t *st) {
	if (st->size == 1) {
		printf("\ndeleted bottom element is: ");
		printf("%i\n", st->ptr[0]);
		pop(st);
	}
	else if (st->size == 0) {
		printf("\nnothing to delete\n");
	}
	else{
		stack_t st2;
		create(&st2);
		while (st->size != 1) {
			push(&st2, st->ptr[st->size - 1]);
			pop(st);
		}
		printf("\ndeleted element is: ");
		printf("%i\n", st->ptr[0]);
		pop(st);
		while(st2.size != 0) {
			push(st, st2.ptr[st2.size - 1]);
			pop(&st2);
		}
	}
}

void swap_top_bottom(stack_t *st) {
	if (st->size == 1) {
		printf("\nno need in swap\n");
	}
	else if (st->size == 0) {
		printf(POP_ERROR);
	}
	else {
		stack_t st2;
		create(&st2);
		push(&st2, st->ptr[st->size - 1]);
		pop(st);
		stack_t st3;
		create(&st3);
		while (st->size != 1) {
			push(&st3, st->ptr[st->size - 1]);
			pop(st);
		}
		stack_t st4;
		create(&st4);
		push(&st4, st->ptr[0]);
		pop(st);

		push(st, st2.ptr[0]);
		int tmp1 = pop(&st2);
		while(st3.size != 0) {
			push(st, st3.ptr[st3.size - 1]);
			pop(&st3);
		}
		push(st, st4.ptr[0]);
		int tmp2 = pop(&st4);
		printf("\nswapped elements are: ");
		printf("%i ", tmp1);
		printf("%i\n", tmp2);
	}
}

void task() { //список заданий
	printf("\nclear the stack(1)\nadd an element(2)\npop the element(3)\nswap 2 top elements(4)\ndelete the bottom element(5)\nswap top and bottom(6)\nend(0)\n\n");
>>>>>>> ce1c11d00dd1c5c76bb8234cf3747f7d001320ac
}

void task() { // list of tasks
	printf("\nclear the stack(1)\nadd an element(2)\npop the element(3)\nswap 2 top elements(4)\ndelete the bottom element(5)\nswap top and bottom(6)\nend(0)\n\n");
}

void menu(stack_t *st) { // what to do
	int choose = 1;
	task();
	int new_element;
<<<<<<< HEAD
	int check_push;
	int st1_size = 0;
=======
	int tmp_pop;
	int tmp_clean;
	int check_push;
>>>>>>> ce1c11d00dd1c5c76bb8234cf3747f7d001320ac
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
<<<<<<< HEAD

			case 1: {

				while (st1_size != 0) {
					printf("\ndeleted element is: ");
					int tmp;
					printf("%i\n", tmp = pop(st, &st1_size));
					if (succes_code == REALLOC_ERROR) {
						clean(st);
						exit(0);
					}
				}
				if (st1_size == 0)
					printf("\n     #######\n     #CLEAN#\n     #######\n");

				break;
			}

			case 2: {

=======
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
>>>>>>> ce1c11d00dd1c5c76bb8234cf3747f7d001320ac
				printf("\nenter new element: ");
				int check_push = scanf("%i", &new_element);
				while (check_push != 1){
					printf(SCANF_ERROR);
					printf("\nenter new element: ");
					int check_push = scanf("%i", &new_element);
				}
<<<<<<< HEAD
				push(st, new_element, &st1_size);
				if (succes_code == REALLOC_ERROR) {
					clean(st);
					exit(0);
				}
				break;
			}

			case 3: {

				if (st1_size != 0) {
					printf("poped element is: ");
					int tmp;
					printf("%i\n", tmp = pop(st, &st1_size));
					if (succes_code == REALLOC_ERROR) {
						clean(st);
						exit(0);
					}
				}
				else
					printf(POP_ERROR);

=======
				push(st, new_element);
				break;
			case 3:
				if (st->size != 0) {
					printf("poped element is: ");
					printf("%i\n", st->ptr[st->size - 1]);
					pop(st);
				}
				else
					printf(POP_ERROR);
>>>>>>> ce1c11d00dd1c5c76bb8234cf3747f7d001320ac
				break;
			}

			case 4:
<<<<<<< HEAD
				swap_TOP2(st, &st1_size);

				break;
			case 5:
				delete_BOTTOM(st, &st1_size);

				break;
			case 6:
				swap_TOPBOTTOM(st, &st1_size);

=======
				swap_top2(st);
				break;
			case 5:
				delete_bottom(st);
				break;
			case 6:
				swap_top_bottom(st);
>>>>>>> ce1c11d00dd1c5c76bb8234cf3747f7d001320ac
				break;
			case 10:
				task();

				break;
			case 0:
				printf("#####END OF THE PROGRAM#####");
				clean(st);
				exit(0);
			default:
				printf(OPTION_CHOOSE_ERROR);

				break;	
		}
	}
}


int main() {
	stack_t st1;	
	stack_t st_new;
	create(&st1);
	createcopy(&st1,&st_new);
	menu(&st_new);
}
