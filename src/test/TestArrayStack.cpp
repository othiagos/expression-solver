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

TEST_CASE("Check top") {
    ArrayStack<int> stack;

    stack.push(15);
    stack.push(25);

    bool exp = stack.top() == 25 && stack.get_size() == 2;
    CHECK(exp);
}

TEST_CASE("Check stack is full") {
    ArrayStack<int> stack;

    while (stack.get_size() < MAX_TAM)    
        stack.push(7);

    CHECK_THROWS_AS(stack.push(21), sexcp::StackFull);
}

TEST_CASE("Check stack is empty") {
    ArrayStack<int> stack;

    CHECK_THROWS_AS(stack.pop(), sexcp::EmptyStack);
}

TEST_CASE("Check stack is empty TOP") {
    ArrayStack<int> stack;

    CHECK_THROWS_AS(stack.top(), sexcp::EmptyStack);
}