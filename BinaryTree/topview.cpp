#include<iostream>
#include<climits>
#include<queue>
#include<vector>
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

void HorLevel(Node* root,int& minlevel,int& maxlevel,int level){
       if(root==NULL){
        return;
    }
    minlevel=min(minlevel,level);
    maxlevel=max(maxlevel,level);
    cout<<root->data<<" ";
    HorLevel(root->left,minlevel,maxlevel,level-1);
    HorLevel(root->right,minlevel,maxlevel,level+1);
} 
void topview(vector<int>& top,Node* root,int level){
    if(root==NULL) return;
    if(top[level]==INT_MIN) top[level]=root->data;
    topview(top,root->left,level-1);
    topview(top,root->right,level+1);
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,9,INT_MIN};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=construct(arr,n);
    levelOrder(root);
    int minlevel=0;
    int maxlevel=0;
    HorLevel(root,minlevel,maxlevel,0);
    int horlevel=maxlevel-minlevel+1;
    vector<int>top(horlevel,-1);
    topview(top,root,-minlevel);
    for(int i=0;i<horlevel;i++){
       cout<<top[i]<<" ";
    }
}