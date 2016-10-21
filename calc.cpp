#include "calc.h"

int calc(int lhs, char op, int rhs) {
	switch (op) {
	case '+':
		return lhs + rhs;
	case '*':
		return lhs * rhs;
	case '-':
		return lhs -rhs;
	case '/':
		if (rhs==0)
			throw std::invalid_argument{"division by zero"};
		return lhs / rhs;
	case '%':
		if (rhs==0)
			throw std::invalid_argument{"modulo by zero"};
		return lhs % rhs;
	default:
		throw std::invalid_argument{"invalid operator"};
	}
}

int calc(std::istream& in) {
	int lhs{};
	int rhs{};
	char op{};
	in >> lhs;
	in >> op;
	in >> rhs;
	return calc(lhs, op, rhs);
}
