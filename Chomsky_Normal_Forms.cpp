#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

bool is_valid_sentence(const std::string& sentence) {
    std::unordered_map<std::string, std::vector<std::string>> grammar = {
        {"S", {"SUB PRED"}},
        {"SUB", {"PN", "P"}},
        {"PRED", {"V", "V N"}},
        {"PN", {"Sagor", "Selim", "Salma", "Nipu"}},
        {"P", {"he", "she", "i", "we", "you", "they"}},
        {"N", {"book", "cow", "dog", "home", "grass", "rice", "mango"}},
        {"V", {"read", "eat", "take", "run", "write", "program with c++ code"}}
    };

    std::istringstream iss(sentence);
    std::string word;
    std::vector<std::string> words;

    while (iss >> word) {
        words.push_back(word);
    }

    std::vector<std::string> stack = {"S"};

    for (const std::string& word : words) {
        if (stack.empty()) {
            return false;
        }

        std::string top = stack.back();
        stack.pop_back();

        if (grammar.count(top) == 0) {
            return false;
        }

        const std::vector<std::string>& expansions = grammar[top];
        if (std::find(expansions.begin(), expansions.end(), word) == expansions.end()) {
            return false;
        }

        stack.insert(stack.end(), expansions.rbegin(), expansions.rend());
    }

    return stack.empty();
}

int main() {
    std::vector<std::string> sentences = {
        "Sagor read",
        "Nipu take book",
        "Selim eat book",
        "we write program with c++ code",
        "i run home",
        "Salma run cow",
        "he take mango",
        "they run rice",
        "we take dog",
        "you read grass"
    };

    for (const std::string& sentence : sentences) {
        if (is_valid_sentence(sentence)) {
            std::cout << "Valid: " << sentence << std::endl;
        } else {
            std::cout << "Invalid: " << sentence << std::endl;
        }
    }

    return 0;
}
