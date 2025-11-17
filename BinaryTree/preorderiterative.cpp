#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr || !st.empty()) {
        while (curr) {                 // push all left children
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();     // process node
        ans.push_back(curr->val);
        curr = curr->right;            // go right
    }
    return ans;
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* curr = st.top(); st.pop();
        ans.push_back(curr->val);

        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    return ans;
}
vector<int> postorderTraversalOneStack(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (curr || !st.empty()) {
        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* peekNode = st.top();
            if (peekNode->right && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                ans.push_back(peekNode->val);
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
    return ans;
}

//boundary traversal
void leftBoundary(TreeNode* root) {
  if(root==NULL) return;
  if(root->left==NULL && root->right==NULL) return;
  cout<<root->val<<" ";
  if(root->left) leftBoundary(root->left);
  else if(root->right) leftBoundary(root->right);
}
void bottomBoundary(TreeNode* root) {
  if(root==NULL) return;
  if(root->left==NULL && root->right==NULL){
    cout<<root->val<<" ";
    return;
  }
  bottomBoundary(root->left);
  bottomBoundary(root->right);
}
void rightBoundary(TreeNode* root) {
  if(root==NULL) return;
  if(root->left==NULL && root->right==NULL) return;
  if(root->right) rightBoundary(root->right);
  else if(root->left) rightBoundary(root->left);
  cout<<root->val<<" ";
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<int> pre=preorderTraversal(root);
    for(auto x:pre){
        cout<<x<<" ";
    }
    cout<<endl;
    vector<int> in=inorderTraversal(root);
    for(auto x:in){
        cout<<x<<" ";
    }
    cout<<endl;
    vector<int> post=postorderTraversalOneStack(root);
    for(auto x:post){
        cout<<x<<" ";
    }
    cout<<endl;
    leftBoundary(root);
    bottomBoundary(root);
    rightBoundary(root->right);
    return 0;
}