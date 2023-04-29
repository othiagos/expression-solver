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
    return this->_has_tree;
}

void ExpressionTree::set_has_tree(bool stage) {
    this->_has_tree = stage;
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

                rm_border_space(lstr);
                rm_border_space(rstr);
                return std::string(1, exp[i]);
            }
            if (exp[i] == '*' || exp[i] == '/') {
                lstr = exp.substr(0, i);
                rstr = exp.substr(i + 1, exp.length() - i + 1);

                rm_border_space(lstr);
                rm_border_space(rstr);
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
        rm_border_bracket(node->item);
        rm_border_space(node->item);
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
    if (util::is_operator(node->item[0]))
        return calc_operator(node->item[0], solve(node->left), solve(node->right));

    util::replace_char(node->item, ",", ".");
    return std::stod(node->item);
}

void ExpressionTree::remove_left_white_space(std::string &text) {
    while (util::is_empty_space(*text.begin()))
        text.erase(text.begin());
}

void ExpressionTree::remove_right_white_space(std::string &text) {
    while (util::is_empty_space(*(text.end() - 1)))
        text.erase(text.end() - 1);
}

void ExpressionTree::rm_border_space(std::string &text) {
    remove_left_white_space(text);
    remove_right_white_space(text);
}

void ExpressionTree::rm_border_bracket(std::string &text) {
    rm_border_space(text);
    int start = -1, bracket_stage = 0;

    for (int i = 0; i < (int) text.length(); i++) {
        if (text[i] == '(') {
            if (bracket_stage == 0)
                start = i;
            bracket_stage++;
        }

        if (text[i] == ')')
            bracket_stage--;

        if (bracket_stage == 0 && start == 0 && i == (int) text.length() - 1) {
            text.erase(text.begin() + i);
            text.erase(text.begin() + start);
        }
    }
}

double ExpressionTree::calc_operator(char alpha, double n1, double n2) {
    switch (alpha) {
    case '+':
        return n1 + n2;
        break;

    case '-':
        return n1 - n2;
        break;

    case '*':
        return n1 * n2;
        break;

    case '/':
        if (n2 != 0)
            return n1 / n2;
        throw etexcp::DomainError();
        break;
    
    default:
        return 0;
        break;
    }
}

std::string ExpressionTree::get_number(std::string exp, int &i) {
    for (int j = 0; util::is_number(exp[i + j]); j++) {
        if (!util::is_number(exp[i + j + 1])) {
            std::string number = exp.substr(i, j + 1);
            i += j;
            return number;
        }
    }
    return "";
}

ExpressionTree::ExpressionTree() {
    this->_root = nullptr;
    this->_has_tree = false;
}

ExpressionTree::~ExpressionTree() {
    clear();
}

void ExpressionTree::insert_infix(std::string exp) {
    clear();
    Parser::is_infix(exp);
    Node *node = new Node();
    node->item = exp;
    set_root(node);
    insert_recursive_infix(get_root());
    set_has_tree(true);
}

void ExpressionTree::insert_postfix(std::string exp) {
    clear();
    rm_border_space(exp);
    Parser::is_postfix(exp);
    ArrayStack<Node*> stack;

    for (int i = 0; i < (int) exp.length(); i++) {
        if (util::is_number(exp[i])) {
            Node* node = new Node();
            node->item = get_number(exp, i);
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
    throw etexcp::EmptyTree();
}

std::string ExpressionTree::in_order() {
    if (get_has_tree())
        return in_order(get_root());
    throw etexcp::EmptyTree();
}

std::string ExpressionTree::post_order() {
    if (get_has_tree())
        return post_order(get_root());
    throw etexcp::EmptyTree();
}

double ExpressionTree::solve() {
    if (get_has_tree())
        return solve(get_root());
    throw etexcp::EmptyTree();
}

void ExpressionTree::clear() {
    clear_recursive(get_root());
    set_root(nullptr);
    set_has_tree(false);
}

