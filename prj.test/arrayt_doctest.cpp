#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <arrayt/arrayt.hpp>

TEST_CASE("[arrayt] - ctor") {
    SUBCASE("Default constructor") {
        ArrayT<double> arr;
        CHECK(arr.Size() == 0);
    }

    SUBCASE("Constructor with size") {
        ArrayT<int> arr(5);
        CHECK(arr.Size() == 5);
    }
}

TEST_CASE("[arrayt] - copy ctor") {
    ArrayT<char> arr1(3);
    arr1[0] = 'a';
    arr1[1] = 'b';
    arr1[2] = 'c';

    ArrayT<char> arr2(arr1);
    CHECK(arr2.Size() == 3);
    CHECK(arr2[0] == 'a');
    CHECK(arr2[1] == 'b');
    CHECK(arr2[2] == 'c');
}

TEST_CASE("[arrayt] - assignment operator") {
    ArrayT<std::string> arr1(2);
    arr1[0] = "hello";
    arr1[1] = "world";

    ArrayT<std::string> arr2;
    arr2 = arr1;

    CHECK(arr2.Size() == 2);
    CHECK(arr2[0] == "hello");
    CHECK(arr2[1] == "world");
}

TEST_CASE("[arrayt] - assignment operator") {
    SUBCASE("Assigning to an empty array") {
        ArrayT<int> arr1;
        ArrayT<int> arr2 = arr1;

        CHECK(arr2.Size() == 0);
    }

    SUBCASE("Assigning to a non-empty array") {
        ArrayT<int> arr1(3);
        arr1[0] = 1;
        arr1[1] = 2;
        arr1[2] = 3;

        ArrayT<int> arr2;
        arr2 = arr1;

        CHECK(arr2.Size() == 3);
        CHECK(arr2[0] == 1);
        CHECK(arr2[1] == 2);
        CHECK(arr2[2] == 3);
    }
}

TEST_CASE("[arrayt] - resize") {
    ArrayT<float> arr(3);
    arr.Resize(5); // Increase size
    CHECK(arr.Size() == 5);

    arr.Resize(2); // Decrease size
    CHECK(arr.Size() == 2);

    arr.Resize(0); // Resize to zero
    CHECK(arr.Size() == 0);
}

TEST_CASE("[arrayt] - insert") {
    ArrayT<char> arr;
    arr.Insert(0, 'a');
    CHECK(arr.Size() == 1);
    CHECK(arr[0] == 'a');

    arr.Insert(1, 'b');
    CHECK(arr.Size() == 2);
    CHECK(arr[1] == 'b');

    arr.Insert(1, 'c'); // Insert in the middle
    CHECK(arr.Size() == 3);
    CHECK(arr[1] == 'c');
    CHECK(arr[2] == 'b');

    arr.Insert(0, 'd'); // Insert at the beginning
    CHECK(arr.Size() == 4);
    CHECK(arr[0] == 'd');
}

TEST_CASE("[arrayt] - remove") {
    ArrayT<int> arr;
    arr.Insert(0, 1);
    arr.Insert(1, 2);
    arr.Insert(2, 3);

    arr.Remove(0); // Remove element at index 1

    CHECK(arr.Size() == 2);
    CHECK(arr[0] == 2);
    CHECK(arr[1] == 3);

    arr.Remove(0); // Remove first element

    CHECK(arr.Size() == 1);
    CHECK(arr[0] == 3);
}