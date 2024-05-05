#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int vowelCount[5] = {0}; // Array to store vowel counts (a, e, i, o, u)
    int consonantCount = 0;

    for (char ch : str) {
        ch = tolower(ch);
        if (isalpha(ch)) {
            if (ch == 'a')
                vowelCount[0]++;
            else if (ch == 'e')
                vowelCount[1]++;
            else if (ch == 'i')
                vowelCount[2]++;
            else if (ch == 'o')
                vowelCount[3]++;
            else if (ch == 'u')
                vowelCount[4]++;
            else
                consonantCount++;
        }
    }

    cout << "Vowel Counts:" << endl;
    cout << "a: " << vowelCount[0] << endl;
    cout << "e: " << vowelCount[1] << endl;
    cout << "i: " << vowelCount[2] << endl;
    cout << "o: " << vowelCount[3] << endl;
    cout << "u: " << vowelCount[4] << endl;

    cout << "Consonant Count: " << consonantCount << endl;

    return 0;
}
