#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string letters;
    string digits;
    string others;

    for (char ch : str) {
        if (isalpha(ch)) {
            letters += ch;
        } else if (isdigit(ch)) {
            digits += ch;
        } else if (!isspace(ch)) {
            others += ch;
        }
    }

    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Others: " << others << endl;

    return 0;
}
