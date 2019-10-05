#pragma once

class Complex{
private :
	int real;
	int imag;
public:

	Complex() {}

	Complex(int real,int imag) : real(real),imag(imag) {}

	int GetReal() const
	{
		return real;
	}

	void SetReal(int real)
	{
		this->real = real;
	}

	int GetImag() const
	{
		return imag;
	}

	void SetImag(int inmag)
	{
		this->imag = inmag;
	}

	Complex& operator=(const Complex& other) {
		if (this == &other)
			return *this;
		imag = other.imag;
		real = other.real;
		return *this;
	}

	Complex& operator=(Complex&& other) {
		if (this == &other)
			return *this;
		imag = other.imag;
		real = other.real;
		other.imag = 0;
		other.real = 0;
		
		return *this;
	}

	friend bool operator==(const Complex& lhs, const Complex& rhs)
	{
		return lhs.real == rhs.real
			&& lhs.imag == rhs.imag;
	}

	friend bool operator!=(const Complex& lhs, const Complex& rhs)
	{
		return !(lhs == rhs);
	}
};
