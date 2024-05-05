#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int wordCount = 0, letterCount = 0, digitCount = 0, otherCount = 0;

    for (char ch : str) {
        if (isalpha(ch)) {
            letterCount++;
        } else if (isdigit(ch)) {
            digitCount++;
        } else if (isspace(ch)) {
            wordCount++;
        } else {
            otherCount++;
        }
    }

    // If the string doesn't end with a space, increment word count.
    if (!str.empty() && !isspace(str.back())) {
        wordCount++;
    }

    cout << "Number of words: " << wordCount << endl;
    cout << "Number of letters: " << letterCount << endl;
    cout << "Number of digits: " << digitCount << endl;
    cout << "Number of other characters: " << otherCount << endl;

    return 0;
}
