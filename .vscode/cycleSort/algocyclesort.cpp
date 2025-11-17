#include<iostream>
using namespace std;
int main(){
    int arr[]={1,4,5,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
    int i=0;
    while(i<n){
        int correctIndex = arr[i] - 1; // Calculate the correct index for the current element
        if(arr[i] != arr[correctIndex]){ // If the current element is not in the correct position
            swap(arr[i], arr[correctIndex]); // Swap it with the element at its correct index
        } else {
            i++; // Move to the next element if the current one is in the correct position
        }
    }
}
