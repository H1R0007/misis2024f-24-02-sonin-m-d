#include <iostream>
#include <sstream>

class Complex {
public:

	double real;
	double image;

	Complex(double r = 0.0, double i = 0.0) : real(r), image(i) {}

	double GetR() const { return real; }
	double GetI() const { return image; }


	Complex& operator=(const Complex& other) { this->real = other.GetR(); this->image = other.GetI(); return *this;}
	bool operator==(const Complex& other) { return this->real == other.GetR() and this->image == other.GetI(); }
	bool operator!=(const Complex& other) { return this->real != other.GetR() and this->image != other.GetI(); }
	Complex& operator+(const Complex& other) { Complex answer; answer.real = this->real + other.GetR(); answer.image = this->image + other.GetI(); return answer;  }
	Complex& operator+=(const Complex& other) { this->real += other.GetR(); this->image += other.GetI(); return *this; }
	Complex& operator-(const Complex& other) { Complex answer; answer.real = this->real + other.GetR(); answer.image = this->image + other.GetI(); return answer; }
	Complex& operator-=(const Complex& other) { this->real -= other.GetR(); this->image -= other.GetI(); return *this; }
	Complex& operator*(const Complex& other) { Complex answer; answer.real = this->real * other.GetR() - this->image * other.GetI(); answer.image = this->real * other.GetI() + this->image * other.GetR(); return answer; }
	Complex& operator*=(const Complex& other) { double a1 = this->real * other.GetR() - this->image * other.GetI(); double a2 = this->real * other.GetI() + this->image * other.GetR(); this->real = a1; this->image = a2; return *this; }
	Complex& operator/(const Complex& other) { Complex answer; answer.real = (this->real * other.GetR() + this->image + other.GetI()) / (other.GetR() * other.GetR() + other.GetI() * other.GetI()); answer.image = (this->image * other.GetR() - this->real * other.GetI()) / (other.GetR() * other.GetR() + other.GetI() * other.GetI()); return answer; }
	Complex& operator/=(const Complex& other) { double a1 = other.GetR() * other.GetR() + other.GetI() * other.GetI(); double a2 = this->real * other.GetR() + this->image * other.GetI(); double a3 = this->image * other.GetI() - this->real * other.GetR(); this->real = a2 / a1; this->image = a3 / a1; return *this; }
	~Complex(){}
};

std::ostream& operator<<(std::ostream& enter, Complex& thing){
	enter << thing.real;
	if (thing.GetI() < 0.0){ enter << " - " << thing.GetI() * (-1) << "i"; }
	else{ enter << " + " << thing.GetI() << "i"; }
	return enter;
}
std::istream& operator>>(std::istream& output, Complex& thing){
	output >> thing.real >> thing.image;
	return output;
}
