#pragma once

#include <string>

namespace etexcp {
    class EmptyTree : public std::exception {
    private:
        
    public:
        EmptyTree() { }

        const char* what() const throw() {
            return "no tree stored";
        }
    };

    class DomainError : public std::exception {
    private:
        
    public:
        DomainError() { }

        const char* what() const throw() {
            return "can not divide by zero";
        }
    };
}
