#pragma once

#include <iostream>
#include <string>
#include <string>

#include "ArrayStack.hpp"
#include "Util.hpp"

enum TYPE_EXPR {
    INVALID_EXPRESION,
    INFIX,
    POSTFIX
};

class Parser {
private:
    bool is_valid_expresion(std::string expresion);
    bool is_postfix(std::string postfix);
    bool is_infix(std::string postfix);

public:
    Parser();
    ~Parser();

    TYPE_EXPR expression(std::string &input);
};
