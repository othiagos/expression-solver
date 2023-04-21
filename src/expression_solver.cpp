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
                expr.insert(input);
                std::cout << "EXPRESSAO OK: " + input << std::endl;
                break;

            case TYPE_EXPR::POSTFIX:
                expr.insert(input);
                std::cout << "EXPRESSAO OK: " + input << std::endl;
                break;
            }
        }
        else if (input == "INFIXA") {
            std::cout << "INFIXA: "<< expr.to_infix() << std::endl;
        }
        else if (input == "POSFIXA") {
            std::cout << "POSFIXA: "<< expr.to_postfix() << std::endl;;
        }
        else if (input == "RESOLVE") {
            expr.solve();
        }
    }
    return 0;
}