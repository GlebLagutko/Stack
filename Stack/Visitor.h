#pragma once
#include <string>

class Complex;

class Visitor {
public:
	virtual void visit(Complex&) = 0;
	virtual ~Visitor() = default;

};

class ToStringComplexVisitor : public Visitor {
	std::string str;
public:
	void visit(Complex& elem);



	ToStringComplexVisitor() : str("") {};


	std::string GetStr() const {
		return str;
	}

};

class ToStringVisitor : public Visitor {
private:
	std::string stackString;
public:

	ToStringVisitor() : stackString("") {};

	void visit(int elem);

	std::string GetString() const {
		return stackString;
	}
};
