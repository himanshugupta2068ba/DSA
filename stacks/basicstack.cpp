#include<iostream>
#include<stack>
using namespace std;

void pushElements(stack<int>& st) {
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
}

void printStack(stack<int> st) {
    cout << "Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void printStackReverse(stack<int> st) {
    stack<int> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    cout << "Stack (bottom to top): ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void reverseStackWithStack(stack<int>& st) {
    stack<int> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    st = temp;
}

void reverseStackWithArray(stack<int>& st) {
    int n = st.size();
    int* arr = new int[n];
    int i = 0;
    while (!st.empty()) {
        arr[i++] = st.top();
        st.pop();
    }
    for (int j = 0; j < n; j++) {
        st.push(arr[j]);
    }
    delete[] arr;
}

void pushAtBottom(stack<int>& st, int val) {
    stack<int> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}
void pushatindex(stack<int>& st, int index, int val) {
    if (index < 0 || index > st.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    pushAtBottom(st, val);
    while (index > 0) {
        int temp = st.top();
        st.pop();
        pushAtBottom(st, temp);
        index--;
    }
}

int main() {
    stack<int> st;
    cout << "Initial stack size: " << st.size() << endl;

    pushElements(st);
    cout << "After pushing elements: ";
    printStack(st);

    cout << "After printing in reverse: ";
    printStackReverse(st);

    reverseStackWithStack(st);
    cout << "After reversing with stack: ";
    printStack(st);

    reverseStackWithArray(st);
    cout << "After reversing with array: ";
    printStack(st);

    pushAtBottom(st, 99);
    cout << "After pushing 99 at bottom: ";
    printStack(st);

    return 0;
}