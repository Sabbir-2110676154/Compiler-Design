#include <iostream>
#include <string>
#include <regex>

enum TokenType {
    FLOAT_VARIABLE,
    FLOAT_NUMBER,
    DOUBLE_NUMBER,
    INVALID_INPUT
};

struct Token {
    TokenType type;
    std::string lexeme;
};

Token lex(const std::string& input) {
    std::regex floatVariableRegex(R"(([a-hA-Ho-zO-Z])([a-zA-Z0-9])*)");
    std::regex floatNumberRegex(R"(0\.(?:[0-9]{2}|[1-9][0-9]*\.[0-9]{2}))");
    std::regex doubleNumberRegex(R"(0\.(?:[0-9]{3,}|[1-9][0-9]*\.[0-9]{3})+)");

    if (std::regex_match(input, floatVariableRegex)) {
        return { FLOAT_VARIABLE, input };
    } else if (std::regex_match(input, floatNumberRegex)) {
        return { FLOAT_NUMBER, input };
    } else if (std::regex_match(input, doubleNumberRegex)) {
        return { DOUBLE_NUMBER, input };
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
        case FLOAT_VARIABLE:
            std::cout << "FLOAT_VARIABLE";
            break;
        case FLOAT_NUMBER:
            std::cout << "FLOAT_NUMBER";
            break;
        case DOUBLE_NUMBER:
            std::cout << "DOUBLE_NUMBER";
            break;
        case INVALID_INPUT:
            std::cout << "INVALID_INPUT";
            break;
    }

    std::cout << std::endl;
    std::cout << "Lexeme: " << token.lexeme << std::endl;

    return 0;
}
