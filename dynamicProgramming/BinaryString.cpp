//find an n digit binary string such thatno consecutive digits are 1
#include <iostream>
#include <vector>
using namespace std;
void generateBinaryStrings(int n, string str, vector<string> &result) {
    if (str.length() == n) {
        result.push_back(str);
        return;
    }

    // Append '0' and recurse
    generateBinaryStrings(n, str + "0", result);

    // Append '1' only if the last character is not '1'
    if (str.empty() || str.back() != '1') {
        generateBinaryStrings(n, str + "1", result);
    }
}
int main() {
    int n;
    cout << "Enter the length of binary strings: ";
    cin >> n;

    vector<string> result;
    generateBinaryStrings(n, "", result);

    cout << "Binary strings of length " << n << " with no consecutive 1s are:\n";
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}