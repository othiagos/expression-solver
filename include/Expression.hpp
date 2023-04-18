#pragma once

#include <string>

class Expression {
private:

    std::string infix_to_postfix(std::string);

public:
    Expression();
    ~Expression();

    void infix(std::string exp);
    void postfix(std::string exp);
    std::string to_infix();
    std::string to_postfix();
    double solve();
};
