//check if array is partitioned into two contiguous subarrays of equal sum
#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,5,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
    for(int i=1;i<n;i++){
        arr[i] = arr[i] +arr[i-1]; 
    }
    cout<<endl;
    int sum = arr[n-1];
    for(int i=0;i<n-1;i++){
        if(arr[i] == sum - arr[i]){
            cout<<"Array is partitioned at index "<<i<<endl;
            return 0;
        }
    }
    cout<<"Array is not partitioned"<<endl;
    return 0;
}