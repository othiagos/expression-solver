#include "ExpressionTree.hpp"

Node::Node() {   
    left = nullptr;
    right = nullptr;
    item = "";
}

Node *ExpressionTree::get_root() {
    return this->_root;
}

void ExpressionTree::set_root(Node *new_root) {
    this->_root = new_root;
}

bool ExpressionTree::get_has_tree() {
    return this->has_tree;
}

void ExpressionTree::set_has_tree(bool stage) {
    this->has_tree = stage;
}

void ExpressionTree::clear_recursive(Node *node) {
    if (node != nullptr) {
        clear_recursive(node->left);
        clear_recursive(node->right);
        delete node;
    }
}

std::string ExpressionTree::pre_order(Node* node) {
    std::string str = "";
    if (node != nullptr) {
        str.append(node->item).append(" ");
        str.append(pre_order(node->left));
        str.append(pre_order(node->right));
    }
    return str;
}

std::string ExpressionTree::in_order(Node* node) {
    std::string str = "";
    if (node != nullptr) {
        if (node->left != nullptr) {
            str.append("( ");
            str.append(in_order(node->left));
        }
        str.append(node->item).append(" ");
        if (node->right != nullptr) {
            str.append(in_order(node->right));
            str.append(") ");
        }
    }
    return str;
}

std::string ExpressionTree::post_order(Node* node) {
    std::string str = "";
    if (node != nullptr) {
        str.append(post_order(node->left));
        str.append(post_order(node->right));
        str.append(node->item).append(" ");
    }
    return str;
}

std::string ExpressionTree::bfs() {
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

std::string ExpressionTree::break_expression(std::string exp, std::string &lstr, std::string &rstr) {
    std::string high_op = "";
    int close_bracket = 0;

    for (int i = exp.length() - 1; i >= 0; i--) {
        if (exp[i] == ')') {
            close_bracket++;
            continue;
        }
        if (exp[i] == '(') {
            close_bracket--;
            continue;
        }

        if (close_bracket == 0) {
            if (exp[i] == '+' || exp[i] == '-') {
                lstr = exp.substr(0, i);
                rstr = exp.substr(i + 1, exp.length() - i + 1);

                util::rm_border_space(lstr);
                util::rm_border_space(rstr);
                return std::string(1, exp[i]);
            }
            if (exp[i] == 'x' || exp[i] == '/') {
                lstr = exp.substr(0, i);
                rstr = exp.substr(i + 1, exp.length() - i + 1);

                util::rm_border_space(lstr);
                util::rm_border_space(rstr);
                high_op = std::string(1, exp[i]);
            }
        }
    }
    if (high_op != "") return high_op;
    return exp;
}

void ExpressionTree::insert_recursive_infix(Node* node) { 
    std::string exp, l_str, r_str;
    Node* l_node = nullptr;
    Node* r_node = nullptr;

    if (node != nullptr) {
        util::rm_bracket_border(node->item);
        util::rm_border_space(node->item);
        exp = node->item;

        node->item = break_expression(exp, l_str, r_str);

        if (node->item != exp) {
            l_node = new Node();
            r_node = new Node();

            l_node->item = l_str;
            r_node->item = r_str;

            node->left = l_node;
            node->right = r_node;
        }
        insert_recursive_infix(node->left);
        insert_recursive_infix(node->right);
    }
}

double ExpressionTree::solve(Node *node) {
    if (node != nullptr) {
        if (util::is_operator(node->item[0]))
            return util::calc_operator(node->item[0], solve(node->left), solve(node->right));

        util::replace_char(node->item, ",", ".");
        return std::stod(node->item);
    }
    throw "error";
}

ExpressionTree::ExpressionTree() {
    this->_root = nullptr;
    this->has_tree = false;
}

ExpressionTree::~ExpressionTree() {
    clear();
}

void ExpressionTree::insert_infix(std::string exp) {
    Node*node = new Node();
    node->item = exp;
    set_root(node);
    insert_recursive_infix(get_root());
    set_has_tree(true);
}

void ExpressionTree::insert_postfix(std::string exp) {
    ArrayStack<Node*> stack;

    for (int i = 0; i < (int) exp.length(); i++) {
        if (util::is_number(exp[i])) {
            Node* node = new Node();
            node->item = util::get_number(exp, i);
            stack.push(node);
        }
        if (util::is_operator(exp[i])) {
            Node* n1 = stack.pop();
            Node* n2 = stack.pop();
            Node* op = new Node();

            op->item = exp[i];
            op->left = n2;
            op->right = n1;
            stack.push(op);
        } 
    }
    set_root(stack.top());
    set_has_tree(true);
}

std::string ExpressionTree::pre_order() {
    if (get_has_tree())
        return pre_order(get_root());
    throw "error";
}

std::string ExpressionTree::in_order() {
    if (get_has_tree())
        return in_order(get_root());
    throw "error";
}

std::string ExpressionTree::post_order() {
    if (get_has_tree())
        return post_order(get_root());
    throw "error";
}

// std::string ExpressionTree::bfs() {
    // if (get_has_tree())
    //     return bfs();
    // throw "error";
// }

double ExpressionTree::solve() {
    if (get_has_tree())
        return solve(get_root());
    throw "error";
}

void ExpressionTree::clear() {
    clear_recursive(get_root());
    set_root(nullptr);
    set_has_tree(false);
}

