#pragma once

#include <iostream>

#include "ArrayQueue.hpp"
#include "ArrayStack.hpp"
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

    Node *get_root();
    void set_root(Node *new_root);
    void clear_recursive(Node *node);
    std::string pre_order(Node* node);
    std::string in_order(Node* node);
    std::string post_order(Node* node);
    std::string bfs();
    void insert_infix(Node* node);
    double solve(Node *node);
    
public:
    ExpressionTree();
    ~ExpressionTree();
    void insert_infix(std::string exp);
    void insert_postfix(std::string exp);
    std::string pre_order();
    std::string in_order();
    std::string post_order();
    // std::string bfs();
    double solve();
    void clear();
};
