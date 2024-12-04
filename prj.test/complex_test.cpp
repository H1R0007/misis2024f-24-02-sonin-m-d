#include <complex/complex.hpp>
#include <iostream>
#include <sstream>

void static io_test() {
	Complex a, a1;
	std::ostringstream out;
	std::istringstream to("{8, 7}");
	out << a;
	to >> a1;
	if (out.str() == "{0, 0}" && a1.im == 7 && a1.re == 8) {
		std::cout << "Input success!" << std::endl;
		std::cout << "Output success!" << std::endl;
	}
}

void static plus_cc_test(Complex x, Complex y)
{
	Complex a(x.re + y.re, x.im + y.im);
	if (x + y == a) std::cout << x << " + " << y << " = " << a << std::endl;
}
void static plus_cd_test(Complex x, double y)
{
	Complex a(x.re + y, x.im);
	if (x + y == a) std::cout << x << " + " << y << " = " << a << std::endl;
}
void static plus_dc_test(double x, Complex y)
{
	Complex a(x + y.re, y.im);
	if (x + y == a) std::cout << x << " + " << y << " = " << a << std::endl;
}

void static min_cc_test(Complex x, Complex y)
{
	Complex a(x.re - y.re, x.im - y.im);
	if (x - y == a) std::cout << x << " - " << y << " = " << a << std::endl;
}
void static min_cd_test(Complex x, double y)
{
	Complex a(x.re - y, x.im);
	if (x - y == a) std::cout << x << " - " << y << " = " << a << std::endl;
}
void static min_dc_test(double x, Complex y)
{
	Complex a(x - y.re, y.im);
	if (x - y == a) std::cout << x << " - " << y << " = " << a << std::endl;
}

void static mult_cc_test(Complex x, Complex y)
{
	Complex a(x.re * y.re - x.im * y.im, x.re * y.im + x.im * y.re);
	if (x * y == a) std::cout << x << " * " << y << " = " << a << std::endl;
}
void static mult_cd_test(Complex x, double y)
{
	Complex a(x.re * y, x.im * y);
	if (x * y == a) std::cout << x << " * " << y << " = " << a << std::endl;
}
void static mult_dc_test(double x, Complex y)
{
	Complex a(x * y.re, x * y.im);
	if (x * y == a) std::cout << x << " * " << y << " = " << a << std::endl;
}

void static del_cc_test(Complex x, Complex y)
{
	double div = y.re * y.re + y.im * y.im;
	Complex a((x.re * y.re + x.im * y.im) / div, (x.im * y.re - x.re * y.im) / div);
	if (x / y == a) std::cout << x << " / " << y << " = " << a << std::endl;
}
void static del_cd_test(Complex x, double y)
{
	Complex a(x.re / y, x.im / y);
	if (x / y == a) std::cout << x << " / " << y << " = " << a << std::endl;
}
void static del_dc_test(double x, Complex y)
{
	Complex a(x);
	double div = y.re * y.re + y.im * y.im;
	a = { (a.re * y.re + a.im * y.im) / div, (a.im * y.re - a.re * y.im) / div };
	if (x / y == a) std::cout << x << " / " << y << " = " << a << std::endl;
}

void static otric_test(Complex x) 
{
	Complex a(-x.re, -x.im);
	if (a == -x) std::cout << x << " => " << a << std::endl;
}

void static identific_test(Complex x)
{
	Complex a = x;
	if (a == x) std::cout << x << " = " << a << std::endl;
}

void static ravn_cc_test(Complex x, Complex y)
{
	if (x == y) std::cout << x << " == " << y << std::endl;
}

void static NEravn_cc_test(Complex x, Complex y)
{
	if (x != y) std::cout << x << " != " << y << std::endl;
}

int main() {
	Complex x(2.2, -8.6);
	Complex y(-3.0, -8.9);
	double z = 7.3;

	io_test();

	min_cc_test(x, y);
	min_cd_test(x, z);
	min_dc_test(z, x);

	plus_cc_test(x, y);
	plus_cd_test(x, z);
	plus_dc_test(z, x);

	mult_cc_test(x, y);
	mult_cd_test(x, z);
	mult_dc_test(z, x);

	del_cc_test(x, y);
	del_cd_test(x, z);
	del_dc_test(z, x);

	otric_test(x);
	otric_test(y);

	identific_test(x);
	identific_test(y);

	ravn_cc_test(x, y);
	NEravn_cc_test(x, y);


	y = {0, 0};
	try {
		x / y;
	}
	catch (std::runtime_error) {
		std::cout << "Error, division by zero!" << std::endl;
	}
	return 0;
}
