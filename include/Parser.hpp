#pragma once

#include <iostream>
#include <string>

class Parser {
private:
public:
    Parser();
    ~Parser();

    void read(std::string input);
    void infix();
    void postfix();
    void solve();
};
