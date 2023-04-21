#include "Expression.hpp"

Expression::Expression() {

}

Expression::~Expression() {

}

ExpressionTree &Expression::get_tree() {
    return this->_tree;
}

void Expression::insert(std::string exp) {
    for (int i = 0; i < (int) exp.length(); i++) {
        if (util::is_empty_space(exp[i]))
            continue;

        if (util::is_separator(exp[i]) || util::is_operator(exp[i]))
            get_tree().insert(std::string(1, exp[i]));

        //para inserir um numero na arvore
        for (int j = 0; util::is_number(exp[i + j]); j++) {
            if (!util::is_number(exp[i + j + 1])) {
                std::string n = exp.substr(i, j + 1);
                get_tree().insert(n);
                i += j;
                break;
            }
        }
    }
}

std::string Expression::to_infix() {
    return get_tree().print(1);
}

std::string Expression::to_postfix() {
    return get_tree().print(2);
}

double Expression::solve() {
    return 2.6;
}