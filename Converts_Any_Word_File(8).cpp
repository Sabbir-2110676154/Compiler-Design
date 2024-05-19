#include <iostream>
#include <string>
#include <regex>
#include <unordered_set>

enum TokenType {
    KEYWORD,
    IDENTIFIER,
    ARITHMETIC_OPERATOR,
    RELATIONAL_OPERATOR,
    LOGICAL_OPERATOR,
    ASSIGNMENT_OPERATOR,
    INTEGER,
    FLOAT,
    INVALID
};

std::unordered_set<std::string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

std::unordered_set<std::string> arithmeticOperators = {
    "+", "-", "*", "/"
};

std::unordered_set<std::string> relationalOperators = {
    "==", "!=", ">", "<", ">=", "<="
};

std::unordered_set<std::string> logicalOperators = {
    "&&", "||", "!"
};

std::unordered_set<std::string> assignmentOperators = {
    "=", "+=", "-=", "*=", "/="
};

bool isInteger(const std::string& token) {
    std::regex integerRegex(R"([0-9]+)");
    return std::regex_match(token, integerRegex);
}

bool isFloat(const std::string& token) {
    std::regex floatRegex(R"([0-9]+\.[0-9]+)");
    return std::regex_match(token, floatRegex);
}

TokenType getTokenType(const std::string& token) {
    if (keywords.count(token) > 0) {
        return KEYWORD;
    } else if (arithmeticOperators.count(token) > 0) {
        return ARITHMETIC_OPERATOR;
    } else if (relationalOperators.count(token) > 0) {
        return RELATIONAL_OPERATOR;
    } else if (logicalOperators.count(token) > 0) {
        return LOGICAL_OPERATOR;
    } else if (assignmentOperators.count(token) > 0) {
        return ASSIGNMENT_OPERATOR;
    } else if (isInteger(token)) {
        return INTEGER;
    } else if (isFloat(token)) {
        return FLOAT;
    } else {
        return IDENTIFIER;
    }
}

int main() {
    std::string input;
    std::cout << "Enter a word of a C++ program: ";
    std::cin >> input;

    TokenType type = getTokenType(input);

    std::cout << "Token type: ";
    switch (type) {
        case KEYWORD:
            std::cout << "Keyword";
            break;
        case IDENTIFIER:
            std::cout << "Identifier";
            break;
        case ARITHMETIC_OPERATOR:
            std::cout << "Arithmetic Operator";
            break;
        case RELATIONAL_OPERATOR:
            std::cout << "Relational Operator";
            break;
        case LOGICAL_OPERATOR:
            std::cout << "Logical Operator";
            break;
        case ASSIGNMENT_OPERATOR:
            std::cout << "Assignment Operator";
            break;
        case INTEGER:
            std::cout << "Integer";
            break;
        case FLOAT:
            std::cout << "Float";
            break;
        default:
            std::cout << "Invalid";
            break;
    }

    std::cout << std::endl;

    return 0;
}
