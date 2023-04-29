#pragma once

#include <iostream>

#include "ExpressionTreeExcp.hpp"
#include "ArrayStack.hpp"
#include "Parser.hpp"
#include "Util.hpp"

class Node {
private:
    std::string item;
    Node *left;
    Node *right;

public:
    Node();

    friend class ExpressionTree;
};

class ExpressionTree {
private:
    Node *_root;
    bool _has_tree;

    Node *get_root();
    void set_root(Node *new_root);
    bool get_has_tree();
    void set_has_tree(bool stage);
    void clear_recursive(Node *node);
    std::string pre_order(Node* node);
    std::string in_order(Node* node);
    std::string post_order(Node* node);
    std::string break_expression(std::string exp, std::string &lstr, std::string &rstr);
    void insert_recursive_infix(Node* node);
    double solve(Node *node);
    void remove_left_white_space(std::string &text);
    void remove_right_white_space(std::string &text);
    void rm_border_space(std::string &text);
    void rm_border_bracket(std::string &text);
    double calc_operator(char alpha, double number1, double number2);
    std::string get_number(std::string exp, int &i);
    
public:
    ExpressionTree();
    ~ExpressionTree();
    void insert_infix(std::string exp);
    void insert_postfix(std::string exp);
    std::string pre_order();
    std::string in_order();
    std::string post_order();
    double solve();
    void clear();
};
