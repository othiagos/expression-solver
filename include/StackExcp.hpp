#pragma once

#include <exception>

namespace sexcp {
    class StackFull : public std::exception {
    private:
        int _size;
        
    public:
        StackFull(int size) : _size(size) { }

        int get_size() { return this->_size; }

        const char* what() const throw() {
            return "Stack is full";
        }
    };

    class EmptyStack : public std::exception {
    private:
        int _size;
        
    public:
        EmptyStack(int size) : _size(size) { }

        int get_size() { return this->_size; }

        const char* what() const throw() {
            return "Stack is empty";
        }
    };
}
