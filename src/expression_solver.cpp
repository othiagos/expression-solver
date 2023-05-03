#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "ExpressionTree.hpp"

using std::string;
using std::cin;

int main(int argc, char const *argv[]) {
    string input;
    ExpressionTree tree;

    while (cin >> input) {
        try {
            if (input == "LER") {
                std::string t_exp;
                cin >> t_exp;
                getline(cin, input);

                if (t_exp == "INFIXA")
                    tree.insert_infix(input);
                else if (t_exp == "POSFIXA")
                    tree.insert_postfix(input);

                //remove left space from input
                while (util::is_empty_space(*input.begin()))
                    input.erase(input.begin());
                
                std::cout << "EXPRESSAO OK: " + input << std::endl;
            }
            else if (input == "INFIXA") {
                std::string str = tree.in_order();
                std::cout << "INFIXA: "<< str << std::endl;
            }
            else if (input == "POSFIXA") {
                std::string str = tree.post_order();
                std::cout << "POSFIXA: "<< str << std::endl;
            }
            else if (input == "RESOLVE") {
                std::stringstream stream;
                stream << std::fixed << tree.solve();

                std::string str = stream.str();

                //remove right zero from str
                while (*(str.end() - 1) == '0')
                    str.erase(str.end() - 1);
                
                if (*(str.end() - 1) == ',')
                    str.erase(str.end() - 1);
                
                std::cout << "VAL: " << str << std::endl;
            }
            else if (input == "SAIR")
                break;
            
        }
        catch (etexcp::DomainError &e) {
            std::cerr << "ERRO: EXP NAO EXISTE" << std::endl;
        }
        catch (etexcp::EmptyTree &e) {
            std::cerr << "ERRO: EXP NAO EXISTE" << std::endl;
        }
        catch (pexcp::InvalidInfix &e) {
            std::cerr << "ERRO: " + e.get_exp() + " NAO VALIDA" << std::endl;
        }
        catch (pexcp::InvalidPostfix &e) {
            std::cerr << "ERRO: " + e.get_exp() + " NAO VALIDA" << std::endl;
        }
        catch (pexcp::InvalidExpresion &e) {
            std::cerr << "ERRO: " + e.get_exp() + " NAO VALIDA" << std::endl;
        }
        catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}