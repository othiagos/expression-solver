#include "doctest.h"
#include "ExpressionTree.hpp"

TEST_CASE("Check insert infix") {
    ExpressionTree tree;

    tree.insert_infix("2 * 4 + 3");
    CHECK(true);
}

TEST_CASE("Check insert infix with brackets") {
    ExpressionTree tree;

    tree.insert_infix("( ( ( 2 ) * ( 4 ) ) + 3 )");
    CHECK(true);
}

TEST_CASE("Check insert postfix") {
    ExpressionTree tree;

    tree.insert_postfix("2 4 * 3 +");
    CHECK(true);
}

TEST_CASE("Check solve") {
    ExpressionTree tree;

    tree.insert_postfix("2,3 4,7 * 3,3 +");

    double solve = tree.solve();
    CHECK(solve == 14.11);
}

TEST_CASE("Check division by zero") {
    ExpressionTree tree;

    tree.insert_infix("(5,5+8,8)/(4,5-4,5)");
    CHECK_THROWS_AS(tree.solve(), etexcp::DomainError);
}