#pragma once
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iosfwd>
#include <cstdint>

class Rational
{
private:
	std::int32_t chisl_ = 0;
	std::int32_t znam_ = 1;
	static const char sep_ = '/';

	void static Norm() noexcept;


public:
	Rational() = default;

	Rational(const Rational&) = default;

	Rational(const std::int32_t chisl, const std::int32_t znam);

	explicit Rational(const std::int32_t chisl) noexcept : chisl_(chisl) {}

	Rational(Rational&&) = default;
	Rational& operator=(Rational&&) = default;

	Rational& operator=(const Rational&) = default;

	~Rational() = default;

	[[nodiscard]] std::int32_t Getchisl() const noexcept { return chisl_; }
	[[nodiscard]] std::int32_t Getznam() const noexcept { return znam_; }
	[[nodiscard]] static char Getsep() { return sep_; }
	[[nodiscard]] void chisl(std::int32_t chisl) { chisl_ = chisl; }
	[[nodiscard]] void znam(std::int32_t znam) { znam_ = znam; }

	[[nodiscard]] bool operator==(const Rational& right) const noexcept;
	[[nodiscard]] bool operator==(const int32_t rhs) const noexcept;
	[[nodiscard]] bool operator!=(const Rational& right) const noexcept;
	[[nodiscard]] bool operator!=(const int32_t rhs) const noexcept;
	[[nodiscard]] bool operator<(const Rational& right) const noexcept;
	[[nodiscard]] bool operator<(const int32_t rhs) const noexcept;
	[[nodiscard]] bool operator>(const Rational& right) const noexcept;
	[[nodiscard]] bool operator>(const int32_t rhs) const noexcept;
	[[nodiscard]] bool operator>=(const Rational& right) const noexcept;
	[[nodiscard]] bool operator>=(const int32_t rhs) const noexcept;
	[[nodiscard]] bool operator<=(const Rational& right) const noexcept;
	[[nodiscard]] bool operator<=(const int32_t rhs) const noexcept;

	[[nodiscard]] Rational& operator+=(const Rational& right) noexcept;
	[[nodiscard]] Rational& operator-=(const Rational& right) noexcept;
	[[nodiscard]] Rational& operator*=(const Rational& right) noexcept;
	[[nodiscard]] Rational& operator/=(const Rational& right);

	[[nodiscard]] Rational& operator+=(const std::int32_t right) noexcept { return operator+=(Rational(right)); }
	[[nodiscard]] Rational& operator-=(const std::int32_t right) noexcept { return operator-=(Rational(right)); }
	[[nodiscard]] Rational& operator*=(const std::int32_t right) noexcept { return operator*=(Rational(right)); };
	[[nodiscard]] Rational& operator/=(const std::int32_t right) { return operator/=(Rational(right)); }

	[[nodiscard]] Rational operator-() const noexcept { return { -chisl_, -znam_ }; }

	std::ostream& WriteTostream(std::ostream& Wtostream) const noexcept;
	std::istream& ReadFromstream(std::istream& Rfromstream) noexcept;
};

[[nodiscard]] Rational operator+(const Rational& left, const Rational& right) noexcept;
[[nodiscard]] Rational operator+(const Rational& left, const int32_t right) noexcept;
[[nodiscard]] Rational operator+(const int32_t left, const Rational& right) noexcept;

[[nodiscard]] Rational operator*(const Rational& left, const Rational& right) noexcept;
[[nodiscard]] Rational operator*(const Rational& left, const int32_t right) noexcept;
[[nodiscard]] Rational operator*(const int32_t left, const Rational& right) noexcept;

[[nodiscard]] Rational operator-(const Rational& left, const Rational& right) noexcept;
[[nodiscard]] Rational operator-(const Rational& left, const int32_t right) noexcept;
[[nodiscard]] Rational operator-(const int32_t left, const Rational& right) noexcept;

[[nodiscard]] Rational operator/(const Rational& left, const Rational& right);
[[nodiscard]] Rational operator/(const Rational& left, const int32_t right);
[[nodiscard]] Rational operator/(const int32_t left, const Rational& right);

inline static std::ostream& operator<<(std::ostream& Wtostream, const Rational& right) noexcept {
	return right.WriteTostream(Wtostream);
}

inline static std::istream& operator>>(std::istream& Rfromstream, Rational& right) noexcept {
	return right.ReadFromstream(Rfromstream);
}

#endif //