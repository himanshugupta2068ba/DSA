#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reverseKfromlast(queue<int> &q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) {
        return; // Invalid case
    }

    stack<int> s;
    int size = q.size();

    // Step 1: Move the first (size - k) elements to the back of the queue
    for (int i = 0; i < size - k; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 2: Push the last k elements into the stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 3: Enqueue the elements from the stack back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
int main() {
    queue<int> q;
    int n, k;
    cout << "Enter number of elements in the queue: ";
    cin >> n;
    cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    cout << "Enter k: ";
    cin >> k;

    reverseKfromlast(q, k);

    cout << "Queue after reversing last " << k << " elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}