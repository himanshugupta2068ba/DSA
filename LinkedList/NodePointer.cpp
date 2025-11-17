#include<iostream>
using namespace std;

class Node {  //linked list node
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};
void display(Node* head){
  while (head != nullptr) {
      cout << "Value: " << head->val << endl;
      head = head->next;
  }
  cout<<endl;
}
void displayrec(Node* head){ //recursive display
  if (head == nullptr) {
      return;
  }
  cout << "Value: " << head->val << endl;
  displayrec(head->next);
}
void reverseDisplay(Node* head) {// reverse display
  if (head == nullptr) {
      return;
  }
  reverseDisplay(head->next);
  cout << "Value: " << head->val << endl;
}

int size(Node* head){
  int count = 0;
  Node* temp = head;
  while (temp != nullptr) {
      count++;
      temp = temp->next;
  }
  return count;
}
void insertAtEnd(Node* head, int value){
  while(head->next != nullptr) {
      head = head->next;
  }
  head->next = new Node(value);
}
int main(){
  // Node a(10);
  // Node b(20);
  // Node c(30);
  // Node d(40);
  // a.next = &b;
  // b.next = &c;
  // c.next = &d;
  
  // Node* temp = a; 
  // while(1){
  //   cout << "Value: " << temp.val << endl;
  //   if(temp.next==nullptr) break;
  //   temp = *temp.next;
  // }

    Node*a=new Node(10);
  Node*b=new Node(20);
  Node*c=new Node(30);
  Node*d=new Node(40);
 Node*e=new Node(50);
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;

  display(a);
  insertAtEnd(a, 60);
  display(a);
  // displayrec(a);
  cout << "Size: " << size(a) << endl;
 
} 