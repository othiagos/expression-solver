#pragma once

#include <string>

namespace util {
    void remove_left_white_space(std::string &text);
    bool is_empty_space(char alpha);
    bool is_separator(char alpha);
    bool round_bracket(char alpha);
    bool is_operator(char alpha);
    bool is_number(char alpha);
    void replace_char(std::string &str, std::string ex, std::string by);
    double calc_operator(char alpha, double number1, double number2);
}