#include <bits/stdc++.h>
using namespace std;

// Convert Prefix → Postfix
string prefixToPostfix(string prefix) {
    stack<string> st;

    // Traverse from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // If operand, push it
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        // If operator, pop two operands
        else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string expr = a + b + c; // operand1 + operand2 + operator
            st.push(expr);
        }
    }
    return st.top();
}

int main() {
    string prefix = "-+2/*6483"; // Example expression
    cout << "Prefix: " << prefix << endl;
    cout << "Postfix: " << prefixToPostfix(prefix) << endl;
}
