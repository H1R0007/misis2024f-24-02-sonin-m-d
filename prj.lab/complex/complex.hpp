#ifndef COMPLEX_H
#define COMPLEX_H

#include <iosfwd>

struct Complex {
	//конструктор по умолчанию
	Complex() = default;

	//конструктор копирования по умолчанию
	Complex(const Complex&) = default;

	//констрктор перемещения по умолчанию
	Complex(Complex&&) = default;

	//деструктор по умолчанию
	~Complex() = default;

	//конструкторы

	double re{ 0.0 };
	double im{ 0.0 };

	Complex(const double real, const double imaginary) : re(real), im(imaginary) { }

	explicit Complex(const double real) : re(real) { }

	Complex& operator=(const Complex&) = default;
	Complex& operator=(Complex&&) = default;

	//пергрузка операторов
	Complex& operator+=(const Complex& right) noexcept;
	Complex& operator+=(const double right) noexcept;

	Complex& operator-=(const Complex& right) noexcept;
	Complex& operator-=(const double right) noexcept;

	Complex& operator*=(const Complex& right) noexcept;
	Complex& operator*=(const double right) noexcept;

	Complex& operator/=(const Complex& right);
	Complex& operator/=(const double right);

	[[nodiscard]] Complex operator-() const noexcept { return Complex(-re, -im); }
	[[nodiscard]] bool operator==(const Complex& right) noexcept;
	[[nodiscard]] bool operator!=(const Complex& right) noexcept;

	[[nodicard]] std::ostream& WriteToStream(std::ostream& Wtostream) const noexcept;
	[[nodicard]] std::istream& ReadFromStream(std::istream& Rfromstream) noexcept;

	static const char Lbrace{ '{' };
	static const char sep{ ',' };
	static const char Rbrace{ '}' };
};

[[nodiscard]] Complex operator+(const Complex& left, const Complex& right) noexcept;
[[nodiscard]] Complex operator+(const Complex& left, const double right) noexcept;
[[nodiscard]] Complex operator+(const double left, const Complex& right) noexcept;

[[nodiscard]] Complex operator-(const Complex& left, const Complex& right) noexcept;
[[nodiscard]] Complex operator-(const Complex& left, const double right) noexcept;
[[nodiscard]] Complex operator-(const double left, const Complex& right) noexcept;

[[nodiscard]] Complex operator*(const Complex& left, const Complex& right) noexcept;
[[nodiscard]] Complex operator*(const Complex& left, const double right) noexcept;
[[nodiscard]] Complex operator*(const double left, const Complex& right) noexcept;

Complex operator/(const Complex& left, const Complex& right);
Complex operator/(const Complex& left, const double right);
Complex operator/(const double left, const Complex& right);

inline std::ostream& operator<<(std::ostream& Wtostream, const Complex& right) noexcept {
	return right.WriteToStream(Wtostream);
}

inline std::istream& operator>>(std::istream& Rfromstream, Complex& right) noexcept {
	return right.ReadFromStream(Rfromstream);
}
#endif //