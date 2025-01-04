#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <rational/rational.hpp>

bool read_test(const std::string& str) {
    std::istringstream istrm(str);
    Rational q;
    istrm >> q;
    bool stream_good = !istrm.fail() || (istrm.eof() && !istrm.fail());
    if (stream_good) {
        std::cout << "Read success: " << str << " -> " << q << '\n';
    }
    else {
        std::cout << "Read error : " << str << " -> " << q << '\n';
    }
    return stream_good;
}
TEST_CASE("rational input") {
    CHECK(read_test("1/0") == false);
    CHECK(read_test("1/2"));
    CHECK(read_test(" 1/2"));
    CHECK(read_test("1/2 "));
    CHECK(read_test(" 1/2 "));
    CHECK(read_test(" 1 /2 ") == false);
    CHECK(read_test(" 1/ 2 ") == false);
}

TEST_CASE("Testing the constructor and exceptions") {
    Rational r_def;
    CHECK(0 == r_def.Getchisl());
    CHECK(1 == r_def.Getznam());

    Rational r_int(3);
    CHECK(3 == r_int.Getchisl());
    CHECK(1 == r_int.Getznam());

    CHECK_THROWS(Rational(1, 0));
    CHECK_NOTHROW(Rational(1, 2)); // Корректное создание дроби 1/2
}

TEST_CASE("Testing simple operations") {
    Rational a(1, 2);  // 1/2
    Rational b(1, 3);  // 1/3

    CHECK(a + b == Rational(5, 6));  // 1/2 + 1/3 = 5/6
    CHECK(a - b == Rational(1, 6));  // 1/2 - 1/3 = 1/6
    CHECK(a * b == Rational(1, 6));  // (1/2) * (1/3) = 1/6
    CHECK(a / b == Rational(3, 2));  // (1/2) / (1/3) = 3/2
}

TEST_CASE("Checking operations with integers") {
    Rational a(1, 2); // 1/2

    CHECK(a + 1 == Rational(3, 2)); // 1/2 + 1 = 3/2
    CHECK(a - 1 == Rational(-1, 2)); // 1/2 - 1 = -1/2
    CHECK(a * 2 == Rational(1, 1)); // (1/2) * 2 = 1
    CHECK(a / 2 == Rational(1, 4)); // (1/2) / 2 = 1/4
}

TEST_CASE("Comparison testing") {
    Rational a(1, 2);  // 1/2
    Rational b(2, 4);  // 2/4 (должен быть равен 1/2)

    CHECK(a == b);
    CHECK(a != Rational(1, 3));
    CHECK(a < Rational(3, 4));
    CHECK(a <= b);
    CHECK((b > a) == false);
    CHECK(b >= a);
}

TEST_CASE("Testing the simplification of fractions") {
    Rational c(4, 8);  // 4/8
    CHECK(c == Rational(1, 2));  // Должен упроститься до 1/2

    Rational d(-2, -6);  // -2/-6
    CHECK(d == Rational(1, 3)); // Должен упроститься до 1/3

    Rational e(-2, 6);   // -2/6
    CHECK(e == Rational(-1, 3)); // Должен упроститься до -1/3
}

TEST_CASE("Testing complex operations") {
    Rational f(1, 2); // 1/2
    Rational g(3, 4); // 3/4

    CHECK((f + g) * Rational(4, 3) == Rational(5, 3)); // (1/2 + 3/4) * (4/3)
}

