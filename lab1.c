#include <stdio.h>
#include <stdlib.h>

int *plus_1(int *data, int *size, int new) {
	(*size)++;
	int *temp = (int*)malloc(sizeof(int) * (*size));


	for (int i = 0; i < (*size) - 1; i++){
		temp[i] = data[i];
	}
	temp[(*size) - 1] = new; 

	free(data);
	return temp;
}

int *del_ind(int *data, int *size, int ind) {
	if (ind >= *size) 
		return data;

	(*size)--;

	for (int i = ind; i < *size; i++) {
		data[i] = data[i + 1];
	}

	data = (int*)realloc(data, sizeof(int) * (*size));

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
	printf("enter the lentgh of array: ");

	int size;
	scanf("%i", &size);

	int* data = (int*)malloc(sizeof(int) * size);

	printf("enter the elements: ");

	for (int i = 0; i < size; i++) {
		scanf("%i", &data[i]);
	}

	printf("enter the new element: ");

	int new;

	scanf("%i", &new);

	data = plus_1(data, &size, new);

	for (int i = 0; i < size; i++) {
		printf("%i ", data[i]);
	}

	printf("\nenter the index: ");

	int ind;

	scanf("%i", &ind);

	data = del_ind(data, &size, ind);

	for (int i = 0; i < size; i++) {
		printf("%i ", data[i]);
	}

	printf("\nenter the element to delete: ");

	int delel;

	scanf("%i", &delel);

	data = delete_element(data, &size, delel);

	for (int i = 0; i < size; i++) {
		printf("%i ", data[i]);
	}
}