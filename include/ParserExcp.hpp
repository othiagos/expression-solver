#pragma once

#include <string>

namespace pexcp {
    class InvalidInfix : public std::exception {
    private:
        std::string _exp;
        
    public:
        InvalidInfix(std::string exp) : _exp(exp) { }

        std::string get_exp() { return this->_exp; }

        const char* what() const throw() {
            return "Invalid Infix Expresion";
        }
    };

    class InvalidPostfix : public std::exception {
    private:
        std::string _exp;
        
    public:
        InvalidPostfix(std::string exp) : _exp(exp) { }

        std::string get_exp() { return this->_exp; }

        const char* what() const throw() {
            return "Invalid Postfix Expresion";
        }
    };

    class InvalidExpresion : public std::exception {
    private:
        std::string _exp;
        
    public:
        InvalidExpresion(std::string exp) : _exp(exp) { }

        std::string get_exp() { return this->_exp; }

        const char* what() const throw() {
            return "Invalid Expresion";
        }
    };
}
