#include "pch.h"
#include <iostream>
#include <omp.h>


void merge(int* array_a, unsigned int length_a, int* array_b,
	unsigned int length_b) {
	int buffer_length = length_a + length_b;
	int* buffer = (int*)malloc(sizeof(int) * buffer_length);

	int* end_array_a = array_a + length_a;
	int* end_array_b = array_b + length_b;

	for (int i = 0; i < buffer_length; ++i) {
		if (array_a == end_array_a) {
			buffer[i] = *array_b;
			array_b++;
		}
		else if (array_b == end_array_b) {
			buffer[i] = *array_a;
			array_a++;
		}
		else {
			if (*array_a < *array_b) {
				buffer[i] = *array_a;
				array_a++;
			}
			else {
				buffer[i] = *array_b;
				array_b++;
			}
		}
	}

	array_a -= length_a;
	for (int i = 0; i < buffer_length; ++i) {
		array_a[i] = buffer[i];
	}

	free(buffer);
}

int* merge_sort(int* array, unsigned int length) {
	if (length <= 1) {
		return array;
	}
	// divide
	int mid = length / 2;
	merge_sort(array, mid);
	merge_sort(array + mid, length - mid);
	merge(array, mid, array + mid, length - mid);

	return array;
}

void swap_for_array(int* array, int first_element, int second_element) {
	int tmp = array[first_element];
	array[first_element] = array[second_element];
	array[second_element] = tmp;
}

void swap_array(int* array) {}

void bubble_sort(int* array, int length) {
	if (length > 0) {
		for (int m = 0; m < length; m++) {
			for (int i = 0; i < length - 1; i++) {
				if (array[i] > array[i + 1]) {
					swap_for_array(array, i, (i + 1));
				}
			}
		}
	}
}

void selection_sort(int* array, int length) {
	int min;
	int min_pos;
	for (int i = 0; i < length; i++) {
		min = array[i];
		min_pos = i;
		for (int m = (i + 1); m < length; m++) {
			if (min > array[m]) {
				min = array[m];
				min_pos = m;
			}
		}
		if (array[i] > array[min_pos]) {
			swap_for_array(array, i, min_pos);
		}
	}
}

void insertion_sort(int* array, int length) {
	int k;
	int card;
	for (int i = 1; i < length; i++) {
		card = array[i];
		k = i;
		while (array[k - 1] > card  && k >= 1) {
			array[k] = array[k - 1];
			k--;
		}
		array[k] = card;
	}
}

void quick_sort_Lomuto(int* array, int length){
	int pivot;
	pivot = array[length - 1];
	int m = (length - 2);
	for (int i = 0; i < m;) {
		if (array[i] < pivot && array[m] > pivot) {
			swap_for_array(array, i, m);
			i++;
			m--;
		} else if (array[i] < pivot && array[m] < pivot) {
			i++;
		} else if(array[i] > pivot && array[m] > pivot){
			m--;
		}
	}
	
}

void quick_sort_Hoare(int* array, int length) {

}

void print_array(int* array, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d  ", array[i]);
	}
	printf("\n");
}

void rand_numbers(int* array, int length) {
	for (int i = 0; i < length; i++) {
		array[i] = rand() % length;
	}
}

int main()
{
	double runtime;

	int array[1000];

	rand_numbers(array, 1000); //max. length = ca. 30.000

	//printf("Alt: ");
	//print_array(array, 1000);
	runtime = omp_get_wtime();
	merge_sort(array, 1000);
	runtime = omp_get_wtime() - runtime;
	//printf("Neu: ");
	//print_array(array, 1000);

	printf("Laufzeit: %f", runtime);
}