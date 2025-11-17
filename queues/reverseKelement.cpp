#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reverseK(queue<int> &q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) {
        return; // Invalid case
    }

    stack<int> s;

    // Step 1: Push first k elements into the stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue the elements from the stack back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining elements to the back of the queue
    int size = q.size();
    for (int i = 0; i < size - k; i++) {
        q.push(q.front());
        q.pop();
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

    reverseK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
    }