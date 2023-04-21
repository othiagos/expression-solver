#include "Util.hpp"

void util::remove_left_white_space(std::string &text) {
    auto it = text.begin();
    while (is_empty_space(*it))
        text.erase(it);
}

bool util::is_empty_space(char alpha) {
    return alpha == ' ' || alpha == '\t';
}

bool util::is_separator(char alpha) {
    return alpha == '(' || alpha == ')';
}

bool util::round_bracket(char alpha) {
    if (alpha == '(')
        return true;
    if (alpha == ')')
        return false;
    return false;
}

bool util::is_operator(char alpha) {
    if(alpha == '+' || alpha =='-')
        return true;
 
    if(alpha == 'x' || alpha =='/')
        return true;

    return false;
}

bool util::is_number(char alpha) {
    return (alpha >= '0' && alpha <= '9') || alpha == ',';
}

void util::replace_char(std::string &str, std::string ex, std::string by) {
    if (str.find(ex) != std::string::npos)
        str.replace(str.find(ex), 1, by);
}

double util::calc_operator(char alpha, double n1, double n2) {
    switch (alpha) {
    case '+':
        return n1 + n2;
        break;

    case '-':
        return n1 - n2;
        break;

    case 'x':
        return n1 * n2;
        break;

    case '/':
        if (n2 != 0)
            return n1 / n2;
        throw "Invalid division";
        break;
    
    default:
        return 0;
        break;
    }
}

