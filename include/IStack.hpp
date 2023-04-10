#pragma once

template<typename T>
class IStack {
public:
    virtual bool is_empty() = 0;
    virtual void push(T item) = 0;
    virtual T pop() = 0;
    virtual T top() = 0;
    virtual void clear() = 0;
};
