#include "complex.hpp"
#include <limits>
#include <iostream>

bool Complex::operator==(const Complex& right) const noexcept
{
	double constexpr O = std::numeric_limits<double>::epsilon();
	return (abs(re - right.re < 2 * O) && abs(im - right.im < 2 * O));
}
bool Complex::operator!=(const Complex& right) const noexcept
{
	return !(operator==(Complex(right)));
}

Complex Complex::operator-() const noexcept
{
	return Complex(-re, -im);
}

Complex& Complex::operator+=(const Complex& right) noexcept
{
	re += right.re;
	im += right.im;
	return *this;
}
Complex& Complex::operator+=(const double right) noexcept
{
	return operator+=(Complex(right));
}

Complex& Complex::operator-=(const Complex& right) noexcept
{
	re -= right.re;
	im -= right.im;
	return *this;
}
Complex& Complex::operator-=(const double right) noexcept
{
	return operator-=(Complex(right));
}

Complex& Complex::operator*=(const Complex& right) noexcept
{
	re = re * right.re - im * right.im;
	im = re * right.im + im * right.re;
	return *this;
}
Complex& Complex::operator*=(const double right) noexcept
{
	re *= right;
	im *= right;
	return *this;
}

Complex& Complex::operator/=(const Complex& right)
{
	if (right.re + right.im == 0.0)
	{
		throw std::runtime_error("Error, division by zero!");
	}
	re = (re * right.re + im * right.im) / (right.re * right.re + right.im * right.im);
	im = (im * right.re - re * right.im) / (right.re * right.re + right.im * right.im);
	return *this;
}
Complex& Complex::operator/=(const double right)
{
	if (right == 0.0)
	{
		throw std::runtime_error("Error, division by zero!");
	}
	re /= right;
	im /= right;
	return *this;
}

std::ostream& Complex::Out(std::ostream& out) const noexcept
{
	out << Lbrace << re << sep << space << im << Rbrace;
	return out;
}
std::istream& Complex::To(std::istream& to) noexcept
{
	char Lbrace(0);
	char sep(0);
	char space(0);
	char Rbrace(0);
	double imag(0.0);
	double real(0.0);
	to >> Lbrace >> real >> sep >> space >> imag >> Rbrace;
	if (to.good()) {
		if ((Complex::Lbrace == Lbrace) && (Complex::sep == sep) && (Complex::space == space) && (Complex::Rbrace == Rbrace)) {
			re = real;
			im = imag;
		}
		else {
			to.setstate(std::ios_base::failbit);
		}
	}
	return to;
}


Complex operator+(const Complex& left, const Complex& right) noexcept { return Complex(left) += right; }
Complex operator+(const Complex& left, const double right) noexcept { return Complex(left) += right; }
Complex operator+(const double left, const Complex& right) noexcept { return Complex(left) += right; }

Complex operator-(const Complex& left, const Complex& right) noexcept { return Complex(left) -= right; }
Complex operator-(const Complex& left, const double right) noexcept { return Complex(left) -= right; }
Complex operator-(const double left, const Complex& right) noexcept { return Complex(left) -= right; }

Complex operator*(const Complex& left, const Complex& right) noexcept { return Complex(left) *= right; }
Complex operator*(const Complex& left, const double right) noexcept { return Complex(left) *= right; }
Complex operator*(const double left, const Complex& right) noexcept { return Complex(left) *= right; }

Complex operator/(const Complex& left, const Complex& right) { return Complex(left) /= right; }
Complex operator/(const Complex& left, const double right) { return Complex(left) /= right; }
Complex operator/(const double left, const Complex& right) { return Complex(left) /= right; }
