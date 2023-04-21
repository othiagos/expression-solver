#include "Parser.hpp"

Parser::Parser() { }

Parser::~Parser() { }

bool Parser::is_valid_expresion(std::string expresion) {
    int n_quant = 0, o_quant = 0;

    for (int i = 0; i < (int) expresion.length(); i++) {
        if (util::is_empty_space(expresion[i]) || util::is_separator(expresion[i])) {
            continue;
        }

        if (util::is_operator(expresion[i])) {
            o_quant++;
            continue;
        }

        for (int j = 0; util::is_number(expresion[i + j]); j++) {
            if (!util::is_number(expresion[i + j + 1])) {
                n_quant++;
                i += j;
                break;
            }
        }
        
        char c = expresion[i];
        if(!(util::is_empty_space(c) || util::is_separator(c) || util::is_operator(c) || util::is_number(c)))
            return false;

    }
    return n_quant == o_quant + 1;
}

bool Parser::is_postfix(std::string postfix) {
    ArrayStack<double> stack;

    if (!util::is_operator(*(postfix.end() - 1)))
        return false;

    for (int i = 0; i < (int) postfix.length(); i++) {
        if (util::is_empty_space(postfix[i]))
            continue;

        if (util::is_separator(postfix[i]))
            return false;

        for (int j = 0; util::is_number(postfix[i + j]); j++) {
            if (!util::is_number(postfix[i + j + 1])) {
                std::string n = postfix.substr(i, j + 1);
                util::replace_char(n, ",", ".");
                stack.push(std::stod(n));
                i += j;
                break;
            }
        }

        if (util::is_operator(postfix[i])) {
            try {
                double n1, n2, res;
                n1 = stack.pop();
                n2 = stack.pop();
                res = util::calc_operator(postfix[i], n2, n1);
                stack.push(res);
            }
            catch(...) {
                return false;
            }
        }
    }
    return stack.get_size() == 1;
}

bool Parser::is_infix(std::string infix) {
    if (util::is_operator(*(infix.end() - 1)))
        return false;

    for (int i = 0; i < (int) infix.length(); i++) {
        if (util::is_number(infix[i]) && util::is_empty_space(infix[i + 1]) && util::is_number(infix[i + 2]))
            return false;
        
        if (util::is_operator(infix[i]) && util::is_operator(infix[i + 1]))
            return false;
        
        if (util::is_operator(infix[i] && util::is_empty_space(infix[i + 1]) && util::is_operator(infix[i + 2])))
            return false;
    }
    return true;
}

TYPE_EXPR Parser::expression(std::string &input) {
    util::remove_left_white_space(input);

    if (!is_valid_expresion(input))
        return TYPE_EXPR::INVALID_EXPRESION;
    else if (is_postfix(input)) {
        return TYPE_EXPR::POSTFIX;
    }
    else if (is_infix(input))  {
        return TYPE_EXPR::INFIX;
    }
    return TYPE_EXPR::INVALID_EXPRESION;
}