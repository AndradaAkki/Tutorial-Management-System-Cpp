#pragma once

#include <vector>

template <typename T>
class DynamicArray {
private:
	T* elems;
	int size;
	int capacity;
	
	void resize();
	friend class DynamicArrayIterator;
public:
	DynamicArray(int capacity = 10);
	DynamicArray(const DynamicArray& other);	// ALSO NEEDS copy constructor if we pass it (or return it) by value
	~DynamicArray();
	T* getElements(); //TODO: create and use iterator instead
	int getSize();
	void add(T elem);
	void remove(int pos);	
	T getElemOnPos(int pos);
	void update(int pos, T elem);
	
};

template<typename T>
DynamicArray<T>::DynamicArray(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) {
	this->size = other.size;
	this->capacity = other.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; ++i)
		this->elems[i] = other.elems[i];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] this->elems;
}

template<typename T>
void DynamicArray<T>::resize() {
	this->capacity *= 2;
	T* newElement = new T[this->capacity];
	for (int i = 0; i < this->size; ++i)
		newElement[i] = this->elems[i];

	delete[] this->elems;
	this->elems = newElement;
}

template<typename T>
void DynamicArray<T>::add(T elem) {
	if (this->size == this->capacity)
		resize();
	this->elems[this->size++] = elem;
}

template<typename T>
T* DynamicArray<T>::getElements() {
	return this->elems;
}

template<typename T>
int DynamicArray<T>::getSize() {
	return this->size;
}

template<typename T>
void DynamicArray<T>::remove(int pos) {
	for (int i = pos; i < this->size - 1; ++i)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}

template<typename T>
T DynamicArray<T>::getElemOnPos(int pos) {
	return this->elems[pos];
}

template<typename T>
void DynamicArray<T>::update(int pos, T elem) {
	this->elems[pos] = elem;
}