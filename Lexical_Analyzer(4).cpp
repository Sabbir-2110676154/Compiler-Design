#include <iostream>
#include <string>
#include <regex>

enum TokenType {
    INTEGER_VARIABLE,
    SHORTINT_NUMBER,
    LONGINT_NUMBER,
    INVALID_INPUT
};

struct Token {
    TokenType type;
    std::string lexeme;
};

Token lex(const std::string& input) {
    std::regex integerVariableRegex(R"(([i-nI-N])([a-zA-Z0-9])*)");
    std::regex shortIntNumberRegex(R"(([1-9]|[1-9][0-9]|[1-9][0-9][0-9]|[1-9][0-9][0-9][0-9]))");
    std::regex longIntNumberRegex(R"(([1-9][0-9]{4,}))");

    if (std::regex_match(input, integerVariableRegex)) {
        return { INTEGER_VARIABLE, input };
    } else if (std::regex_match(input, shortIntNumberRegex)) {
        return { SHORTINT_NUMBER, input };
    } else if (std::regex_match(input, longIntNumberRegex)) {
        return { LONGINT_NUMBER, input };
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
        case INTEGER_VARIABLE:
            std::cout << "INTEGER_VARIABLE";
            break;
        case SHORTINT_NUMBER:
            std::cout << "SHORTINT_NUMBER";
            break;
        case LONGINT_NUMBER:
            std::cout << "LONGINT_NUMBER";
            break;
        case INVALID_INPUT:
            std::cout << "INVALID_INPUT";
            break;
    }

    std::cout << std::endl;
    std::cout << "Lexeme: " << token.lexeme << std::endl;

    return 0;
}
