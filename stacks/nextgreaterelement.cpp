//given an array of integers,we have to return an array which contain next greater of every elemnt if not exist use -1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[i] >= s.top()) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(nums[i]);
    }
    return result;
}
int main() {
    vector<int> nums = {4, 2, 1, 3, 5};
    vector<int> result = nextGreaterElement(nums);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;

}