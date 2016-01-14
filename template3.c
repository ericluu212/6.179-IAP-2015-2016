#include <stdio.h>
#include <stdlib.h>

int * zeroArray(int size) {
	//int arr[size];
	int *arr = malloc(sizeof(*arr) * size);
	int i;
	for (i = 0; i < size; i++) {
		arr[i] = 0;
	}
	return arr;
}

int main() {
	int *arr = zeroArray(5);
	int i;

	for (i = 0; i < 5; i++) {
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;
}