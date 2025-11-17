#include <bits/stdc++.h>
using namespace std;

// Convert Postfix → Infix
string postfixToInfix(string postfix) {
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If operand, push as string
        if (isalnum(c)) {
            string op(1, c); // convert char to string
            st.push(op);
        }
        // If operator, pop two and combine
        else {
            string val1 = st.top(); st.pop();
            string val2 = st.top(); st.pop();
            string expr = "(" + val2 + c + val1 + ")";
            st.push(expr);
        }
    }
    return st.top();
}

int main() {
    string postfix = "264*8/+3-"; // Example: from earlier
    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << postfixToInfix(postfix) << endl;
}
 