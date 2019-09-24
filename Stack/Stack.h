
#pragma once
#include <iostream>
#include <stdexcept>

class Stack;
class ElementInt;

using namespace std;

class Visitor {
public:
	virtual void visit(int) = 0;
	virtual ~Visitor() = default;

};

class SumElementVisitor : public Visitor {
	int sum;
public:
	void visit(int elem);

	SumElementVisitor() : sum(0) {};


	int GetSum() const {
		return sum;
	}

};

class ToStringVisitor : public Visitor {
private:
	string stackString;
public :

	ToStringVisitor() : stackString("Current  : ") {};

	void visit(int elem);

	string GetString() const {
		return stackString;
	}
};



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
		return lhs.current == rhs.current;
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
	
	Stacklterator& operator-- (int) {
		current--;
		return *this;
	}
};

class Stack
{
private:
	int* ptr;//указатель на массив
	int capacity;//размер массива
	int size;// количество элемнтов в стеке
	void resize();
	

public:
	
	Stack(int _size = 2) {
		capacity = _size;
		size = 0;
		ptr = new int[capacity];
	}

	Stack(const Stack& other)
		: capacity(other.capacity),
		size(other.size)	 
	{
		ptr = new int[size];
		for (int i = 0; i < capacity; i++)
			ptr[i] = other.ptr[i];

	}

	Stack(Stack&& other)
	:	capacity(other.capacity),
		size(other.size) 

	{
		ptr = new int[size];
		for (int i = 0; i < capacity; i++)
			ptr[i] = other.ptr[i];
		other.ptr = nullptr;
		other.capacity = 0;
		other.size = 0;
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

	int CalcSum();

	string ToString();

	int* GetPtr() const {
		return ptr;
	}

	void SetPtr(int* ptr)	{
		this->ptr = ptr;
	}

	int GetCapacity() const {
		return capacity;
	}



	int GetSize() const	{
		return size;
	}


	void Clear();

	friend Stacklterator;
	friend Iterator;


	Stack& operator=(const Stack& other) {
		if (this == &other)
			return *this;
		capacity = other.capacity;
		size = other.size;
		delete[] ptr;
		ptr = new int[size];
		for (int i = 0; i < capacity; i++)
			ptr[i] = other.ptr[i];
		return *this;
	}

	Stack& operator=(Stack&& other) {
		if (this == &other)
			return *this;
		capacity = other.capacity;
		size = other.size;
		delete[] ptr;
		ptr = new int[size];
		for (int i = 0; i < capacity; i++)
			ptr[i] = other.ptr[i];
		other.ptr = nullptr;
		other.capacity = 0;
		other.size = 0;
		return *this;
	}

	friend bool operator==(const Stack& lhs, const Stack& rhs) {
		if (lhs.capacity != rhs.capacity) { return false; }
		if (lhs.size != rhs.size) { return false; }
		for (int i = 0; i < rhs.size; i++)
		{
			if (lhs.ptr[i] != rhs.ptr[i]) { return false; }
		}
		return true;
	}

	friend bool operator!=(const Stack& lhs, const Stack& rhs) {
		return !(lhs == rhs);
	}
};

