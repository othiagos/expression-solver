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

void ExpressionTree::insert_infix(Node* node) { 
    std::string exp;
    std::string l_str;
    std::string r_str;
    Node* l_node;
    Node* r_node;

    if (node != nullptr) {
        util::rm_bracket_border(node->item);
        util::rm_border_space(node->item);
    }

    if (node != nullptr && node->item.find(" ") != std::string::npos) {
        exp = node->item;
        node->item = "";

        //procura os operadores de menor precedência '+', '-'
        int close_bracket = 0;
        for (int i = exp.length() - 1; i >= 0; i--) {
            if (exp[i] == ')')
                close_bracket++;
            if (exp[i] == '(')
                close_bracket--;

            if ((exp[i] == '+' || exp[i] == '-') && close_bracket == 0) {
                node->item = exp[i];
                l_str = exp.substr(0, i);
                r_str = exp.substr(i + 1, exp.length() - i + 1);

                util::rm_border_space(l_str);
                util::rm_border_space(r_str);
                break;
            }
        }
        //procura os operadores de maior precedência 'x', '/'
        if (node->item == "") {
            for (int i = exp.length() - 1; i >= 0; i--) {
                if (exp[i] == ')')
                    close_bracket++;
                if (exp[i] == '(')
                    close_bracket--;
                if ((exp[i] == 'x' || exp[i] == '/') && close_bracket == 0) {
                    node->item = exp[i];
                    l_str = exp.substr(0, i);
                    r_str = exp.substr(i + 1, exp.length() - i + 1);

                    util::rm_border_space(l_str);
                    util::rm_border_space(r_str);
                    break;
                }
            }
        }

        if (node->item == "") {
            l_node = r_node = nullptr;
        }
        else {
            l_node = new Node();
            r_node = new Node();

            l_node->item = l_str;
            r_node->item = r_str;

            node->left = l_node;
            node->right = r_node;
        }

        insert_infix(node->left);
        insert_infix(node->right);
    }
}

double ExpressionTree::solve(Node *node) {
    if (node != nullptr) {
        if (util::is_operator(node->item.c_str()[0]))
            return util::calc_operator(node->item.c_str()[0], solve(node->left), solve(node->right));
        util::replace_char(node->item,",", ".");
        return std::stof(node->item);
    }
    throw "error";
}

ExpressionTree::ExpressionTree() {
    this->_root = nullptr;
}

ExpressionTree::~ExpressionTree() {
    clear();
}

void ExpressionTree::insert_infix(std::string exp) {
    Node*node = new Node();
    node->item = exp;
    set_root(node);
    insert_infix(get_root());
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
}

std::string ExpressionTree::pre_order() {
    return pre_order(get_root());
}

std::string ExpressionTree::in_order() {
    return in_order(get_root());
}

std::string ExpressionTree::post_order() {
    return post_order(get_root());
}

// std::string ExpressionTree::bfs() {
    // return bfs();
// }

double ExpressionTree::solve() {
    return solve(get_root());
}

void ExpressionTree::clear() {
    clear_recursive(get_root());
    set_root(nullptr);
}

