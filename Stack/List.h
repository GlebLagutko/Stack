
#pragma once
#include <iostream>
#include <stdexcept>
#include "Complex.h"

class List;
class ElementInt;

using namespace std;




class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Complex& Currentltem() const = 0;
protected:
	Iterator() {};
};

class Listlterator : public Iterator {
private:
	List* _list;
	int current;
public:
	Listlterator(List* aStack) {
		_list = aStack;
		current = 0;
	}

	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual Complex& Currentltem() const;


	friend bool operator==(const Listlterator& lhs, const Listlterator& rhs) {
		return lhs.current == rhs.current;
	}

	friend bool operator!=(const Listlterator& lhs, const Listlterator& rhs){
		return !(lhs == rhs);
	}


	friend void swap(Listlterator& lhs, Listlterator& rhs) {
		swap(lhs._list, rhs._list);
		swap(lhs.current, rhs.current);
	}
	
    Listlterator& operator++ (int) {
		current++;
		return *this;
	}
	
	Listlterator& operator-- (int) {
		current--;
		return *this;
	}
};

class List
{
private:
	Complex* ptr;//указатель на массив
	int capacity;//размер массива
	int size;// количество элемнтов в стеке
	void resize();
	

public:
	
	List(int _size = 2) {
		capacity = _size;
		size = 0;
		ptr = new Complex[capacity];
	}

	List(const List& other)
		: capacity(other.capacity),
		size(other.size)	 
	{
		ptr = new Complex[size];
		for (int i = 0; i < capacity; i++)
			ptr[i] = other.ptr[i];

	}

	List(List&& other)
	:	capacity(other.capacity),
		size(other.size) 

	{
		ptr = new Complex[size];
		for (int i = 0; i < capacity; i++)
			ptr[i] = other.ptr[i];
		other.ptr = nullptr;
		other.capacity = 0;
		other.size = 0;
	}

	~List() {
		delete[] ptr;

	}

	

	void Swap(List& secondList);

	//void resize();

	void PushBack(Complex& element);

	void PushFront(Complex& element);

	void PopFront();

	int Size();



	Complex* GetPtr() const {
		return ptr;
	}

	void SetPtr(Complex* ptr)	{
		this->ptr = ptr;
	}

	int GetCapacity() const {
		return capacity;
	}



	int GetSize() const	{
		return size;
	}


	void Clear();

	friend Listlterator;
	friend Iterator;


	List& operator=(const List& other) {
		if (this == &other)
			return *this;
		capacity = other.capacity;
		size = other.size;
		delete[] ptr;
		ptr = new Complex[size];
		for (int i = 0; i < capacity; i++)
			ptr[i] = other.ptr[i];
		return *this;
	}

	List& operator=(List&& other) {
		if (this == &other)
			return *this;
		capacity = other.capacity;
		size = other.size;
		delete[] ptr;
		ptr = new Complex[size];
		for (int i = 0; i < capacity; i++)
			ptr[i] = other.ptr[i];
		other.ptr = nullptr;
		other.capacity = 0;
		other.size = 0;
		return *this;
	}

	friend bool operator==(const List& lhs, const List& rhs) {
		if (lhs.capacity != rhs.capacity) { return false; }
		if (lhs.size != rhs.size) { return false; }
		for (int i = 0; i < rhs.size; i++)
		{
			if (lhs.ptr[i] != rhs.ptr[i]) { return false; }
		}
		return true;
	}

	friend bool operator!=(const List& lhs, const List& rhs) {
		return !(lhs == rhs);
	}
};

