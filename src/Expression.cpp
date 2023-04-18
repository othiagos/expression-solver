#include "Expression.hpp"

Expression::Expression() {

}

Expression::~Expression() {

}

std::string Expression::infix_to_postfix(std::string) {
    return "";
}

void Expression::infix(std::string exp) {
    postfix(infix_to_postfix(exp));
}

void Expression::postfix(std::string exp) {

}

std::string Expression::to_infix() {
    return "";
}

std::string Expression::to_postfix() {
    return "";
}

double Expression::solve() {
    return 2.6;
}