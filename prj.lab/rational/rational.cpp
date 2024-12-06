#include <rational/rational.hpp>
#include <iostream>
#include <stdexcept>
#include <math.h>

Rational::Rational(const std::int32_t chisl, const std::int32_t znam) : chisl_(chisl), znam_(znam) {
	if (znam_ == 0) {
		throw std::invalid_argument("Error, division by zero!");
	}
	Norm();
}

void Rational::Norm() noexcept {}

bool Rational::operator==(const Rational& right) const noexcept {
	return std::max(chisl_, right.chisl_) / std::min(chisl_, right.chisl_) == std::max(znam_, right.znam_) / std::min(znam_, right.znam_);
}

bool Rational::operator!=(const Rational& right) const noexcept {
	return !(operator==(Rational(right)));
}

bool Rational::operator>(const Rational& right) const noexcept {
	return chisl_ / znam_ > right.chisl_ / right.znam_;
}

bool Rational::operator<(const Rational& right) const noexcept {
	return chisl_ / znam_ < right.chisl_ / right.znam_;
}

bool Rational::operator>=(const Rational& right) const noexcept {
	return chisl_ / znam_ >= right.chisl_ / right.znam_;
}

bool Rational::operator<=(const Rational& right) const noexcept {
	return chisl_ / znam_ <= right.chisl_ / right.znam_;
}

Rational& Rational::operator+=(const Rational& right) noexcept {
	if (znam_ == right.znam_) {
		chisl_ += right.chisl_;
	}
	else {
		chisl_ = chisl_ * right.znam_ + right.chisl_ * znam_;
		znam_ = znam_ * right.znam_;
	}
	return *this;
}

Rational& Rational::operator+=(const std::int32_t right) {
	return operator+=(Rational(right));
 }

Rational& Rational::operator-=(const Rational& right) noexcept {
	if (znam_ == right.znam_) {
		chisl_ -= right.chisl_;
	}
	else {
		chisl_ = chisl_ * right.znam_ - right.chisl_ * znam_;
		znam_ = znam_ * right.znam_;
	}
	return *this;
}

Rational& Rational::operator-=(const std::int32_t right) {
	return operator-=(Rational(right));
}

Rational& Rational::operator*=(const Rational& right) noexcept {
	chisl_ *= right.chisl_;
	znam_ *= right.znam_;
	return *this;
}

Rational& Rational::operator*=(const std::int32_t right) {
	return operator*=(Rational(right));
}

Rational& Rational::operator/=(const Rational& right) {
	if (znam_ == 0) {
		throw std::runtime_error("Error, division by zero!");
	}
	else {
		chisl_ *= right.znam_;
		znam_ *= right.chisl_;
	}
	return *this;
 }

Rational& Rational::operator/=(const std::int32_t right) {
	return operator/=(Rational(right));
}

Rational operator+(const Rational& left, const Rational& right) noexcept { return Rational(left) += right; }
Rational operator+(const std::int32_t left, const Rational& right) noexcept { return Rational(left) += right; }
Rational operator+(const Rational& left, const std::int32_t right) noexcept { return Rational(left) += right; }

Rational operator-(const Rational& left, const Rational& right) noexcept { return Rational(left) -= right; }
Rational operator-(const std::int32_t left, const Rational& right) noexcept { return Rational(left) -= right; }
Rational operator-(const Rational& left, const std::int32_t right) noexcept { return Rational(left) -= right; }

Rational operator*(const Rational& left, const Rational& right) noexcept { return Rational(left) *= right; }
Rational operator*(const std::int32_t left, const Rational& right) noexcept { return Rational(left) *= right; }
Rational operator*(const Rational& left, const std::int32_t right) noexcept { return Rational(left) *= right; }

Rational operator/(const Rational& left, const Rational& right) { return Rational(left) /= right; }
Rational operator/(const std::int32_t left, const Rational& right) { return Rational(left) /= right; }
Rational operator/(const Rational& left, const std::int32_t right) { return Rational(left) /= right; }

std::istream& operator>>(std::istream& to, Rational& right) noexcept {
	std::int32_t chisl(0);
	std::int32_t znam(1);
	char sep(0);
	to >> chisl >> sep >> znam;
	if (to.good()) {
		if (Rational::Getsep() == sep) {
			if (znam < 0) {
				znam = -znam;
				chisl = -chisl;
			}
			if (znam == 0) {
				throw std::runtime_error("Error, division by zero!");
			}
			right.chisl(chisl);
			right.znam(znam);
		}
		else {
			to.setstate(std::ios_base::failbit);
		}
		return to;
	}
}

std::ostream& operator<<(std::ostream& out, const Rational& right) noexcept {
	if (right.Getchisl() == 0) {
		out << 0;
	}
	else {
		out << right.Getchisl() << right.Getsep() << right.Getznam();
	}
	return out;
}
//