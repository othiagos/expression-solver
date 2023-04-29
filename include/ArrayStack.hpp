#pragma once

#include "IStack.hpp"
#include "StackExcp.hpp"

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
            throw sexcp::StackFull(get_size());

        itens[size] = item;
        size++;
    }

    T pop() override {
        if (get_size() == 0)
            throw sexcp::EmptyStack(get_size());

        size--;
        return itens[size];
    }

    T top() override {
        if (get_size() == 0)
            throw sexcp::EmptyStack(get_size());
        
        return itens[size - 1];
    }

    void clear() override {
        size = 0;
    }
};
