#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& v, int low, int mid, int high) {
    vector<int> temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;

    // Merge the two sorted halves
    while (i <= mid && j <= high) {
        if (v[i] <= v[j]) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }

    // Copy remaining elements from left half
    while (i <= mid) temp[k++] = v[i++];

    // Copy remaining elements from right half
    while (j <= high) temp[k++] = v[j++];

    // Copy merged result back into original array
    for (int t = 0; t < temp.size(); t++) {
        v[low + t] = temp[t];
    }
}

void mergesort(vector<int>& v, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(v, low, mid);
        mergesort(v, mid + 1, high);
        merge(v, low, mid, high);
    }
}

int main() {
    vector<int> arr = {8, 3, 4, 12, 5, 6};
    mergesort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
}
