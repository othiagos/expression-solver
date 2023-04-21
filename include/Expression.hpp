#pragma once

#include <string>

#include "ExpressionTree.hpp"
#include "Util.hpp"

class Expression {
private:
    ExpressionTree _tree;

    ExpressionTree &get_tree();

public:
    Expression();
    ~Expression();

    void insert(std::string exp);
    std::string to_infix();
    std::string to_postfix();
    double solve();
};
