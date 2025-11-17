#include<iostream>
#include<climits>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void Inorder(Node* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Postorder(Node* root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
  cout<<root->data<<" ";
}
void nthLevel(Node* root,int curr,int level){
    if(root==NULL){
        return;
    }
    if(curr==level){
        cout<<root->data<<" ";
        return;
    }
    nthLevel(root->left,curr+1,level);
    nthLevel(root->right,curr+1,level);
}
int levels(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(levels(root->left),levels(root->right));
}
void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    int n=levels(root);
for(int i=0;i<n;i++){
        nthLevel(root,0,i);
        cout<<endl;
    }
}
int main(){
    Node* root=new Node(1);
    Node* a=new Node(2);
    Node* b=new Node(3);
    Node* c=new Node(4);
    Node* d=new Node(5);
    Node* e=new Node(6);
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->right=e;
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->left->data<<endl;
    cout<<root->right->right->data<<endl;
    preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    nthLevel(root,0,2);
    cout<<endl;
    return 0;

}