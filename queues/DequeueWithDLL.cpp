#include <iostream>
using namespace std;

// Node of Doubly Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = next = NULL;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    // Insert at front
    void push_front(int x) {
        Node* temp = new Node(x);
        if (isEmpty()) {
            front = rear = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }

    // Insert at rear
    void push_back(int x) {
        Node* temp = new Node(x);
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    // Delete front
    void pop_front() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front) front->prev = NULL;
        else rear = NULL; // if only one element
        delete temp;
    }

    // Delete rear
    void pop_back() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = NULL;
        else front = NULL; // if only one element
        delete temp;
    }

    // Get front
    int get_front() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return front->data;
    }

    // Get rear
    int get_back() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return rear->data;
    }

    // Display
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Driver
int main() {
    Deque dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.display();   // 5 10 20

    dq.pop_front();
    dq.display();   // 10 20

    dq.pop_back();
    dq.display();   // 10

    cout << "Front: " << dq.get_front() << endl;
    cout << "Back: " << dq.get_back() << endl;

    return 0;
}
