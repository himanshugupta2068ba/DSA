#include <bits/stdc++.h>
using namespace std;

// Perform operation
int applyOp(int val1, int val2, char op) {
    if (op == '+') return val1 + val2;
    if (op == '-') return val1 - val2;
    if (op == '*') return val1 * val2;
    if (op == '/') return val1 / val2; // assume val2 != 0
    return 0;
}

// Evaluate postfix expression
int evaluatePostfix(string exp) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If operand, push to stack
        if (isdigit(c)) {
            st.push(c - '0'); // convert char → int
        }
        // Operator
        else {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            int result = applyOp(val2, val1, c);
            st.push(result);
        }
    }
    return st.top();
}

int main() {
    string postfix = "264*8/+3-";  // Example: "2+6*4/8-3" → postfix
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation Result: " << evaluatePostfix(postfix) << endl;
}
