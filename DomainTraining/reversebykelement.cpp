#include<iostream>
using namespace std;
void reverseKelement(int arr[],int size,int k){
    if(k==0) return;
    k=k%size;
    int i=0;
    int j=size-1;
    while(i<k){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}
int main(){
    int arr[]={1,2,3,4,567,8,9,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    reverseKelement(arr,n,3);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}