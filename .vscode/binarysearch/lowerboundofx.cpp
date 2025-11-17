#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,6,7,8,9};
    int n=8;
    int target=6;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==target){
            cout<<"lower bond"<<a[mid-1]<<endl;
            cout<<"upper bond"<<a[mid+1];   
            return 0;
        }
        else if(a[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
     cout<<"lower-bond"<<a[high]<<endl;
     cout<<"upper-bond"<<a[low]<<endl;
     return 0;
}