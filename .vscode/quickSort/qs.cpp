#include<iostream>
using namespace std;
int partition(int arr[], int si, int ei) {
    int pivot = arr[si];
    //ranodmized pivot tosafe from worst case
    // int pivot=arr[(si+ei)/2];
    //change loop according to it
    int count=0;
    for(int i=si+1;i<=ei;i++){
        if(arr[i]<=pivot) count++;
    }
    int pivotIndex = si + count; // Find the correct position for the pivot
    swap(arr[pivotIndex], arr[si]);
    int i=si;
    int j=ei;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot && i<pivotIndex) i++;
        while(arr[j]>pivot && j>pivotIndex) j--;
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex; // Return the index of the pivot after partitioning
}
void quickSort(int arr[],int si,int ei){
    if(si>=ei) return; // Base case: if the start index is greater than the end index
    // Recursive case: sort the array
    int pi=partition(arr, si, ei);
    quickSort(arr, si, pi - 1);
    quickSort(arr, pi + 1, ei);
}

int main(){
    int arr[]={5, 2, 9, 1, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
    quickSort(arr, 0, n-1);
      cout << "Sorted array: \n";
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
}