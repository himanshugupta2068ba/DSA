#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
 vector<int> heap;
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
};

int main(){
    MaxHeap mh;
    mh.push(10);
    mh.push(20);    
    mh.push(5);
    mh.push(15);
    mh.push(30);
    mh.push(25);
    mh.push(40);
    mh.push(35);
    mh.display();
    return 0;
}