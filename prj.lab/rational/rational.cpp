#import <iostream>
#import <sstream>

struct Fractional
{
	double chisl;
	double znam;
	
	Fractional(double ch = 0.0, double zn = 0.0) : chisl(ch), znam(zn);

	double GetC() const { return chisl; }
	double GetZ() const { return znam; }

	Fractional& operator=(const Fractional& other) {this->chisl = other.chisl; this->znam = other.znam; return *this; }
	bool operator==(const Fractional& other) { return this->chisl == other.chisl && this->znam == other.znam; }
	bool operator!=(const Fractional& other) { return !(this->chisl == other.chisl && this->znam == other.znam); }
	Fractional operator+(const Fractional& other) { Fractional temp; double numerator = this->chisl, denominator = this->znam; tem = numerator * other.znam + denominator * other. temp.znam = denominator * other.znam; return temp; }
	Fractional operator-(const Fractional& other) { Fractional temp; double numerator = this->chisl, denominator = this->znam; temp.chisl = numerator * other.znam - denominator * other.nr;temp.znam = denominator * other.znam; return temp; }
	Fractional operator*(const Fractional& other) { Fractional temp; double numerator = this->chisl, denominator = this->znam; temp.chisl = numerator * other.chisl; temp.znam = denominator * other.znam; return temp; }
	Fractional operator/(const Fractional& other) { Fractional temp; double numerator = this->chisl, denominator = this->znam; temp.chisl = numerator * other.znam;temp.znam = denominator * other.chisl; return temp; }
	Fractional& operator+=(const Fractional& other) { double numerator = this->chisl, denominator = this->znam; this->nr = numerator * other.znam + denominator * other.chisl; this->znam = denominator * other.znam; return *this; }
	Fractional& operator-=(const Fractional& other) { double numerator = this->chisl, denominator = this->znam; this->chisl = numerator * other.znam - denominator * other.chisl;this->znam = denominator * other.znam; return *this; }
	Fractional& operator*=(const Fractional& other) { double numerator = this->chisl, denominator = this->znam; this->chisl = numerator * other.chisl; this->znam = denominator * other.znam; return *this; }
	Fractional& operator/=(const Fractional& other) { double numerator = this->chisl, denominator = this->znam; this->chisl = numerator * other.znam; this->znam = denominator * other.chisl; return *this; }
	~Fractional(){ }
};

std::ostream& operator<<(std::ostream& os, Fractional& number)
{
	if (number.znam == 0)
	{
		os << number.chisl << "/" << number.znam << "Деление на ноль!";
	}
	else
	{
		os << number.chisl << "/" << number.znam << " = " << number.nr / number.znam;
	}
	return os;
}
std::istream& operator>>(std::istream& is, Fractional& number)
{
	is >> number.chisl >> number.znam;
	return is;
}
