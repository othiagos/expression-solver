#include "Util.hpp"

void util::remove_left_white_space(std::string &text) {
    while (is_empty_space(*text.begin()))
        text.erase(text.begin());
}

void util::remove_right_white_space(std::string &text) {
    while (is_empty_space(*(text.end() - 1)))
        text.erase(text.end() - 1);
}

void util::rm_border_space(std::string &text) {
    remove_left_white_space(text);
    remove_right_white_space(text);
}

void util::rm_bracket_border(std::string &text) {
    int start = 0, bracket_stage = 0;

    for (int i = 0; i < (int) text.length(); i++) {
        if (text[i] == '(') {
            if (bracket_stage == 0)
                start = i;
            bracket_stage++;
        }

        if (text[i] == ')') {
            bracket_stage--;
            if (bracket_stage == 0) {
                text.erase(text.begin() + i);
                text.erase(text.begin() + start);
            }
        }
    }
}

bool util::is_empty_space(char alpha) {
    return alpha == ' ' || alpha == '\t';
}

bool util::is_bracket(char alpha) {
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
 
    if(alpha == '*' || alpha =='/')
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

    case '*':
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

std::string util::get_number(std::string exp, int &i) {
    for (int j = 0; util::is_number(exp[i + j]); j++) {

        if (!util::is_number(exp[i + j + 1])) {
            std::string number = exp.substr(i, j + 1);
            i += j;
            return number;
        }

    }
    return "";
}
