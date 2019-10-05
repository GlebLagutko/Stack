#include "List.h"


void Listlterator::First() {
	current = 0;
}

void Listlterator::Next() {
	current++;
}

bool Listlterator::IsDone() const {
	return current >= _list->size;
}

Complex& Listlterator::Currentltem() const {
	if (IsDone())
		throw std::out_of_range("Error");
	else
		return _list->ptr[current];
}

