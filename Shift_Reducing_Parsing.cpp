#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to perform shift operation
void shift(stack<char>& st, string& input, int& inputIndex) {
    st.push(input[inputIndex]);
    inputIndex++;
}

// Function to perform reduce operation
void reduce(stack<char>& st) {
    // Rule to reduce: A -> XY
    if (st.size() >= 2) {
        char X = st.top();
        st.pop();
        char Y = st.top();
        st.pop();
        st.push('A');

        cout << "Reduced: A -> " << X << Y << endl;
    } else {
        cout << "Error: Cannot perform reduce operation" << endl;
    }
}

// Function to perform parsing
void parse(string input) {
    // Initialize stack with start symbol
    stack<char> st;
    st.push('$');
    st.push('A');

    int inputIndex = 0;

    while (st.top() != '$') {
        if (st.top() == input[inputIndex]) {
            cout << "Shifted: " << st.top() << endl;
            shift(st, input, inputIndex);
        } else {
            cout << "Reduced: " << st.top() << endl;
            reduce(st);
        }
    }

    cout << "Parsing completed" << endl;
}

int main() {
    string input;
    cout << "Enter input string: ";
    cin >> input;

    parse(input);

    return 0;
}
