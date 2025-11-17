#include<iostream>
using namespace std;
int main(){
    int a[]={3,5,7,9,10,90,100,130,140,160,170};
    int target=10;
    int low=0;
    int high=1;
    while(a[high]<target){
        low=high;
        high=high*2;
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==target){
            cout<<"element found at index "<<mid;
            return 0;
        }
        else if(a[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<"element not found";
    return 0;
}