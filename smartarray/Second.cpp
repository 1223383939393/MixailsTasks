#include "Second.h"

//template<typename T>
//Second<T>::~Second() {
//	delete[] data;
//}
//
//template<typename T>
//T& Second<T>::operator[](int index) {
//	if (index >= 0 && index <= size - 1) {
//		return data[index];
//	}
//}
//
//template<typename T>
//Second<T>& Second<T>::operator=(const Second& other) {
//	for (int i = 0; i < other.size; ++i) {
//		data[i] = other.data[i];
//	}
//	return *this;
//}
//
//template<typename T>
//void Second<T>::push_back(const T& value) {
//	data[data->size() - 1] = value;
//}
//
//template<typename T>
//void Second<T>::pop_back() {
//	T* newData = new T[size - 2];
//
//	for (int i = 0; i < size - 2; ++i) {
//		newData[i] = this->data[i];
//	}
//
//	delete[] data;
//	this->data = newData;
//}
//
//template<typename T>
//T& Second<T>::back() {
//	return data[size - 1];
//}
//
//
//
//template<typename T>
//bool Second<T>::empty() const {
//	if (data != nullptr) {
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//
//template<typename T>
//void Second<T>::clear() {
//	data = nullptr;
//}
//
//template<typename T>
//void Second<T>::insert(int index, const T& value) {
//	data[index - 1] = value;
//}
//
//template<typename T>
//void Second<T>::erase(int index) {
//
//}
//
//template<typename T>
//int Second<T>::find(const T& value) {
//	int index;
//	for (int i = 0; i < size - 1; i++) {
//		if (data[i] == value)
//		{
//			index = i;
//		}
//	}
//	return index;
//}