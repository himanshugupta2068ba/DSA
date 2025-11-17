#include <iostream>
#include <stack>
using namespace std;
 
string reverse(string str) {
    stack<char> st;
    for (char c : str) {
        st.push(c);
    }
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}
string ConsecutiveDuplicateRemove(string str) {
    stack<char> st;
    for (char c : str) {
        if (st.empty() || st.top() != c) {
            st.push(c);
        } 
    }
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    result=reverse(result);
    return result;
}
int main() {
    string str1 = "aabcccccaaa";
    string str2 = "xyzyzz";
    cout << "Original String: " << str1 << endl;
    cout << "After removing consecutive duplicates: " << ConsecutiveDuplicateRemove(str1) << endl;
    cout << "Original String: " << str2 << endl;
    cout << "After removing consecutive duplicates: " << ConsecutiveDuplicateRemove(str2) << endl;
    return 0;
}