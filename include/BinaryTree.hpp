#pragma once

#include <iostream>

#include "ITree.hpp"
#include "ArrayQueue.hpp"

template<typename U>
class Node {
private:
    U item;
    Node<U> *left;
    Node<U> *right;

public:
    Node() {   
        left = nullptr;
        right = nullptr;
    }

    template<typename T>
    friend class BinaryTree;
};

template<typename T>
class BinaryTree : public ITree<T> {
private:
    Node<T> *root;

    void insert_recursive(Node<T>* &node, T item) {
        if (node == nullptr) {
            node = new Node<T>();
            node->item = item;
        } else {
            if (item < node->item)
                insert_recursive(node->left, item);
            else
                insert_recursive(node->right, item);
        }
    }

    void clear_recursive(Node<T> *node) {
        if (node != nullptr) {
            clear_recursive(node->left);
            clear_recursive(node->right);
            delete node;
        }
    }

    void pre_order(Node<T>* node) {
        if (node != nullptr) {
            std::cout << node->item << ' ';
            pre_order(node->left);
            pre_order(node->right);
        }
    }

    void in_order(Node<T>* node) {
        if (node != nullptr) {
            in_order(node->left);
            std::cout << node->item << ' ';
            in_order(node->right);
        }
    }

    void post_order(Node<T>* node) {
        if (node != nullptr) {
            post_order(node->left);
            post_order(node->right);
            std::cout << node->item << ' ';
        }
    }

    void bfs() {
        ArrayQueue<Node<T>*> queue;
        queue.enqueue(root);
        Node<T> *node = nullptr;

        while (!queue.is_empty()) {
            node = queue.dequeue();
            if (node != nullptr) {
                std::cout << node->item << ' ';
                queue.enqueue(node->left);
                queue.enqueue(node->right);
            }
        }
    }
    
public:
    BinaryTree() {
        this->root = nullptr;
    }

    ~BinaryTree() {
        clear();
    }

    void insert(T item) override {
        insert_recursive(this->root, item);
    }

    void print(int type) {
        switch (type) {
        case 0:
            pre_order(root);
            std::cout << std::endl;
            break;

        case 1:
            in_order(root);
            std::cout << std::endl;
            break;

        case 2:
            post_order(root);
            std::cout << std::endl;
            break;
        case 3: 
            bfs();
            std::cout << std::endl;
            break;
        }
    }

    void clear() override {
        clear_recursive(this->root);
        this->root = nullptr;
    }
};
