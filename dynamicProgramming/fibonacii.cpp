#include<iostream>
#include<vector>
using namespace std;

vector<int>dp;

// top down approach
// int fibonacci(int n) {
//     if (n <= 1) return n;
//     if (dp[n] != -1) return dp[n];
//       return dp[n]=fibonacci(n - 1) + fibonacci(n - 2);
 
// }

// int main(){
//     int n;
//     cout << "Enter the position of Fibonacci number to compute: ";
//     cin >> n;
//     dp.clear();
//     dp.resize(n + 1, -1);// Initialize dp array with -1
//     int result = fibonacci(n);
//     cout << "Fibonacci number at position " << n << " is: " << result << endl;
//     return 0;
// }

// bottom up approach,iterative
int fibonacci(int n) {
    if (n <= 1) return n;
    dp.clear();
    dp.resize(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main(){
    int n=6;
    cout<<fibonacci(n);
    return 0;
}