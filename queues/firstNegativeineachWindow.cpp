#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> firstNegativeInWindow(const vector<int>& arr, int k) {
    vector<int> result;
    queue<int> negIndices; // Queue to store indices of negative numbers

    for (int i = 0; i < arr.size(); i++) {
        // Remove indices that are out of the current window
        if (!negIndices.empty() && negIndices.front() < i - k + 1) {
            negIndices.pop();
        }

        // If the current element is negative, add its index to the queue
        if (arr[i] < 0) {
            negIndices.push(i);
        }

        // Once we have processed the first k elements, start recording results
        if (i >= k - 1) {
            if (!negIndices.empty()) {
                result.push_back(arr[negIndices.front()]); // First negative in the window
            } else {
                result.push_back(0); // No negative number in the window
            }
        }
    }

    return result;
}
int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    vector<int> vec(arr, arr + n);
    vector<int> negatives = firstNegativeInWindow(vec, k);
    cout << "First negative numbers in each window of size " << k << " are: ";
    for (int num : negatives) {
        cout << num << " ";
    }

}