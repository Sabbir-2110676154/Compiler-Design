#include <iostream>
#include <string>
#include <regex>

enum TokenType {
    CHARACTER_VARIABLE,
    BINARY_VARIABLE,
    BINARY_NUMBER,
    INVALID_INPUT
};

struct Token {
    TokenType type;
    std::string lexeme;
};

Token lex(const std::string& input) {
    std::regex characterVariableRegex(R"(ch_([a-zA-Z0-9])([a-zA-Z0-9])*)");
    std::regex binaryVariableRegex(R"(bn_([a-zA-Z0-9])([a-zA-Z0-9])*)");
    std::regex binaryNumberRegex(R"(0[01]+)");

    if (std::regex_match(input, characterVariableRegex)) {
        return { CHARACTER_VARIABLE, input };
    } else if (std::regex_match(input, binaryVariableRegex)) {
        return { BINARY_VARIABLE, input };
    } else if (std::regex_match(input, binaryNumberRegex)) {
        return { BINARY_NUMBER, input };
    } else {
        return { INVALID_INPUT, input };
    }
}

int main() {
    std::string input;
    std::cout << "Enter an input: ";
    std::cin >> input;

    Token token = lex(input);

    std::cout << "Token type: ";
    switch (token.type) {
        case CHARACTER_VARIABLE:
            std::cout << "CHARACTER_VARIABLE";
            break;
        case BINARY_VARIABLE:
            std::cout << "BINARY_VARIABLE";
            break;
        case BINARY_NUMBER:
            std::cout << "BINARY_NUMBER";
            break;
        case INVALID_INPUT:
            std::cout << "INVALID_INPUT";
            break;
    }

    std::cout << std::endl;
    std::cout << "Lexeme: " << token.lexeme << std::endl;

    return 0;
}
