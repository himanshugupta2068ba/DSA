#include<iostream>
using namespace std;
int main(){
    int a[]={1,1,2,2,2,3,3,3,3,4,4,4,4,4};
    int n=sizeof(a)/sizeof(a[0]);
    int x=4;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==x){
            if(mid==n-1) {
                cout<<mid;
                return 0;
            }
            else if(a[mid+1]!=a[mid]){
                cout<<mid;
                return 0;
            }
            else{
                low=mid+1;
            }
        }
        else if(a[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
}