#include "doctest.h"
#include "ArrayQueue.hpp"

TEST_CASE("Check size and enqueue") {
    ArrayQueue<int> queue;

    queue.enqueue(4);
    queue.enqueue(7);

    CHECK(queue.get_size() == 2);
}

TEST_CASE("Check dequeue") {
    ArrayQueue<int> queue;

    queue.enqueue(4);
    queue.enqueue(7);

    bool test = queue.dequeue() == 4 && queue.dequeue() == 7;
    CHECK(test);
}

TEST_CASE("Check is empty") {
    ArrayQueue<int> queue;

    queue.enqueue(4);
    queue.enqueue(7);

    queue.dequeue();
    queue.dequeue();

    CHECK(queue.is_empty());
}

TEST_CASE("Check size") {
    ArrayQueue<int> queue;

    queue.enqueue(4);
    queue.enqueue(4);
    queue.enqueue(6);
    queue.enqueue(8);
    queue.enqueue(12);

    queue.dequeue();
    queue.dequeue();

    CHECK(queue.get_size() == 3);
}

TEST_CASE("Check clear") {
    ArrayQueue<int> queue;

    queue.enqueue(4);
    queue.enqueue(4);
    queue.enqueue(6);
    queue.enqueue(8);
    queue.enqueue(12);

    queue.clear();

    CHECK(queue.is_empty());
}