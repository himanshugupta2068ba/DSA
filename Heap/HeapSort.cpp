#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

public:

    // ------------------------
    // Upheapify
    // ------------------------
    void upheapify(int index) {
        if (index == 0) return;

        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            upheapify(parent);
        }
    }

    // ------------------------
    // Downheapify
    // ------------------------
    void downheapify(int index, int bound) {
        while (index < bound) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left >= bound) break;

            int largest = index;

            if (left < bound && heap[left] > heap[largest])
                largest = left;

            if (right < bound && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    // ------------------------
    // Push a new value
    // ------------------------
    void push(int val) {
        heap.push_back(val);
        upheapify(heap.size() - 1);
    }

    // ------------------------
    // Check if empty
    // ------------------------
    bool empty() {
        return heap.empty();
    }

    // ------------------------
    // Display heap
    // ------------------------
    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }

    // ------------------------
    // Peek max
    // ------------------------
    int peek() {
        if (!empty()) return heap[0];
        return -1;
    }

    // ------------------------
    // Build heap from array
    // ------------------------
    MaxHeap(vector<int> arr) {
        heap = arr;
        int n = heap.size();

        for (int j = (n / 2) - 1; j >= 0; j--) {
            downheapify(j, n);
        }
    }

    // ------------------------
    // Heap sort
    // ------------------------
    vector<int> heapsort() {
        int sz = heap.size();

        while (sz > 1) {
            swap(heap[0], heap[sz - 1]);
            sz--;
            downheapify(0, sz);
        }

        return heap;     // sorted in ascending order
    }
};


// ---------------------------------------------------------
// Global heapsort helper
// ---------------------------------------------------------
void heapsort(vector<int>& v) {
    MaxHeap hp(v);
    vector<int> sorted = hp.heapsort();

    cout << "Sorted array is: ";
    for (int x : sorted) cout << x << " ";
    cout << endl;
}


// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------
int main() {
    vector<int> arr = {9, 6, 1, 19, 3, 2, 8, 12, 5};

    MaxHeap mh(arr);
    mh.display();

    mh.push(25);
    mh.display();

    heapsort(arr);

    return 0;
}
