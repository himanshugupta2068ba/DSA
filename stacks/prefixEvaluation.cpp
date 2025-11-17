#include <bits/stdc++.h>
using namespace std;

// Function to apply operator
int applyOp(int val1, int val2, char op) {
    if (op == '+') return val1 + val2;
    if (op == '-') return val1 - val2;
    if (op == '*') return val1 * val2;
    if (op == '/') return val1 / val2; // assume val2 != 0
    return 0;
}

// Evaluate Prefix Expression
int evaluatePrefix(string prefix) {
    stack<int> st;

    // Traverse right → left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isdigit(c)) {
            st.push(c - '0'); // convert char → int
        } else {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            int result = applyOp(val1, val2, c);
            st.push(result);
        }
    }
    return st.top();
}

int main() {
    string prefix = "-+2/*6483"; // Example (same expr as before)
    cout << "Prefix: " << prefix << endl;
    cout << "Evaluation Result: " << evaluatePrefix(prefix) << endl;
}
