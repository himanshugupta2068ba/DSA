#include <iostream>
#include <vector>
using namespace std;

// Function to reduce a number to its digit root
int digitRoot(int n) {
    while (n >= 10) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> magicNumbers;

    for (int i = m; i <= n; i++) {
        if (digitRoot(i) == 1) {
            magicNumbers.push_back(i);
        }
    }

    cout << magicNumbers.size() << endl;
    for (int num : magicNumbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
