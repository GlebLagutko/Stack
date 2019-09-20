#include "Stack.h"


void Stacklterator::First() {
	current = 0;
}

void Stacklterator::Next() {
	current++;
}

bool Stacklterator::IsDone() const {
	return current >= _stack->capacity;
}

int Stacklterator::Currentltem() const {
	if (IsDone())
		throw std::out_of_range("Error");
	else
		return _stack->ptr[current];
}

