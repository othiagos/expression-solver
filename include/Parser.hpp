#pragma once

#include <iostream>
#include <string>
#include <string>

#include "ArrayStack.hpp"

enum TYPE_EXPR {
    INVALID_EXPRESION,
    INFIX,
    POSTFIX
};

class Parser {
private:
    void remove_left_white_space(std::string &text);
    bool is_empty_space(char alpha);
    bool is_separator(char alpha);
    bool is_operator(char alpha);
    bool is_number(char alpha);
    bool is_valid_expresion(std::string expresion);
    bool is_postfix(std::string postfix);
    bool is_infix(std::string postfix);
    void replace_char(std::string &str, std::string ex, std::string by);
    double calc_operator(char alpha, double number1, double number2);

public:
    Parser();
    ~Parser();

    TYPE_EXPR expression(std::string &input);
};
