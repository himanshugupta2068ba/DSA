//findout the span of stock where the price is previous larger than current price
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> calculateSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> result(n);
    result[0] = 1;  // first element span is always 1   
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++) {
        // Pop elements from stack which are smaller than current price
        while (!s.empty() && prices[i] >= prices[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = i - s.top();
        }
        s.push(i);
    }
    return result;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = calculateSpan(prices);
    for (int i = 0; i < result.size(); i++) {
        cout << "The span of stock at " << i << " is " << result[i] << endl;
    }
    return 0;
}