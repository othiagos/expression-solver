#pragma once

#include <string>

namespace util {
    void remove_left_white_space(std::string &text);
    void remove_right_white_space(std::string &text);
    void rm_border_space(std::string &text);
    void rm_bracket_border(std::string &text);
    bool is_empty_space(char alpha);
    bool is_bracket(char alpha);
    bool round_bracket(char alpha);
    bool is_operator(char alpha);
    bool is_number(char alpha);
    void replace_char(std::string &str, std::string ex, std::string by);
    double calc_operator(char alpha, double number1, double number2);
    std::string get_number(std::string exp, int &i);
}