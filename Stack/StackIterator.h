/*#pragma once
#include "Stack.h"
//
//
class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual int Currentltem() const = 0;
protected:
	Iterator();
};

class Stacklterator : public Iterator {
private:
    Stack* _stack;
	int current;
public:
	Stacklterator (Stack* aStack) {
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

	friend bool operator!=(const Stacklterator& lhs, const Stacklterator& rhs) {
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
*/
