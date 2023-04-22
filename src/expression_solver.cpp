#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Parser.hpp"
#include "ExpressionTree.hpp"

using std::string;
using std::cin;

int main(int argc, char const *argv[]) {
    string input;
    Parser parser;
    ExpressionTree tree;

    while (cin >> input) {
        if (input == "LER") {
            getline(cin, input);
            TYPE_EXPR type = parser.expression(input);

            switch (type) {
            case TYPE_EXPR::INVALID_EXPRESION:
                std::cout << "ERRO: " + input + " NAO VALIDA" << std::endl;
                break;
            
            case TYPE_EXPR::INFIX: 
                tree.insert_infix(input);
                std::cout << "EXPRESSAO OK: " + input << std::endl;
                break;

            case TYPE_EXPR::POSTFIX:
                tree.insert_postfix(input);
                std::cout << "EXPRESSAO OK: " + input << std::endl;
                break;
            }
        }
        else if (input == "INFIXA") {
            std::cout << "INFIXA: "<< tree.in_order() << std::endl;
        }
        else if (input == "POSFIXA") {
            std::cout << "POSFIXA: "<< tree.post_order() << std::endl;;
        }
        else if (input == "RESOLVE") {
            std::stringstream stream;
            stream << std::fixed << std::setprecision(6) << tree.solve();

            std::string str = stream.str();
            util::replace_char(str, ".", ",");
            std::cout << "VAL: " << str << std::endl;
        }
    }
    return 0;
}