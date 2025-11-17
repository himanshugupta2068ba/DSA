#include <climits>
#include<iostream>
using namespace std;
void maximum(int arr[],int n,int idx,int max){
    if(idx==n){
        cout<<max;
        return;
    }
    if(arr[idx]>max) max=arr[idx];
    maximum(arr,n,idx+1,max);
}
int main(){
    int arr[5]={7,8,3,17,18};
    maximum(arr,5,0,INT_MIN);
}