#include<iostream>
using namespace std;
int main (){
    int a[]={1,2,3,4,5,5,6,7,8,9};
    int n=10;
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]!=mid+1){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    if(ans!=-1){
        cout<<"repeated element is "<<a[ans];
    }
    else{
        cout<<"no element is repeated";
    }

}