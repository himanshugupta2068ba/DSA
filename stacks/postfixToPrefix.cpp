#include <bits/stdc++.h>
using namespace std;

// Convert Postfix → Prefix
string postfixToPrefix(string postfix) {
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If operand, push as string
        if (isalnum(c)) {
            string op(1, c);
            st.push(op);
        }
        // If operator
        else {
            string val1 = st.top(); st.pop();
            string val2 = st.top(); st.pop();
            string expr = c + val2 + val1;  // operator + operand1 + operand2
            st.push(expr);
        }
    }
    return st.top();
}

int main() {
    string postfix = "264*8/+3-";  // Example: from earlier
    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << postfixToPrefix(postfix) << endl;
}
