#include<iostream>
#include<climits>
using namespace std;
// int main(){
//     int arr[]={2,4,7,5,3,434,6};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k=3;
//     int maxSum=INT_MIN;
//     int maxIdx=-1;
//     for(int i=0;i<=n-k;i++){
//         int sum=0;
//         for(int j=i;j<i+k;j++){
//             sum+=arr[j];
//         }
//         if(maxSum<sum){
//             maxSum=sum;
//             maxIdx=i;
//         }
//     }
//     cout<<maxSum<<endl;
//     cout<<maxIdx;

// }

//optimized way - sliding window
int main(){
    int arr[]={2,4,7,5,3,434,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int maxSum=INT_MIN;
    int maxIdx=-1;
    int windowSum=0;
    for(int i=0;i<k;i++){
        windowSum+=arr[i];
    }
    if(maxSum<windowSum){
        maxSum=windowSum;
        maxIdx=0;
    }
    for(int i=k;i<n;i++){
        windowSum+=arr[i]-arr[i-k];
        if(maxSum<windowSum){
            maxSum=windowSum;
            maxIdx=i-k+1;
        }
    }
    cout<<maxSum<<endl;
    cout<<maxIdx;
}