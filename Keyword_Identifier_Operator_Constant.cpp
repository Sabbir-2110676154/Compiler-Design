#include <iostream>
#include <string>
#include <regex>
#include <unordered_set>

enum TokenType {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    CONSTANT,
    INVALID
};

std::unordered_set<std::string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

std::unordered_set<std::string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=", ">", "<", ">=", "<=", "&&", "||",
    "!", "&", "|", "^", "~", "++", "--", "+=", "-=", "*=", "/=", "%=", "<<", ">>",
    "<<=", ">>=", "&=", "|=", "^="
};

bool isIdentifier(const std::string& token) {
    std::regex identifierRegex(R"([a-zA-Z_][a-zA-Z0-9_]*)");
    return std::regex_match(token, identifierRegex);
}

bool isConstant(const std::string& token) {
    std::regex constantRegex(R"([0-9]+(\.[0-9]+)?)");
    return std::regex_match(token, constantRegex);
}

TokenType getTokenType(const std::string& token) {
    if (keywords.count(token) > 0) {
        return KEYWORD;
    } else if (isIdentifier(token)) {
        return IDENTIFIER;
    } else if (operators.count(token) > 0) {
        return OPERATOR;
    } else if (isConstant(token)) {
        return CONSTANT;
    } else {
        return INVALID;
    }
}

int main() {
    std::string input;
    std::cout << "Enter an input: ";
    std::getline(std::cin, input);

    std::string token;
    std::istringstream iss(input);

    while (iss >> token) {
        TokenType type = getTokenType(token);

        std::cout << "Token: " << token << " -> ";

        switch (type) {
            case KEYWORD:
                std::cout << "Keyword" << std::endl;
                break;
            case IDENTIFIER:
                std::cout << "Identifier" << std::endl;
                break;
            case OPERATOR:
                std::cout << "Operator" << std::endl;
                break;
            case CONSTANT:
                std::cout << "Constant" << std::endl;
                break;
            case INVALID:
                std::cout << "Invalid" << std::endl;
                break;
        }
    }

    return 0;
}//ifif
