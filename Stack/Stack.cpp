#pragma once
#include <iostream>
#include "Stack.h"
#include <stdexcept>

using namespace std;

void Stack::accept(Visitor &instance) {
	instance.visit(*this);
}

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



/////////////////////////////////////////////
//VISITOR METHODS
/////////////////////////////////////////////

void Increase::visit(Stack& st) {

	int* a = st.GetPtr();
	for (int i = 0; i < st.GetCapacity(); i++)
		a[i]++;
}


/*void GetSize::visit(Stack& instance) {
	value = instance.GetCapacity();
}

/*void Clear::visit(Stack& instance)
{
	if (instance.GetArraySize() != 0)
	{
		delete[] instance.GetArray();
	}
	instance.SetArraySize(0);
	instance.SetElementQuantity(0);
}

void IsPresent::visit(Set& set_instance)
{
	for (int i = 0; i < set_instance.GetElementQuantity(); i++)
	{
		if (set_instance.GetArray()[i] == element_instance)
		{
			value = true;
			return;
		}
	}
	value = false;
}

void Pop::visit(Stack& st1)
{
	if (st1.GetCapacity() <= 0) {
		throw std::out_of_range("ptr is empty");
	}
	else {
		int * newStack = new int[st1.GetSize()];
		for (int i = 0; i < st1.GetCapacity() - 1; ++i) {
			newStack[i] = st1.GetPtr()[i];
		}
		delete[] st1.GetPtr();
		st1.SetPtr(newStack);
		--capacity;
	}
}

void Push::visit(Stack& set_instance)
{
	IsPresent is_present_visitor(element_instance);
	set_instance.accept(is_present_visitor);
	if (is_present_visitor.value) { return; }
	if (set_instance.GetElementQuantity() == set_instance.GetArraySize())
	{
		int* temporary_array = new int[set_instance.GetArraySize() * 2 + 1];
		for (int i = 0; i < set_instance.GetElementQuantity(); i++)
		{
			temporary_array[i] = set_instance.GetArray()[i];
		}
		auto swap_tmp_array = set_instance.GetArray();
		set_instance.SetArray(temporary_array);
		if (set_instance.GetArraySize() > 0) { delete swap_tmp_array; }
		set_instance.SetArraySize(set_instance.GetArraySize() * 2 + 1);
	}
	set_instance.GetArray()[set_instance.GetElementQuantity()] = element_instance;
	set_instance.SetElementQuantity(set_instance.GetElementQuantity() + 1);
}




void SwapSet::visit(Set& set_instance)
{
	auto tmp_array = other.GetArray();
	auto tmp_array_size = other.GetArraySize();
	auto tmp_element_quantity = other.GetElementQuantity();
	other.SetArray(set_instance.GetArray());
	other.SetArraySize(set_instance.GetArraySize());
	other.SetElementQuantity(set_instance.GetElementQuantity());
	set_instance.SetArray(tmp_array);
	set_instance.SetArraySize(tmp_array_size);
	set_instance.SetElementQuantity(tmp_element_quantity);
}
*/
