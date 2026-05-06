#pragma once
#include <iostream>
using namespace std;
class Array
{
	int* arr;
	int size;
public:
	
	Array(int num) {
		size = num;
		arr = new int[num];
	}

	Array() {
		size = 5;
		arr = new int[size];
	}

	void fillArray();
	void showArray();

	void changeSize(int num){
		delete[] arr;
		size = num;
		arr = new int[num];
	}

	void sortArray();

	void findMinNMaxArray();
	
	Array(const Array& obj)  : arr{obj.arr}, size{obj.size}
	{
		std::cout << "Fraction constructed for "
			<< this << '\n';
	}
	~Array() {
		delete[] arr;
		cout << "Array destructed for " << this << '\n';
	}
};

