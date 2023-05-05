#include "doctest.h"
#include "Parser.hpp"

TEST_CASE("check if is invalid  expression") {
    std::string exp = "2+3 5 *";

    CHECK_THROWS_AS(Parser::is_infix(exp), pexcp::InvalidInfix);
}

TEST_CASE("check if is invalid  expression") {
    std::string exp = "2+3**5 1";

    CHECK_THROWS_AS(Parser::is_infix(exp), pexcp::InvalidInfix);
}

TEST_CASE("check if is invalid  expression") {
    std::string exp = "2+3* *5 1";

    CHECK_THROWS_AS(Parser::is_infix(exp), pexcp::InvalidInfix);
}

TEST_CASE("check if is invalid  expression") {
    std::string exp = "2 4 - - 4";

    CHECK_THROWS_AS(Parser::is_postfix(exp), pexcp::InvalidPostfix);
}

TEST_CASE("check if is invalid  expression") {
    std::string exp = "2 - 3 + 6";

    CHECK_THROWS_AS(Parser::is_postfix(exp), pexcp::InvalidPostfix);
}

TEST_CASE("check if is invalid  expression") {
    std::string exp = "5.22.3 + 4,1";

    CHECK_THROWS_AS(Parser::is_infix(exp), pexcp::InvalidExpresion);
}

TEST_CASE("check if is invalid expression") {
    std::string exp = "2 + 3 x 5";

    CHECK_THROWS_AS(Parser::is_infix(exp), pexcp::InvalidExpresion);
}

TEST_CASE("check if is valid expression") {
    std::string exp = "5,2 1 2 + 4.7 * + 3 -";

    Parser::is_postfix(exp);
    CHECK(true);
}

TEST_CASE("check if is valid expression") {
    std::string exp = "2 + 3 * 5";

    Parser::is_infix(exp);
    CHECK(true);
}

TEST_CASE("check if is valid expression") {
    std::string exp = "2+3*5";

    Parser::is_infix(exp);
    CHECK(true);
}

TEST_CASE("check if is valid expression") {
    std::string exp = "(5 + ((1 + 2) * 4) - 3)";

    Parser::is_infix(exp);
    CHECK(true);
}

TEST_CASE("check if is valid expression") {
    std::string exp = "5.2 1 2 + 4.7 * + 3 -";

    Parser::is_postfix(exp);
    CHECK(true);
}

TEST_CASE("check if is valid expression") {
    std::string exp = ".2 1 2 + .7 * + 3 -";

    Parser::is_postfix(exp);
    CHECK(true);
}