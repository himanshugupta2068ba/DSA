#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

class Stack {
	Node* head;
public:
	Stack() : head(nullptr) {}
	~Stack() {
		while (head) pop();
	}

	void push(int val) {
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}

	void pop() {
		if (!head) {
			cout << "Stack Underflow!\n";
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	int top() {
		if (!head) {
			cout << "Stack is empty!\n";
			return -1;
		}
		return head->data;
	}

	bool empty() {
		return head == nullptr;
	}

	void display() {
		Node* curr = head;
		cout << "Stack (top to bottom): ";
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};

int main() {
	Stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.display();
	cout << "Top: " << st.top() << endl;
	st.pop();
	st.display();
	st.pop();
	st.display();
	st.pop();
	st.display();
	st.pop(); // Underflow test
	return 0;
}