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
void display(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
int sum(Node* root){
    if(root==NULL){
        return 0;
    }
    return root->data+sum(root->left)+sum(root->right);
}
int size(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+size(root->left)+size(root->right);
}
int maxvalue(Node* root){
    if(root==NULL){
        return INT_MIN;
    }
   return max(root->data,max(maxvalue(root->left),maxvalue(root->right)));
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int level(Node* root,int k){
    if(root==NULL){
        return -1;
    }
    if(k==0){
        return root->data;
    }
    int left=level(root->left,k-1);
    if(left!=-1){
        return left;
    }
    return level(root->right,k-1);
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
    display(root);
    cout<<endl;
    cout<<sum(root)<<endl;
    cout<<size(root)<<endl;
    cout<<maxvalue(root)<<endl;
    return 0;

}