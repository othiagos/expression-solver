#include "Util.hpp"

bool util::is_empty_space(char alpha) {
    return alpha == ' ' || alpha == '\t';
}

bool util::is_bracket(char alpha) {
    return alpha == '(' || alpha == ')';
}

bool util::is_operator(char alpha) {
    if(alpha == '+' || alpha =='-')
        return true;
 
    if(alpha == '*' || alpha =='/')
        return true;

    return false;
}

bool util::is_number(char alpha) {
    return (alpha >= '0' && alpha <= '9') || alpha == '.';
}

void util::replace_char(std::string &str, std::string ex, std::string by) {
    if (str.find(ex) != std::string::npos)
        str.replace(str.find(ex), 1, by);
}
