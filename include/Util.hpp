#pragma once

#include <string>

namespace util {
    bool is_empty_space(char alpha);
    bool is_bracket(char alpha);
    bool is_operator(char alpha);
    bool is_number(char alpha);
    void replace_char(std::string &str, std::string ex, std::string by);
}