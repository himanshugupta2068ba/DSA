#include <iostream>
#include <deque>   // header file
using namespace std;

int main() {
    deque<int> dq;

    // Insert at back
    dq.push_back(10);
    dq.push_back(20);

    // Insert at front
    dq.push_front(5);
    dq.push_front(1);

    cout << "Deque elements: ";
    for (int x : dq) cout << x << " ";   // 1 5 10 20
    cout << "\n";

    // Remove from front and back
    dq.pop_front();  // removes 1
    dq.pop_back();   // removes 20

    cout << "After pop: ";
    for (int x : dq) cout << x << " ";   // 5 10
    cout << "\n";

    // Access front and back
    cout << "Front: " << dq.front() << endl;  // 5
    cout << "Back: " << dq.back() << endl;    // 10

    // Size and empty check
    cout << "Size: " << dq.size() << endl;
    cout << "Is empty? " << (dq.empty() ? "Yes" : "No") << endl;

    return 0;
}
