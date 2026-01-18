//given n, find the count of n digit binary strings such that no consecutive digits are 1
#include <iostream>
using namespace std;

int countBinaryStrings(int n) {
    if (n == 1) return 2; // "0", "1"
    if (n == 2) return 3; // "00", "01", "10"
    
    int a = 2; // count for n=1
    int b = 3; // count for n=2
    int c = 0;

    for (int i = 3; i <= n; ++i) {
        c = a + b; // Fibonacci step
        a = b;     // shift window
        b = c;
    }

    return c;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Count of " << n << "-digit binary strings with no consecutive 1s: " << countBinaryStrings(n) << endl;
    return 0;
}
