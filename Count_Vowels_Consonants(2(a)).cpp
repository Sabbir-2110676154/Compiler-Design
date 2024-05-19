#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int vowelCount = 0, consonantCount = 0;

    for (char ch : str) {
        ch = tolower(ch);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
    }

    cout << "Number of vowels: " << vowelCount << endl;
    cout << "Number of consonants: " << consonantCount << endl;

    return 0;
}
