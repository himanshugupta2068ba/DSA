#include<iostream>
#include<climits>
using namespace std;

int main() {
    int arr[] = {-2,0,5,-1,3,-4,6,-3,2,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    int p = -1;  // index of first negative in window
    int ans[n - k + 1];

    // Find first negative in first window
    for(int i = 0; i < k; i++) {
        if(arr[i] < 0) {
            p = i;
            break;
        }
    }

    ans[0] = (p == -1 ? 0 : arr[p]);

    int i = 1;
    int j = k;

    while(j < n) {

        // If previous negative is still inside window → use it
        if(p >= i) {
            ans[i] = arr[p];
        } 
        else {
            // Find new negative inside window
            p = -1;
            for(int x = i; x <= j; x++) {
                if(arr[x] < 0) {
                    p = x;
                    break;
                }
            }
            ans[i] = (p == -1 ? 0 : arr[p]);
        }

        i++;
        j++;
    }

    // Print results
    for(int x = 0; x <= n-k; x++) {
        cout << ans[x] << " ";
    }

    return 0;
}
// This code finds the first negative integer in each window of size k in the given array.