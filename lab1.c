#include <stdio.h>
#include <stdlib.h>

int *plus_1(int *data, int *size, int new) {
	(*size)++;
	int *temp = (int*)malloc(sizeof(int) * (*size));


	for (int i = 0; i < (*size) - 1; i++){
		temp[i] = data[i];
	}
	temp[(*size) - 1] = new; 

	return temp;
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

}