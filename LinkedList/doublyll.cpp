#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void displayrev(Node* head){
    // Node* temp=head;
    // while(temp->next!=NULL){
    //     temp=temp->next;
    // }
    // while(temp!=NULL){
    //     cout<<temp->data<<"->";
    //     temp=temp->prev;
    // }
    if(head==NULL){
        cout<<"NULL->";
        return;
    }
    displayrev(head->next);
    cout<<head->data<<"->";
}
void insertAtHead(Node* &head,int val){
    Node* n=new Node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}
void insertAtTail(Node* &head,int val){
    Node* n=new Node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void insertAtPosition(Node* &head,int pos,int val){
    Node* temp=head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(head,val);
        return;
    }
    Node* n=new Node(val);
    n->next=temp->next;
    temp->next->prev=n;
    temp->next=n;
    n->prev=temp;
}
void deleteAtHead(Node* &head){
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}
void deleteAtTail(Node* &head){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    delete temp;
}
void deleteAtPosition(Node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    Node* temp=head;
    int count=1;
    while(count<pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
  
}
int main(){
    Node*a =new Node(10);
    Node*b =new Node(20);
    Node*c =new Node(30);
    Node*d =new Node(40);
    Node*e =new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    a->prev = b;
    b->prev = c;
    c->prev = d;
    d->prev = e;
    insertAtHead(a,5);
    display(a);
    displayrev(a);
}