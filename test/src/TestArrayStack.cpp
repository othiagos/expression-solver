#include "doctest.h"
#include "ArrayStack.hpp"

TEST_CASE("Check size and pop") {
    ArrayStack<int> stack;

    stack.push(1);
    stack.push(2);

    CHECK(stack.get_size() == 2);
}

TEST_CASE("Check pop") {
    ArrayStack<int> stack;

    stack.push(15);
    stack.push(25);

    bool exp = stack.pop() == 25 && stack.pop() == 15;
    CHECK(exp);
}

TEST_CASE("Check clear") {
    ArrayStack<int> stack;

    stack.push(1);
    stack.push(2);

    stack.clear();

    CHECK(stack.is_empty());
}