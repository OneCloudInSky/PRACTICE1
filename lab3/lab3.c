#include <stdio.h>
#include <stdlib.h>

#define MALLOC_FAILED -1

void freedata(int* data) {
	free(data);
}

int *create(int *size, int *exit) {
	int *data = (int*)malloc(sizeof(int) * (*size));
	if (data != NULL) {
		printf("enter the elements: ");
		for (int i = 0; i < *size; i++) {
			scanf("%i", &data[i]);
			if (&data[i] == NULL) {
				printf("scanf error");
				freedata(data);
				return 0;
			}
		}
		return data;
	}

	else {
		*exit = MALLOC_FAILED;
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
		scanf("%i", &size);
		if (&size == NULL) {
			printf("scanf error");
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
			scanf("%i", &choose2);

			if (&choose2 == NULL) {
				freedata(data);
				printf("scanf error");
				return 0;
			}

			switch(choose2) {
				case 1:
					printf("\nenter the new element: ");

					int new;

					scanf("%i", &new);

					if (&new == NULL) {
						printf("scanf error");
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

					scanf("%i", &ind);

					if (&ind == NULL) {
						printf("scanf error");
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

					scanf("%i", &delel);

					if (&delel == NULL) {
						printf("scanf error");
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
		scanf("%i", &choose1);

		if (&choose1 == NULL) {
			printf("scanf error");
			freedata(data);
			return 0;
		}

	}
}