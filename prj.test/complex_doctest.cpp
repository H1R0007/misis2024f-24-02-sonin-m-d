#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <complex/complex.hpp>
#include "doctest.h"

bool read_test(const std::string& str) noexcept {
    std::istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good() || istrm.eof()) {
        std::cout << "Read Success: ";
    }
    else {
        std::cout << "Read Error: ";
    }
    std::cout << "read " << z << " from " << str << '\n';
    return istrm.good();
}
bool areEqual(int a, int b) {
    return a == b;
}
bool areNotEqual(int a, int b) {
    return a != b;
}

TEST_CASE("complex input") {
    CHECK(read_test("{1,2}"));
    CHECK(read_test("{1.2, 2.3}"));
    CHECK(read_test("{-1.2, 2.3}"));
    CHECK(read_test("{1.2,2.3}"));
    CHECK(read_test("{-1.2,2.3}"));
    CHECK(read_test("{1.2 ,2.3}"));
    CHECK(read_test("{-1.2 ,2.3}"));
    CHECK(read_test("{1.2 , 2.3}"));
    CHECK(read_test("{-1.2 , 2.3}"));
    CHECK(read_test("{ 1.2 , 2.3 }"));
    CHECK(read_test(" {1.2,  2.3} "));
    CHECK(read_test(" {1.2  ,2.3} "));
    CHECK(read_test(" {-  1.2,2.3} ") == false);
}

TEST_CASE("Equality Tests") {
    CHECK(areEqual(5, 5) == true);  // Проверка равенства 5 == 5
    CHECK(areEqual(10, 15) == false);  // Проверка равенства 10 == 15 (ожидается false)
    CHECK(areEqual(-1, -1) == true);  // Проверка равенства -1 == -1
}

TEST_CASE("Inequality Tests") {
    CHECK(areNotEqual(5, 10) == true);  // Проверка неравенства 5 != 10
    CHECK(areNotEqual(7, 7) == false);  // Проверка неравенства 7 != 7 (ожидается false)
    CHECK(areNotEqual(-1, -1) == false);  // Проверка неравенства -1 != -1 (ожидается false)
}

TEST_CASE("Complex number addition") {
    Complex a(3.0, 4.0);
    Complex b(1.0, 2.0);
    Complex result = a + b;
    CHECK(result == Complex(4.0, 6.0));
}

TEST_CASE("Complex number multiplication") {
    Complex a(2.0, 3.0);
    Complex b(4.0, 5.0);
    Complex result = a * b;
    CHECK(result == Complex(-7.0, 22.0));
}

TEST_CASE("Division by zero throws exception") {
    Complex a(3.0, 4.0);
    Complex zero(0.0, 0.0);
    CHECK_THROWS(a / zero);
}



