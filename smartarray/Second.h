#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Second
{
	T* data;
	int size;
public:
	Second() : data(nullptr), size{ 0 } {}
	Second(int initialCapacity) : data(new T[initialCapacity]), size{ data->size() } {}
	Second(const Second& other) : data{ other.data }, size{ other.data->size() } {}
	~Second() {
		delete[] data;
	}

	T& operator[](int index) {
		if (index >= 0 && index <= size - 1) {
			return data[index];
		}
	}
	Second& operator=(const Second& other) {
		for (int i = 0; i < other.size; ++i) {
			data[i] = other.data[i];
		}
		return *this;
	}

	void push_back(const T& value) {
		data[data->size() - 1] = value;
	}
	void pop_back() {
		T* newData = new T[size - 2];

		for (int i = 0; i < size - 2; ++i) {
			newData[i] = this->data[i];
		}

		delete[] data;
		this->data = newData;
	}
	T& back() {
		return data[size - 1];
	}
	int size() const {
		return size;
	}
	bool empty() const {
		if (data != nullptr) {
			return false;
		}
		else
		{
			return true;
		}
	}
	void clear() {
		data = nullptr;
	}
	void insert(int index, const T& value) {
		data[index - 1] = value;
	}
	void erase(int index) {

	}
	int find(const T& value) {
		int index;
		for (int i = 0; i < size - 1; i++) {
			if (data[i] == value)
			{
				index = i;
			}
		}
		return index;
	}
};
