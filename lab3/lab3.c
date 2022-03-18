#include <stdio.h>
#include <stdlib.h>

#define MALLOC_FAILED -1
#define SCANF_ERROR "ERROR: FAILED TO GET A VALUE\n"

void freedata(int* data) {
	free(data);
}

int *create(int *size, int *ex) {
	int *data = (int*)malloc(sizeof(int) * (*size));
	if (data != NULL) {
		printf("enter the elements: ");
		for (int i = 0; i < *size; i++) {
			int check = scanf("%i", &data[i]);
			if (check != 1) {
				printf(SCANF_ERROR);
				exit(0);
			}
		}
		return data;
	}

	else {
		*ex = MALLOC_FAILED;
		return 0;
	}
}


void* reallocdata(int* data, int size) {
	int* tmp_ptr = (int*)realloc(data, size * sizeof(int));
	if (tmp_ptr != NULL) 
		data = tmp_ptr;
	else if (size == 0) {
		data = tmp_ptr;
	}
	else {
		printf("realloc error");
		freedata(tmp_ptr);
		exit(0);
	}
}

int *plus_1(int *data, int *size, int new) {
	(*size)++;
	data = reallocdata(data, *size);
	data[*size - 1] = new;
	return data;	
}


int *del_ind(int *data, int *size, int ind) {
	if (ind >= *size) 
		return data;

	(*size)--;

	for (int i = ind; i < *size; i++) {
		data[i] = data[i + 1];
	}

	reallocdata(data, (*size));
	return data;
}


int *delete_element(int *data, int *size, int delel) {
	for (int i = 0; i < *size; i++) {
		if (data[i] == delel) {
			data = del_ind(data, size, i);
			i--;
		}
	}
	return data;
}

int main() {
	int choose1 = 1;
	while (choose1 == 1) {
		printf("\nenter the lentgh of array: ");

		int size;
		int check = scanf("%i", &size);
		if (check != 1) {
			printf(SCANF_ERROR);
			exit(0);
		}

		int exit;

		int *data = create(&size, &exit);

		if (exit == MALLOC_FAILED) {
			return 0;
		}

	
		while (1) {

			int choose2;
			printf("\nchoose 1 - enter the new element, 2 - enter te index of the element you want to delete, 3 - enter the element you want to delete, everything else to end: ");
			int check = scanf("%i", &choose2);

			if (check != 1) {
				freedata(data);
				printf(SCANF_ERROR);
				return 0;
			}

			switch(choose2) {
				case 1:
					printf("\nenter the new element: ");

					int new;

					check = scanf("%i", &new);

					if (check != 1) {
						printf(SCANF_ERROR);
						return 0;
					}

					data = plus_1(data, &size, new);

					for (int i = 0; i < size; i++) {
						printf("%i ", data[i]);
					};
					break;
				case 2:
					printf("\nenter the index: ");

					int ind;

					check = scanf("%i", &ind);

					if (check != 1) {
						printf(SCANF_ERROR);
						return 0;
					}

					data = del_ind(data, &size, ind);

					for (int i = 0; i < size; i++) {
						printf("%i ", data[i]);
					};
					break;
				case 3:
					printf("\nenter the element to delete: ");

					int delel;

					check = scanf("%i", &delel);

					if (check != 1) {
						printf(SCANF_ERROR);
						return 0;
					}

					data = delete_element(data, &size, delel);

					for (int i = 0; i < size; i++) {
						printf("%i ", data[i]);
					};
					break;
				default:
					freedata(data);
					return 0;
			}
		}
		int choose1;
		printf("\nnext - 1, end - 0: ");
		check = scanf("%i", &choose1);

		if (check != 1) {
			printf(SCANF_ERROR);
			freedata(data);
			return 0;
		}

	}
}
