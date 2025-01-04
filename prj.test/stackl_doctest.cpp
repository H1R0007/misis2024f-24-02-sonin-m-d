#include <stackl/stackl.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("StackL - Push, Pop, and Top operations") {
    StackL stack;

    SUBCASE("Push elements and check top") {
        stack.Push(10);
        CHECK(stack.Top() == 10);

        stack.Push(20);
        CHECK(stack.Top() == 20);
    }

    SUBCASE("Pop elements and check stack state") {
        stack.Push(30);
        stack.Push(40);
        stack.Push(50);

        CHECK(stack.Top() == 50);

        stack.Pop();
        CHECK(stack.Top() == 40);

        stack.Pop();
        CHECK(stack.Top() == 30);

        stack.Pop();
        CHECK(stack.IsEmpty());

        // Try popping from an empty stack
        CHECK_NOTHROW(stack.Pop()); // No throw expected
    }
}

TEST_CASE("StackL - Clear and IsEmpty operations") {
    StackL stack;

    SUBCASE("Check initial state") {
        CHECK(stack.IsEmpty());
    }

    SUBCASE("Push elements and then clear the stack") {
        stack.Push(60);
        stack.Push(70);

        CHECK_FALSE(stack.IsEmpty());

        stack.Clear();
        CHECK(stack.IsEmpty());
    }
}

TEST_CASE("StackL - Copy and Move operations") {
    StackL stack1;

    stack1.Push(80);
    stack1.Push(90);

    SUBCASE("Copy constructor") {
        StackL stack2(stack1);

        CHECK(stack2.Top() == 90);
        stack2.Pop();
        CHECK(stack2.Top() == 80);
    }

    SUBCASE("Move constructor") {
        StackL stack3(std::move(stack1));

        CHECK(stack3.Top() == 90);
        stack3.Pop();
        CHECK(stack3.Top() == 80);
    }

    SUBCASE("Copy assignment operator") {
        StackL stack4;
        stack4 = stack1;

        CHECK(stack4.Top() == 90);
    }

    SUBCASE("Move assignment operator") {
        StackL stack5;
        stack5 = std::move(stack1);

        CHECK(stack5.Top() == 90);
    }
}
