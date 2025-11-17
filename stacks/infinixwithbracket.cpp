#include <iostream>
#include <stack>
using namespace std;

// Function to define precedence of operators
int priority(char ch) {
    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    return 0; // '(' or invalid operators
}

// Function to perform basic arithmetic between two values
int solve(int val1, int val2, char ch) {
    if (ch == '+') return val1 + val2;
    else if (ch == '-') return val1 - val2;
    else if (ch == '*') return val1 * val2;
    else return val1 / val2;
}

int main() {
    string s = "(2+6)*4/8-3";   // input expression
    stack<int> val;             // stack for numbers
    stack<char> op;             // stack for operators

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {  
            // convert char digit to int and push
            val.push(s[i] - '0');
        } 
        else {  
            // case 1: empty stack → just push
            if (op.empty()) op.push(s[i]);

            // case 2: opening bracket → push
            else if (s[i] == '(') op.push(s[i]);

            // case 3: top is '(' → always push
            else if (op.top() == '(') op.push(s[i]);

            // case 4: higher precedence than top → push
            else if (priority(s[i]) > priority(op.top())) op.push(s[i]);

            // case 5: closing bracket → solve until '('
            else if (s[i] == ')') {
                while (op.top() != '(') {
                    char ch = op.top(); op.pop();
                    int val1 = val.top(); val.pop();
                    int val2 = val.top(); val.pop();
                    int ans = solve(val2, val1, ch); // val2 op val1
                    val.push(ans);
                }
                op.pop(); // pop the '('
            }

            // case 6: lower/equal precedence → solve until safe
            else {
                while (!op.empty() && priority(s[i]) <= priority(op.top())) {
                    char ch = op.top(); op.pop();
                    int val1 = val.top(); val.pop();
                    int val2 = val.top(); val.pop();
                    int ans = solve(val2, val1, ch); // val2 op val1
                    val.push(ans);
                }
                op.push(s[i]); // push current operator
            }
        }
    }

    // process any leftover operators
    while (!op.empty()) {
        char ch = op.top(); op.pop();
        int val1 = val.top(); val.pop();
        int val2 = val.top(); val.pop();
        int ans = solve(val2, val1, ch);
        val.push(ans);
    }

    cout << val.top(); // final result
}
