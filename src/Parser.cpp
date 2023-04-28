#include "Parser.hpp"

void Parser::is_valid(std::string exp) {
    int n_quant = 0, o_quant = 0;

    for (int i = 0; i < (int) exp.length(); i++) {
        if (util::is_empty_space(exp[i])) {
            continue;
        }

        if (util::is_operator(exp[i])) {
            o_quant++;
            continue;
        }

        for (int j = 0; util::is_number(exp[i + j]); j++) {
            if (!util::is_number(exp[i + j + 1])) {
                n_quant++;
                i += j;
                break;
            }
        }
        
        char c = exp[i];
        if(!(util::is_empty_space(c) || util::is_bracket(c) || util::is_operator(c) || util::is_number(c)))
            throw pexcp::InvalidExpresion(exp);

    }

    if (n_quant != o_quant + 1)
        throw pexcp::InvalidExpresion(exp);
}

void Parser::is_postfix(std::string exp) {
    Parser::is_valid(exp);
    
    if (!util::is_operator(*(exp.end() - 1)))
        throw pexcp::InvalidPostfix(exp);

    int find_number = 0;
    for (int i = 0; i < (int) exp.length(); i++) {
        if (util::is_empty_space(exp[i]))
            continue;

        if (util::is_operator(exp[i]) || util::is_bracket(exp[i]))
            throw pexcp::InvalidPostfix(exp);
        
        for (int j = 0; util::is_number(exp[i + j]); j++) {
            if (!util::is_number(exp[i + j + 1])) {
                find_number++;
                i += j;
                break;
            }
        }

        if (find_number == MIN_NUMBER)
            break;
    }
}

void Parser::is_infix(std::string exp) {
    Parser::is_valid(exp);

    if (util::is_operator(*(exp.end() - 1)))
        throw pexcp::InvalidInfix(exp);

    for (int i = 0; i < (int) exp.length(); i++) {
        if (util::is_number(exp[i]) && util::is_empty_space(exp[i + 1]) && util::is_number(exp[i + 2]))
            throw pexcp::InvalidInfix(exp);
        
        if (util::is_operator(exp[i]) && util::is_operator(exp[i + 1]))
            throw pexcp::InvalidInfix(exp);
        
        if (util::is_operator(exp[i] && util::is_empty_space(exp[i + 1]) && util::is_operator(exp[i + 2])))
            throw pexcp::InvalidInfix(exp);
    }
}