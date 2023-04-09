#pragma once

#include "IStack.hpp"

template<typename T>
class Stack : public IStack<T> {
private:
    int size;
public:
    Stack();
    ~Stack();

    int get_size();
    bool is_empty();
    virtual void push(T item);
    virtual T pop();
    virtual void clear();
};
