#include "Parser.hpp"

Parser::Parser() { }

Parser::~Parser() { }

void Parser::remove_left_white_space(std::string &text) {
    auto it = text.begin();
    while (is_empty_space(*it))
        text.erase(it);
}

bool Parser::is_empty_space(char alpha) {
    return alpha == ' ' || alpha == '\t';
}

bool Parser::is_separator(char alpha) {
    return alpha == '(' || alpha == ')' || alpha == '[' || alpha == ']';
}

bool Parser::is_operator(char alpha) {
    if(alpha == '+' || alpha =='-')
        return true;
 
    if(alpha == 'x' || alpha =='/')
        return true;

    return false;
}

bool Parser::is_number(char alpha) {
    return (alpha >= '0' && alpha <= '9') || alpha == ',';
}

void Parser::replace_char(std::string &str, std::string ex, std::string by) {
    if (str.find(ex) != std::string::npos)
        str.replace(str.find(ex), 1, by);
}

double Parser::calc_operator(char alpha, double n1, double n2) {
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

bool Parser::is_valid_expresion(std::string expresion) {
    int n_quant = 0, o_quant = 0;

    for (int i = 0; i < (int) expresion.length(); i++) {
        if (is_empty_space(expresion[i]) || is_separator(expresion[i])) {
            continue;
        }

        if (is_operator(expresion[i])) {
            o_quant++;
            continue;
        }

        for (int j = 0; is_number(expresion[i + j]); j++) {
            if (!is_number(expresion[i + j + 1])) {
                n_quant++;
                i += j;
                break;
            }
        }
        
        char c = expresion[i];
        if(!(is_empty_space(c) || is_separator(c) || is_operator(c) || is_number(c)))
            return false;

    }
    return n_quant == o_quant + 1;
}

bool Parser::is_postfix(std::string postfix) {
    ArrayStack<double> stack;

    if (!is_operator(*(postfix.end() - 1)))
        return false;

    for (int i = 0; i < (int) postfix.length(); i++) {
        if (is_empty_space(postfix[i]))
            continue;

        if (is_separator(postfix[i]))
            return false;

        for (int j = 0; is_number(postfix[i + j]); j++) {
            if (!is_number(postfix[i + j + 1])) {
                std::string n = postfix.substr(i, j + 1);
                replace_char(n, ",", ".");
                stack.push(std::stod(n));
                i += j;
                break;
            }
        }

        if (is_operator(postfix[i])) {
            try {
                double n1, n2, res;
                n1 = stack.pop();
                n2 = stack.pop();
                res = calc_operator(postfix[i], n2, n1);
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
    if (is_operator(*(infix.end() - 1)))
        return false;

    for (int i = 0; i < (int) infix.length(); i++) {
        if (is_number(infix[i]) && is_empty_space(infix[i + 1]) && is_number(infix[i + 2]))
            return false;
        
        if (is_operator(infix[i]) && is_operator(infix[i + 1]))
            return false;
        
        if (is_operator(infix[i] && is_empty_space(infix[i + 1]) && is_operator(infix[i + 2])))
            return false;
    }
    return true;
}

std::string Parser::infix_to_postfix(std::string expresion) {
    std::string postfix = ";)";
    
    return postfix;
}

void Parser::read(std::string input) {
    remove_left_white_space(input);
    
    if (!is_valid_expresion(input))
        std::cout <<  "ERRO: " + input + " NAO VALIDA" << std::endl;

    else if (is_postfix(input)) {
        std::cout <<  "EXPRESSAO OK: " + input << std::endl;
    }

    else if (is_infix(input)) {
        std::cout <<  "EXPRESSAO OK: " + input << std::endl;
    }
    else
        std::cout <<  "ERRO: " + input + " NAO VALIDA" << std::endl;
}

void Parser::infix() {

}

void Parser::postfix() {

}

void Parser::solve() {

}