
#pragma once
#include <iostream>
#include <stdexcept>
#include "StackIterator.h"

class Stack;

using namespace std;

class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual int Currentltem() const = 0;
protected:
	Iterator() {};
};

class Stacklterator : public Iterator {
private:
	Stack* _stack;
	int current;
public:
	Stacklterator(Stack* aStack) {
		_stack = aStack;
		current = 0;
	}

	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual int Currentltem() const;


	friend bool operator==(const Stacklterator& lhs, const Stacklterator& rhs) {
		return lhs._stack == rhs._stack
			&& lhs.current == rhs.current;
	}

	friend bool operator!=(const Stacklterator& lhs, const Stacklterator& rhs){
		return !(lhs == rhs);
	}


	friend void swap(Stacklterator& lhs, Stacklterator& rhs) {
		swap(lhs._stack, rhs._stack);
		swap(lhs.current, rhs.current);
	}
	
    Stacklterator& operator++ (int) {
		current++;
		return *this;
	}
};


class Stack
{
private:
	int* ptr;//указатель на массив
	int size;//размер массива
	int capacity;// количество элемнтов в стеке
	void resize();
	

public:
	
	Stack(int _size = 2) {
		size = _size;
		capacity = 0;
		ptr = new int[size];
	}

	Stack(const Stack& other)
		: size(other.size),
		capacity(other.capacity)	 
	{
		delete[] ptr;
		ptr = new int[capacity];
		for (int i = 0; i < size; i++)
			ptr[i] = other.ptr[i];

	}

	Stack(Stack&& other)
	:	size(other.size),
		capacity(other.capacity) 
	{
		delete[] ptr;
		ptr = new int[capacity];
		for (int i = 0; i < size; i++)
			ptr[i] = other.ptr[i];
		other.ptr = nullptr;
		other.size = 0;
		other.capacity = 0;
	}

	~Stack() {
		delete[] ptr;

	}

	void Swap(Stack& secondStack);

	//void resize();

	void Push(int element);

	int Top();

	bool IsEmpty();

	void Pop();

	int Size();

	void Clear();

	friend Stacklterator;


	Stack& operator=(const Stack& other) {
		if (this == &other)
			return *this;
		size = other.size;
		capacity = other.capacity;
		delete[] ptr;
		ptr = new int[capacity];
		for (int i = 0; i < size; i++)
			ptr[i] = other.ptr[i];
		return *this;
	}

	Stack& operator=(Stack&& other) {
		if (this == &other)
			return *this;
		size = other.size;
		capacity = other.capacity;
		delete[] ptr;
		ptr = new int[capacity];
		for (int i = 0; i < size; i++)
			ptr[i] = other.ptr[i];
		other.ptr = nullptr;
		other.size = 0;
		other.capacity = 0;
		return *this;
	}

	friend bool operator==(const Stack& lhs, const Stack& rhs) {
		return lhs.ptr == rhs.ptr
			&& lhs.size == rhs.size
			&& lhs.capacity == rhs.capacity;
	}

	friend bool operator!=(const Stack& lhs, const Stack& rhs) {
		return !(lhs == rhs);
	}
};





