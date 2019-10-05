#include <string>
#include "Complex.h"
#include "Visitor.h"

void ToStringComplexVisitor::visit(Complex& elem) {
	str = std::to_string(elem.GetReal()) + '+' + std::to_string(elem.GetImag()) + 'i';

}
