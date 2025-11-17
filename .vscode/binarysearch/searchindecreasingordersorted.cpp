#include<iostream>
using namespace std;
int main(){
    int a[]={9,8,7,6,5,4,3,2,1};
    int n=9;
    int target=10;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==target){
            cout<<"element found at index "<<mid;
            return 0;
        }
        else if(a[mid]>target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"element not found";
}