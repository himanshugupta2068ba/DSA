#include<iostream>
using namespace std;
void reverse(int arr[],int size){
    for(int i=0;i<size/2;i++){
        int temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    reverse(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}