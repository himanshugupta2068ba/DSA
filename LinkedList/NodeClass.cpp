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

int main(){
  Node a(10);
  Node b(20);
  Node c(30);
  Node d(40);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  
  Node temp = a; 
  while(1){
    cout << "Value: " << temp.val << endl;
    if(temp.next==nullptr) break;
    temp = *temp.next;
  }
  // cout << "Value of a: " << a.val << endl;
  // cout << "Value of b: " << a.next->val << endl; //*(a.next)
  // cout << "Value of c: " << a.next->next->val << endl; //*(a.next->next)
  // cout << "Value of d: " << a.next->next->next->val << endl; //*(a.next->next->next) 

  return 0;
}