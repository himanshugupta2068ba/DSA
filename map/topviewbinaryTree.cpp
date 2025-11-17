#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<unordered_map>
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
    cout<<root->data<<endl;
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

void topview(Node* root){
    unordered_map<int,int>m;
    queue< pair<Node*,int> >q;
    pair<Node*,int>r;
    r.first=root;
    r.second=0;
    q.push(r);
    // m[0]=root->data;
    while(q.size()>0){
        Node* temp=(q.front()).first;
        int level=(q.front()).second;
        q.pop();
        if(m.find(level)==m.end()){
            m[level]=temp->data;
        }
        if(temp->left!=NULL){
            pair<Node*,int>p;
            p.first=temp->left;
            p.second=level-1;
            q.push(p);
        }
         if(temp->right!=NULL){
            pair<Node*,int>p;
            p.first=temp->right;
            p.second=level+1;
            q.push(p);
        }
    }
    int minlevel=INT_MAX;
    int maxlevel=INT_MIN;
    for(auto x:m){
        int level=x.first;
        minlevel=min(minlevel,level);
        maxlevel=max(maxlevel,level);
    }
    for(int i=minlevel;i<=maxlevel;i++){
        cout<<m[i];
    }
    cout<<endl;
}

int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,9,INT_MIN};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=construct(arr,n);
    levelOrder(root);
    int minlevel=0;
    int maxlevel=0;
    cout<<endl;
    topview(root);
}