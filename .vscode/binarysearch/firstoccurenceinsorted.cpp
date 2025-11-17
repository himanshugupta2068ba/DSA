#include<iostream>
using namespace std;
int main(){
    int a[]={2,2,3,3,3,3,4,4,7,7,7,9,9,9};
    int n=14;
    int target=3;
    int low=0;  
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==target){
            ans=mid;
            if(a[mid-1]!=target){
                break;
            }
            high=mid-1;
        }
        else if(a[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(ans==-1){
        cout<<"element not found";
    }
    else{
        cout<<"element found at index "<<ans;
    }

}