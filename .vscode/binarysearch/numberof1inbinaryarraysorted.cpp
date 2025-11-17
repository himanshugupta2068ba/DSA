#include<iostream>
using namespace std;
int main(){
    int a[]={0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int n=16;
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==1){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    cout<<"number of 1 in array is "<<n-ans;
}