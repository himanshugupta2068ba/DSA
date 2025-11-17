#include<iostream>
#include<stack>
using namespace std;

void displayreverse(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    cout << temp << " ";
    s.pop();
    displayreverse(s);
    s.push(temp);
}

void display(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
 
    s.pop();
    display(s);
       cout << temp << " ";
    s.push(temp);
}
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Original Stack: ";
    while (!s.empty()) {    
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    displayreverse(s);
    display(s);
    return 0;
}
