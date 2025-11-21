#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
 vector<int> heap;
 int i; //i=[0,i]
 public:

void upheapify(int index){
    if(index==0){
        return;
    }
    int parent=(index-1)/2;
    if(heap[parent]<heap[index]){
        swap(heap[parent],heap[index]);
        upheapify(parent);
    }
 }

 void downheapify(int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;  // cascade down
        } else {
            break;            // no more violations → exit
        }
    }
}

 void push(int val){
    heap.push_back(val);
    upheapify(heap.size()-1);
 }
 
 bool empty(){
    return heap.size()==0;
 }

 void display(){
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
 }

 int peek(){
    if(!empty()){
        return heap[0];
    }
    return -1; // or throw an exception
 }

 MaxHeap(vector<int>& arr){
    heap=arr;
    // tc=o(n)
    for(int i=(heap.size()/2)-1;i>=0;i--){
        downheapify(i);
    }
}
};

int main(){
   vector<int> arr={9,6,1,19,3,2,8,12,5};
   MaxHeap mh(arr);
    mh.display();
    mh.push(100);
    mh.display();
    return 0;
}