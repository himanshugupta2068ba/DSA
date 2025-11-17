#include<iostream>
using namespace std;
class Node { //user defined datatype
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};
class LinkedList{ //user defined data structur
 public:
    Node* head;
    Node* tail;
    int size;

    LinkedList(){
        head=tail=nullptr;
        size=0;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void insertAtPosition(int value, int position) {
        if (position < 0 || position > size) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 0) {
            insertAtHead(value);
            return;
        }
        if (position == size) {
            insertAtEnd(value);
            return;
        }
        else{
          Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        }
    }   
   void display(){
      Node* temp = head;
      while (temp != nullptr) {
          cout << "Value: " << temp->val << endl;
          temp = temp->next;
      }
      cout<<endl;
   }
};
int getElement(LinkedList& ll, int position) {
    if (position < 0 || position >= ll.size) {
        cout << "Invalid position" << endl;
        return -1; // or throw an exception
    }
    else{
        Node* temp = ll.head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        return temp->val;
    }
}
void deleteAtPosition(LinkedList& ll, int position) {
    if (position < 0 || position >= ll.size) {
        cout << "Invalid position" << endl;
        return;
    }
    Node* temp = ll.head;
    if (position == 0) {
        ll.head = ll.head->next;
        delete temp;
    } else {
        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete == ll.tail) {
            ll.tail = temp;
        }
        delete nodeToDelete;
    }
    ll.size--;
}
int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtHead(7);
    ll.display();
    ll.insertAtPosition(15,2);
    ll.display();
    cout<<getElement(ll,0)<<endl;
    deleteAtPosition(ll,2);
    ll.display(); 
    return 0;
}