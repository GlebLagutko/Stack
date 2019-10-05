#pragma once
#include <iostream>
#include "List.h"
#include <stdexcept>
#include <string>
#include "Visitor.h"

using namespace std;



void List::resize() {
	int newSize = capacity * 2;
	Complex* newStack = new Complex[newSize];

	for (int i = 0; i < capacity; ++i) {
		newStack[i] = ptr[i];
	}
	delete[] ptr;
	ptr = newStack;
	capacity = newSize;
}

void List::PushBack(Complex& element) {
	if (size + 1 == capacity) {
		resize();
	}

	ptr[size++] = element;
}

void List::PushFront(Complex& element) {
	if (size + 2 == capacity) {
		resize();
	}
	Complex * newList = new Complex[capacity ];

	for (int i = 0; i < size ; ++i) {
		newList[i + 1] = ptr[i];
	}
	delete[] ptr;
	ptr = newList;

	ptr[0] = element;
	size++;

}


void List::PopFront() {
	if (size <= 0) {
		throw std::out_of_range("stack is empty");
	}
	else {
		Complex* newList = new Complex[capacity];
		for (int i = 1; i < size ; ++i) {
			newList[i -  1] = ptr[i];
		}
		delete[] ptr;
		ptr = newList;
		--size;
	}
}



int List::Size() {
	return size;
}



void List::Swap(List& secondList) {
	//swap(*this, secondList);
	swap(capacity, secondList.capacity);
	swap(size, secondList.size);
	swap(ptr, secondList.ptr);
}










