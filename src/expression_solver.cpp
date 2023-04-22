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
        try {
            if (input == "LER") {
                getline(cin, input);
                TYPE_EXPR type = parser.expression(input);

                switch (type) {
                case TYPE_EXPR::INVALID_EXPRESION:
                    std::cout << "ERRO: " + input + " NAO VALIDA" << std::endl;
                    tree.clear();
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
                std::string str = tree.in_order();
                std::cout << "INFIXA: "<< str << std::endl;
            }
            else if (input == "POSFIXA") {
                std::string str = tree.post_order();
                std::cout << "POSFIXA: "<< str << std::endl;;
            }
            else if (input == "RESOLVE") {
                std::stringstream stream;
                stream << std::fixed << std::setprecision(10) << tree.solve();
                // stream << tree.solve();

                std::string str = stream.str();
                util::replace_char(str, ".", ",");
                std::cout << "VAL: " << str << std::endl;
            }
        } catch (...) {
            std::cout << "ERRO: " + input + " NAO VALIDA" << std::endl;
        }
        //  catch(const std::exception& e) {
        //     std::cerr << e.what() << '\n';
        // }
    }
    return 0;
}