#pragma once
#include <iostream>
#include "Stack.h"
#include <stdexcept>
#include <string>

using namespace std;



void Stack::resize() {
	int newSize = capacity * 2;
	int* newStack = new int[newSize];

	for (int i = 0; i < capacity; ++i) {
		newStack[i] = ptr[i];
	}
	delete[] ptr;
	ptr = newStack;
	capacity = newSize;
}

void Stack::Push(int element) {
	if (size + 1 == capacity) {
		resize();
	}

	ptr[size++] = element;
}

int Stack::Top() {
	if (size <= 0) {
		throw std::out_of_range("ptr is empty");
	}
	else {
		return ptr[size - 1];
	}
}

void Stack::Pop() {
	if (size <= 0) {
		throw std::out_of_range("ptr is empty");
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

bool Stack::IsEmpty() {
	if (size <= 0)
		return true;
	else
		return false;

}

int Stack::Size() {
	return size;
}

void Stack::Clear() {
	int new_size = 20;
	delete[] ptr;
	ptr = new int[new_size];
	capacity = new_size;
	size = 0;
}

void Stack::Swap(Stack& secondStack) {
	//swap(*this, secondStack);
	swap(capacity, secondStack.capacity);
	swap(size, secondStack.size);
	swap(ptr, secondStack.ptr);
}

int Stack::CalcSum() {
	SumElementVisitor sum;
	Stacklterator iter(this);

	for(iter.First() ; !iter.IsDone() ; iter++) 
		sum.visit(iter.Currentltem());
	
	return sum.GetSum();
	
}


string Stack::ToString() {
	ToStringVisitor str;
	Stacklterator iter(this);

	for (iter.First(); !iter.IsDone(); iter++)
		str.visit(iter.Currentltem());
	return str.GetString();
}






/////////////////////////////////////////////
//VISITOR METHODS
/////////////////////////////////////////////

void SumElementVisitor::visit(int elem) {
	sum += elem;
}

void ToStringVisitor::visit(int elem) {
	stackString += to_string(elem) + " ";
}



/*void GetCapacity::visit(Stack& instance) {
	value = instance.GetSize();
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
	if (st1.GetSize() <= 0) {
		throw std::out_of_range("ptr is empty");
	}
	else {
		int * newStack = new int[st1.GetCapacity()];
		for (int i = 0; i < st1.GetSize() - 1; ++i) {
			newStack[i] = st1.GetPtr()[i];
		}
		delete[] st1.GetPtr();
		st1.SetPtr(newStack);
		--size;
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
