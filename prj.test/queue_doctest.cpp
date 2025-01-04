#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queue/queue.hpp>

TEST_CASE("QueueA - Push and Pop operations") {
    QueueA queue;

    SUBCASE("Push elements and check top") {
        queue.Push(10);
        CHECK(queue.Top() == 10);

        queue.Push(20);
        CHECK(queue.Top() == 10); // Top should still be the first element
    }

    SUBCASE("Push and Pop elements") {
        queue.Push(30);
        queue.Push(40);

        CHECK(queue.Top() == 30);

        queue.Pop();
        CHECK(queue.Top() == 40);

        queue.Pop();
        CHECK(queue.IsEmpty());
    }
}

TEST_CASE("QueueA - Clear and IsEmpty operations") {
    QueueA queue;

    SUBCASE("Clear an empty queue") {
        CHECK(queue.IsEmpty());
        queue.Push(50);
        CHECK(queue.IsEmpty() == false);
        queue.Clear();
        CHECK(queue.IsEmpty());
    }

    SUBCASE("Clear a non-empty queue") {
        queue.Push(50);
        queue.Push(60);

        CHECK_FALSE(queue.IsEmpty());
        queue.Clear();
        CHECK(queue.IsEmpty());
    }
}

TEST_CASE("QueueA - Copy and Move operations") {
    QueueA queue1;

    SUBCASE("Copy constructor") {
        queue1.Push(70);
        queue1.Push(80);

        QueueA queue2(queue1);

        CHECK(queue2.Top() == 70);
        queue2.Pop();
        CHECK(queue2.Top() == 80);
    }

    SUBCASE("Move constructor") {
        queue1.Push(90);
        queue1.Push(100);

        QueueA queue3(std::move(queue1));

        CHECK(queue3.Top() == 90);
        queue3.Pop();
        CHECK(queue3.Top() == 100);
    }

    SUBCASE("Copy assignment operator") {
        QueueA queue4;
        queue4.Push(110);

        QueueA queue5;
        queue5 = queue4;

        CHECK(queue5.Top() == 110);
    }

    SUBCASE("Move assignment operator") {
        QueueA queue6;
        queue6.Push(120);

        QueueA queue7;
        queue7 = std::move(queue6);

        CHECK(queue7.Top() == 120);
    }
}
