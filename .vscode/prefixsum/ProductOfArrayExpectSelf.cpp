//leetcode238
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    int n=arr.size();
    int product;
    int p2;
    int noz=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) noz++;
        product*=arr[i];
        if(arr[i]!=0) p2*=arr[i];
    }
    if(noz>1) p2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) arr[i]=p2;
        else arr[i]=product/arr[i]; 
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}