#pragma once
#include <iostream>
#include "Stack.h"
#include <stdexcept>

using namespace std;

void Stack::resize() {
	int newSize = size * 2;
	int* newStack = new int[newSize];

	for (int i = 0; i < size; ++i) {
		newStack[i] = ptr[i];
	}
	delete[] ptr;
	ptr = newStack;
	size = newSize;
}

void Stack::Push(int element) {
	if (capacity + 1 == size) {
		resize();
	}

	ptr[capacity++] = element;
}

int Stack::Top() {
	if (capacity <= 0) {
		throw std::out_of_range("ptr is empty");
	}
	else {
		return ptr[capacity - 1];
	}
}

void Stack::Pop() {
	if (capacity <= 0) {
		throw std::out_of_range("ptr is empty");
	}
	else {
		int * newStack = new int[size];
		for (int i = 0; i < capacity - 1; ++i) {
			newStack[i] = ptr[i];
		}
		delete[] ptr;
		ptr = newStack;
		--capacity;

	}
}

bool Stack::IsEmpty() {
	if (capacity <= 0)
		return true;
	else
		return false;

}

int Stack::Size() {
	return capacity;
}

void Stack::Clear() {
	int new_size = 20;
	delete[] ptr;
	ptr = new int[new_size];
	size = new_size;
	capacity = 0;
}

void Stack::Swap(Stack& secondStack) {
	//swap(*this, secondStack);
	swap(size, secondStack.size);
	swap(capacity, secondStack.capacity);
	swap(ptr, secondStack.ptr);
}


