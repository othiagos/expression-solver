#pragma once

#include <iostream>
#include <string>
#include <string>

#include "ParserExcp.hpp"
#include "ArrayStack.hpp"
#include "Util.hpp"

#define MIN_NUMBER 2

class Parser {
private:
    static void is_valid(std::string exp);

public:
    static void is_infix(std::string exp);
    static void is_postfix(std::string exp);
};
