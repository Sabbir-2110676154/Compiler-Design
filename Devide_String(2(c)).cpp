#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

bool startsWithVowel(const string& word) {
    char firstChar = tolower(word[0]);
    return (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u');
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    vector<string> vowelWords;
    vector<string> consonantWords;

    stringstream ss(str);
    string word;
    while (ss >> word) {
        if (isalpha(word[0])) {
            if (startsWithVowel(word)) {
                vowelWords.push_back(word);
            } else {
                consonantWords.push_back(word);
            }
        }
    }

    cout << "Words starting with vowels:" << endl;
    for (const string& vowelWord : vowelWords) {
        cout << vowelWord << endl;
    }

    cout << "Words starting with consonants:" << endl;
    for (const string& consonantWord : consonantWords) {
        cout << consonantWord << endl;
    }

    return 0;
}
