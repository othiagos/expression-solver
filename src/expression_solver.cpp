#include <iostream>

#include "Parser.hpp"

using std::string;
using std::cin;

int main(int argc, char const *argv[]) {
    string input;
    Parser parser;

    while (cin >> input) {
        if (input == "LER") {
            getline(cin, input);
            parser.read(input);
        }
        else if (input == "INFIXA") {
            parser.infix();
        }
        else if (input == "POSFIXA") {
            parser.postfix();
        }
        else if (input == "RESOLVE") {
            parser.solve();
        }
    }
    return 0;
}