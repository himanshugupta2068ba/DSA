#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class using Linked List
class Queue {
private:
    Node* head; // front
    Node* tail; // back
public:
    Queue() {
        head = tail = nullptr;
    }

    // push -> insert at back
    void push(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) { // if empty
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    // pop -> remove from front
    void pop() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
    }

    // front -> return first element
    int front() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return head->data;
    }

    // back -> return last element
    int back() {
        if (tail == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return tail->data;
    }

    // empty -> check if queue is empty
    bool empty() {
        return head == nullptr;
    }

    // display -> print all elements
    void display() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = head;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Driver code
int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();   // Queue: 10 20 30
    cout << "Front: " << q.front() << "\n";  // 10
    cout << "Back: " << q.back() << "\n";    // 30

    q.pop();
    q.display();   // Queue: 20 30

    cout << (q.empty() ? "Empty\n" : "Not Empty\n");

    return 0;
}
//advantage
// unlimited size_t
//natural implmentation
