#pragma once
#include <iostream>
#include "List.h"
#include <stdexcept>
#include <string>
#include "Visitor.h"

using namespace std;



void List::resize() {
	int newSize = capacity * 2;
	int* newStack = new int[newSize];

	for (int i = 0; i < capacity; ++i) {
		newStack[i] = ptr[i];
	}
	delete[] ptr;
	ptr = newStack;
	capacity = newSize;
}

void List::Push(int element) {
	if (size + 1 == capacity) {
		resize();
	}

	ptr[size++] = element;
}

int List::Top() {
	if (size <= 0) {
		throw std::out_of_range("stack is empty");
	}
	else {
		return ptr[size - 1];
	}
}

void List::Pop() {
	if (size <= 0) {
		throw std::out_of_range("stack is empty");
	}
	else {
		int * newStack = new int[capacity];
		for (int i = 0; i < size - 1; ++i) {
			newStack[i] = ptr[i];
		}
		delete[] ptr;
		ptr = newStack;
		--size;
	}
}

bool List::IsEmpty() {
	if (size <= 0)
		return true;
	else
		return false;

}

int List::Size() {
	return size;
}

void List::Clear() {
	int new_size = 20;
	delete[] ptr;
	ptr = new int[new_size];
	capacity = new_size;
	size = 0;
}

void List::Swap(List& secondStack) {
	//swap(*this, secondStack);
	swap(capacity, secondStack.capacity);
	swap(size, secondStack.size);
	swap(ptr, secondStack.ptr);
}

int List::CalcSum() {
	SumElementVisitor sum;
	Listlterator iter(this);

	for(iter.First() ; !iter.IsDone() ; iter++) 
		sum.visit(iter.Currentltem());
	
	return sum.GetSum();
	
}


string List::ToStringTop() {
	ToStringVisitor str;
	Listlterator iter(this);

	for (iter.First(); !iter.IsDone(); iter++)
		str.visit(iter.Currentltem());
	return str.GetString();
}






