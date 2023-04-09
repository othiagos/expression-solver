#pragma once

template<typename T>
class ITree {
public:
    virtual void insert(T item) = 0;
    virtual void clear() = 0;
};
