#include <rational/rational.hpp>
#include <iostream>
#include <stdexcept>
#include <math.h>

// наибольший общий делитель
int32_t static GCD(const int32_t left, const int32_t right) noexcept {
	if (left % right == 0) {
		return right;
	}
	if (right % left == 0) {
		return left;
	}
	if (left > right) {
		return GCD(left % right, right);
	}
	return GCD(left, right % left);
}

int32_t static LCM(const int32_t left, const int32_t right) noexcept {
	return (left * right) / GCD(left, right);
}

void Rational::DoRightSign() noexcept {
	if (znam_ < 0) {
		znam_ = -znam_;
		chisl_ = -chisl_;
	}
	return;
}

void Rational::FractionReduce() noexcept {
	int32_t gcd = GCD(std::abs(chisl_), znam_);
	if (gcd != 1) {
		chisl_ /= gcd;
		znam_ /= gcd;
	}
	return;
}

Rational::Rational(const std::int32_t chisl, const std::int32_t znam) : chisl_(chisl), znam_(znam) {
	if (znam_ == 0) {
		throw std::invalid_argument("Error, division by zero!");
	}
	DoRightSign();
	FractionReduce();
}

bool Rational::operator==(const Rational& right) const noexcept {
	return chisl_ == right.chisl_ && znam_ == right.znam_;
}

bool Rational::operator!=(const Rational& right) const noexcept {
	return !(operator==(right));
}

bool Rational::operator==(const int32_t right) const noexcept {
	return operator==(Rational(right));
}

bool Rational::operator!=(const int32_t right) const noexcept {
	return operator!=(Rational(right));
}

bool Rational::operator<(const Rational& right) const noexcept {
	return chisl_ * right.znam_ < right.chisl_ * znam_;
}

bool Rational::operator<(const int32_t right) const noexcept {
	return operator<(Rational(right));
}

bool Rational::operator<=(const Rational& right) const noexcept {
	return operator<(right) || operator==(right);
}

bool Rational::operator<=(const int32_t right) const noexcept {
	return operator<=(Rational(right));
}

bool Rational::operator>(const Rational& right) const noexcept {
	return chisl_ * right.znam_ > right.chisl_ * znam_;
}

bool Rational::operator>(const int32_t right) const noexcept {
	return operator>(Rational(right));
}

bool Rational::operator>=(const Rational& right) const noexcept {
	return operator>(right) || operator==(right);
}

bool Rational::operator>=(const int32_t right) const noexcept {
	return operator>=(Rational(right));
}

Rational& Rational::operator+=(const Rational& right) noexcept {
	if (znam_ == right.znam_) {
		chisl_ += right.chisl_;
	}
	else {
		int32_t lcm = LCM(znam_, right.znam_);
		chisl_ = chisl_ * (lcm / znam_) + right.chisl_ * (lcm / right.znam_);
		znam_ = lcm;
	}
	FractionReduce(); // Убеждаемся, что результат упрощен
	return *this;
}

Rational& Rational::operator-=(const Rational& right) noexcept {
	return operator+=(-1 * right);
}

Rational& Rational::operator*=(const Rational& right) noexcept {
	chisl_ *= right.chisl_;
	znam_ *= right.znam_;
	FractionReduce();
	return *this;
}

Rational& Rational::operator/=(const Rational& right) {
	if (right.znam_ == 0) {
		throw std::runtime_error("Error, division by zero!");
	}
	chisl_ *= right.znam_;
	znam_ *= right.chisl_;
	DoRightSign();
	FractionReduce();
	return *this;
 }

Rational operator+(const Rational& left, const Rational& right) noexcept { Rational sum = left; sum += right; return sum; }
[[nodiscrd]] Rational operator+(const std::int32_t left, const Rational& right) noexcept { return Rational(left) + right; }
[[nodiscrd]] Rational operator+(const Rational& left, const std::int32_t right) noexcept { return left + Rational(right); }

Rational operator-(const Rational& left, const Rational& right) noexcept { Rational razn = left; razn -= right; return razn; }
[[nodiscrd]] Rational operator-(const std::int32_t left, const Rational& right) noexcept { return Rational(left) - right; }
[[nodiscrd]] Rational operator-(const Rational& left, const std::int32_t right) noexcept { return left - Rational(right); }

Rational operator*(const Rational& left, const Rational& right) noexcept { Rational proiz = left; proiz *= right; return proiz; }
[[nodiscrd]] Rational operator*(const std::int32_t left, const Rational& right) noexcept { return Rational(left) * right; }
[[nodiscrd]] Rational operator*(const Rational& left, const std::int32_t right) noexcept { return left * Rational(right); }

Rational operator/(const Rational& left, const Rational& right) { Rational chast = left; chast /= right; return chast; }
[[nodiscrd]] Rational operator/(const std::int32_t left, const Rational& right) { return Rational(left) / right; }
[[nodiscrd]] Rational operator/(const Rational& left, const std::int32_t right) { return left / Rational(right); }

std::istream& Rational::ReadFromstream(std::istream& istrm) noexcept {
	int32_t chisl = 0;
	char sep = 0;
	int32_t znam = 1;
	istrm >> chisl;
	istrm.get(sep);
	int32_t trash = istrm.peek();
	istrm >> znam;
	if (!istrm || trash > '9' || trash < '0') {
		istrm.setstate(std::ios_base::failbit);
		return istrm;
	}
	if (istrm.good() || istrm.eof()) {
		if ('/' == sep && znam > 0) {
			*this = Rational(chisl, znam);
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

std::ostream& Rational::WriteTostream(std::ostream& ostrm) const noexcept {
	ostrm << chisl_ << sep_ << znam_;
	return ostrm;
}
//