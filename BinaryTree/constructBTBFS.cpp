#include<iostream>
#include<queue>
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
Node* construct(int arr[],int n){
    queue<Node*>q;
    Node* root=new Node(arr[0]);
    q.push(root);
   int i=1;
   int j=2;
   while(!q.empty() && i<n){
    Node* temp=q.front();
    q.pop();
    Node* l;
    Node* r;
    if(arr[i]!=INT_MIN ){
        l=new Node(arr[i]);
   }
   else l=NULL;
    if(j<n && arr[j]!=INT_MIN){
          r=new Node(arr[j]);
    }
    else r=NULL;
    temp->left=l;
    temp->right=r;
    if(l!=NULL) q.push(l);
    if(r!=NULL) q.push(r);
    i+=2;
    j+=2;
}
return root;
      
}
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
}
void display(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=construct(arr,n);
    display(root);
    cout<<endl;
    levelOrder(root);
    return 0;
}