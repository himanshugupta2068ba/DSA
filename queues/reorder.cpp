#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reorderQueue(queue<int> &q) {
    stack<int> s;
    int n = q.size();
    
    //pop 1st ha;lf elements and push them onto stack
    for(int i = 0; i < n/2; i++) {
        s.push(q.front());
        q.pop();
    }
    //empty stack elements back to queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    //pop 2nd half elements and push them onto stack
    for(int i = 0; i < n/2; i++) {
        s.push(q.front());
        q.pop();
    }
    //interleave elements of stack and queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

}
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    reorderQueue(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}