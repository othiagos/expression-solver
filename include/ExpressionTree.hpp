#pragma once

#include <iostream>
#include <sstream>

#include "ITree.hpp"
#include "ArrayQueue.hpp"
#include "Util.hpp"

class Node {
private:
    std::string item;
    Node *left;
    Node *right;

public:
    Node() {   
        left = nullptr;
        right = nullptr;
    }

    friend class ExpressionTree;
};

class ExpressionTree : public ITree<std::string> {
private:
    Node *_root;
    bool _open_bracket;

    Node *get_root() {
        return this->_root;
    }

    bool get_open_bracket() {
        return this->_open_bracket;
    }

    void set_root(Node *new_root) {
        this->_root = new_root;
    }

    void set_open_bracket(bool bracket) {
        this->_open_bracket = bracket;
    }

    void insert_recursive(Node* &node, std::string item) {
        if (util::is_separator(item.c_str()[0])) {
            set_open_bracket(util::round_bracket(item.c_str()[0]));
        } else if (node == nullptr) {
            node = new Node();
            node->item = item;
        } else {
            if (util::is_number(node->item.c_str()[0]))
                //
                insert_recursive(node->left, item);
            else
                insert_recursive(node->right, item);
        }
    }

    void clear_recursive(Node *node) {
        if (node != nullptr) {
            clear_recursive(node->left);
            clear_recursive(node->right);
            delete node;
        }
    }

    std::string pre_order(Node* node) {
        std::string str = "";
        if (node != nullptr) {
            str.append(node->item).append(" ");
            str.append(pre_order(node->left));
            str.append(pre_order(node->right));
        }
        return str;
    }

    std::string in_order(Node* node) {
        std::string str = "";
        if (node != nullptr) {
            str.append(in_order(node->left));
            str.append(node->item).append(" ");
            str.append(in_order(node->right));
        }
        return str;
    }

    std::string post_order(Node* node) {
        std::string str = "";
        if (node != nullptr) {
            str.append(post_order(node->left));
            str.append(post_order(node->right));
            str.append(node->item).append(" ");
        }
        return str;
    }

    std::string bfs() {
        std::string str;
        ArrayQueue<Node*> queue;
        queue.enqueue(get_root());
        Node *node = nullptr;

        while (!queue.is_empty()) {
            node = queue.dequeue();
            if (node != nullptr) {
                str.append(node->item).append(" ");
                queue.enqueue(node->left);
                queue.enqueue(node->right);
            }
        }
        return str;
    }
    
public:
    ExpressionTree() {
        this->_root = nullptr;
        this->_open_bracket = false;
    }

    ~ExpressionTree() {
        clear();
    }

    void insert(std::string item) override {
        insert_recursive(this->_root, item);
    }

    std::string print(int type) {
        switch (type) {
        case 0:
            return pre_order(get_root());
        case 1:
            return in_order(get_root());
        case 2:
            return post_order(get_root());
        case 3: 
            return bfs();
        }
        return "";
    }

    void clear() override {
        clear_recursive(get_root());
        set_root(nullptr);
    }
};
