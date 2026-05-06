#include <iostream>
#include "Array.h"

void Array::fillArray() {
	for (int i = 0; i < size; i++) {
		cout << "Write pls " << i << " element of array " << endl;
		cin >> arr[i];
	}
}
void Array::showArray() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Array::sortArray() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Array::findMinNMaxArray() {
	int min = 0, max = 0;
	for (int i = 1; i < size; i++) {
		if (arr[min] > arr[i]) {
			min = i;
		}
		if (arr[max] < arr[i]) {
			max = i;
		}
	}
	cout << "Min: " << arr[min] << endl;
	cout << "Max: " << arr[max] << endl;
}


int main()
{
    
}
