#include "doctest.h"
#include "Parser.hpp"

TEST_CASE("check if is invalid  expression") {
    Parser p;
    std::string e = "2+3 5 x";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::INVALID_EXPRESION == t);
}

TEST_CASE("check if is invalid  expression") {
    Parser p;
    std::string e = "2+3xx5";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::INVALID_EXPRESION == t);
}

TEST_CASE("check if is invalid  expression") {
    Parser p;
    std::string e = "2+3x x5";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::INVALID_EXPRESION == t);
}


TEST_CASE("check if is invalid  expression") {
    Parser p;
    std::string e = "5,2 1 2 + 4.7 x + 3 -";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::INVALID_EXPRESION == t);
}

TEST_CASE("check if is valid expression") {
    Parser p;
    std::string e = "2 + 3 x 5";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::INFIX == t);
}

TEST_CASE("check if is valid expression") {
    Parser p;
    std::string e = "2+3x5";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::INFIX == t);
}

TEST_CASE("check if is valid expression") {
    Parser p;
    std::string e = "5 + ((1 + 2) x 4) - 3";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::INFIX == t);
}

TEST_CASE("check if is valid expression") {
    Parser p;
    std::string e = "5,2 1 2 + 4,7 x + 3 -";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::POSTFIX == t);
}


TEST_CASE("check if is valid expression") {
    Parser p;
    std::string e = "0,2 1 2 + 0,7 x + 3 -";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::POSTFIX == t);
}

TEST_CASE("check if is valid expression") {
    Parser p;
    std::string e = ",2 1 2 + ,7 x + 3 -";

    TYPE_EXPR t = p.expression(e);

    CHECK(TYPE_EXPR::POSTFIX == t);
}