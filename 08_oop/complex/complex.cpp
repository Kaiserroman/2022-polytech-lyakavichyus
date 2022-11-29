#include "complex.h"
#include <cmath>
#include "doctest.h"

const Complex Complex::operator+(const Complex rv) const { //описываем оператор сложения
	return Complex(r_part + rv.r_part, i_part + rv.i_part);
}
const Complex Complex::operator-(const Complex rv) const { //описываем оператор вычитания
	return Complex(r_part - rv.r_part, i_part - rv.i_part);
}

const bool Complex::operator==(const Complex rv) const { //описываем оператор сравнения
	return r_part == rv.r_part && i_part == rv.i_part;
}

const double Complex::abs() const {
	return sqrt(r_part * r_part + i_part * i_part); //описываем оператор модуля
}