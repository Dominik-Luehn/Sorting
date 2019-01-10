#include "pch.h"
#include <iostream>

void bubble_sort(int* array, int length) {
	if (length > 0) {
		for (int m = 0; m < length; m++) {
			for (int i = 0; i < length - 1; i++) {
				if (array[i] > array[i + 1]) {
					int tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
				}
			}
		}
	}
}

void selection_sort(int* array, int length) {
	int min;
	for (int i = 0; i < length; i++) {
		min = array[i];
		for (int m = (i + 1); m < length; m++) {
			if (min > array[m]) {
				min = m;
			}
		}
		if (array[i] > array[min]) {
			int tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
	}
}

void print_array(int* array, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d  ", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = { 7, 6, 5, 4, 9, 1, 3, 8, 2 };
	bubble_sort(array, 9);
	print_array(array, 9);
}