#pragma once

#include "IStack.hpp"

#define MAX_TAM 1000

template<typename T>
class ArrayStack : public IStack<T> {
private:
    int size;
    T itens[MAX_TAM];

public:
    ArrayStack() {
        size = 0;
    }

    ~ArrayStack() { }

    int get_size() {
        return size;
    }

    bool is_empty() override {
        return get_size() == 0;
    }

    void push(T item) override  {
        if (get_size() == MAX_TAM)
            throw "Stack is full!";

        itens[size++] = item;
    }

    T pop() override {
        if (get_size() == 0)
            throw "Stack is empty!";

        return itens[size--];
    }

    void clear() override {
        size = 0;
    }
};
