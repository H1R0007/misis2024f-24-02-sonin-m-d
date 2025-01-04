#include "complex.hpp"
#include <limits>
#include <iostream>

static const double epsilon = 2 * std::numeric_limits<double>::epsilon();

bool Complex::operator==(const Complex& right) noexcept
{
	return (abs(re - right.re < epsilon) && abs(im - right.im < epsilon));
}
bool Complex::operator!=(const Complex& right) noexcept
{
	return !(operator==(Complex(right)));
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

std::ostream& Complex::WriteToStream(std::ostream& Wtostream) const noexcept
{
	Wtostream << Lbrace << re << sep << im << Rbrace;
	return Wtostream;
}
std::istream& Complex::ReadFromStream(std::istream& Rfromstream) noexcept
{
	char Lbrace(0);
	char sep(0);
	char Rbrace(0);
	double imag(0.0);
	double real(0.0);
	Rfromstream >> Lbrace >> real >> sep >> imag >> Rbrace;
	if (Rfromstream.good()) {
		if ((Complex::Lbrace == Lbrace) && (Complex::sep == sep) && (Complex::Rbrace == Rbrace)) {
			re = real;
			im = imag;
		}
		else {
			Rfromstream.setstate(std::ios_base::failbit);
		}
	}
	return Rfromstream;
}

Complex operator+(const Complex& left, const Complex& right) noexcept { return Complex(left) += Complex(right); }
Complex operator+(const Complex& left, const double right) noexcept { return Complex(left) += Complex(right); }
Complex operator+(const double left, const Complex& right) noexcept { return Complex(left) += Complex(right); }

Complex operator-(const Complex& left, const Complex& right) noexcept { return Complex(left) -= Complex(right); }
Complex operator-(const Complex& left, const double right) noexcept { return Complex(left) -= Complex(right); }
Complex operator-(const double left, const Complex& right) noexcept { return Complex(left) -= Complex(right); }

Complex operator*(const Complex& left, const Complex& right) noexcept { return Complex(left) *= Complex(right); }
Complex operator*(const Complex& left, const double right) noexcept { return Complex(left) *= Complex(right); }
Complex operator*(const double left, const Complex& right) noexcept { return Complex(left) *= Complex(right); }

Complex operator/(const Complex& left, const Complex& right) { return Complex(left) /= Complex(right); }
Complex operator/(const Complex& left, const double right) { return Complex(left) /= Complex(right); }
Complex operator/(const double left, const Complex& right) { return Complex(left) /= Complex(right); }

//