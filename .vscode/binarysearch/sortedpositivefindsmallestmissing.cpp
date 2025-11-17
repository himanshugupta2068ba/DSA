#include<iostream>
using namespace std;
int main(){
    int a[]={0,1,2,3,4,7,8,9,11,12};
    int n=10;
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==mid){
            low=mid+1;
        }
        else{
            high=mid-1;
            ans=mid;
        }
    }
    cout<<"smallest missing element is "<<ans;  
}