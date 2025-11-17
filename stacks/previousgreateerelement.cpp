#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> PreviousGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i <n; i++) {
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
    vector<int> result = PreviousGreaterElement(nums);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;

}