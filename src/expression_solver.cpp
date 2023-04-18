#include <iostream>

#include "Parser.hpp"
#include "Expression.hpp"

using std::string;
using std::cin;

int main(int argc, char const *argv[]) {
    string input;
    Parser parser;
    Expression expr;

    while (cin >> input) {
        if (input == "LER") {
            getline(cin, input);
            TYPE_EXPR type = parser.expression(input);

            switch (type) {
            case TYPE_EXPR::INVALID_EXPRESION:
                std::cout << "ERRO: " + input + " NAO VALIDA" << std::endl;
                break;
            
            case TYPE_EXPR::INFIX: 
                expr.infix(input);
                std::cout << "EXPRESSAO OK: " + input << std::endl;
                break;

            case TYPE_EXPR::POSTFIX:
                expr.postfix(input);
                std::cout << "EXPRESSAO OK: " + input << std::endl;
                break;
            }
        }
        else if (input == "INFIXA") {
            expr.to_infix();
        }
        else if (input == "POSFIXA") {
            expr.to_postfix();
        }
        else if (input == "RESOLVE") {
            expr.solve();
        }
    }
    return 0;
}