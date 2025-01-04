#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <arrayd/arrayd.hpp>

TEST_CASE("ArrayD Tests") {
    SUBCASE("Constructor and Indexing") {
        ArrayD arr(5); // Создаем массив размером 5
        CHECK(arr.Size() == 5); // Проверяем размер массива

        // Проверяем инициализацию массива
        for (std::ptrdiff_t i = 0; i < arr.Size(); ++i) {
            CHECK(arr[i] == doctest::Approx(0.0));  // Проверяем, что все элементы равны 0.0 (используем Approx для сравнения float)
        }

        // Изменяем значение элемента и проверяем, что значение действительно изменилось
        arr[2] = 3.14;
        CHECK(arr[2] == doctest::Approx(3.14));
    }

    SUBCASE("Insert and Remove Tests") {
        // Создаем массив и вставляем элемент в середину
        ArrayD arr(3);
        arr[0] = 1.0;
        arr[1] = 2.0;
        arr.Insert(1, 1.5);
        CHECK(arr[1] == doctest::Approx(1.5));
        CHECK(arr.Size() == 4);

        // Удаляем элемент из массива
        arr.Remove(1);
        CHECK(arr[1] == doctest::Approx(2.0));
        CHECK(arr.Size() == 3);
    
    }
}

TEST_CASE("ArrayD operator[] const and non-const tests") {
    ArrayD arr(3);
    arr[0] = 10.0;
    arr[1] = 20.0;
    arr[2] = 30.0;

    CHECK(arr[0] == 10.0);  // Check non-const access for correctness
    CHECK(arr[1] == 20.0);
    CHECK(arr[2] == 30.0);

    arr[1] = 25.0;  // Non-const access should allow modification
    CHECK(arr[1] == 25.0);
}


TEST_CASE("ArrayD assignment operator works correctly") {
    SUBCASE("Assigning one ArrayD object to another") {
        ArrayD arr1(3);
        arr1[0] = 10;
        arr1[1] = 20;
        arr1[2] = 30;

        ArrayD arr2(2);
        arr2[0] = 40;
        arr2[1] = 50;

        arr2 = arr1;

        // Check if the sizes are equal after assignment
        CHECK(arr2.Size() == 3);

        // Check the specific values post-assignment
        CHECK(arr2[0] == 10);
        CHECK(arr2[1] == 20);
        CHECK(arr2[2] == 30);
    }

    SUBCASE("Self-assignment does not modify the object") {
        ArrayD arr(4);
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;

        ArrayD& ref = arr;
        ref = arr; // self-assignment

        // Check that the object remains unchanged after self-assignment
        CHECK(arr[0] == 1);
        CHECK(arr[1] == 2);
        CHECK(arr[2] == 3);
        CHECK(arr[3] == 4);
    }
}