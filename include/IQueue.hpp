#pragma once

template<typename T>
class IQueue {
public:
    virtual bool is_empty() = 0;
    virtual void enqueue(T item) = 0;
    virtual T dequeue() = 0;
    virtual void clear() = 0;
};