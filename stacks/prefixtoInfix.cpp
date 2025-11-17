#include <bits/stdc++.h>
using namespace std;

// Convert Prefix → Infix
string prefixToInfix(string prefix) {
    stack<string> st;

    // Traverse right → left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // If operand, push as string
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        // If operator
        else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string expr = "(" + a + c + b + ")";
            st.push(expr);
        }
    }
    return st.top();
}

int main() {
    string prefix = "-+2/*6483"; // Example
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << prefixToInfix(prefix) << endl;
}
