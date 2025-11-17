#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of array";
    cin>>n;
    vector<int>v(n);
    cout<<"enter element in array";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int target;
    cout<<"enter the target element";
    cin>>target;
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    while(low<=high){
        if(v[mid]==target){
            cout<<"element found at index "<<mid;
            break;
        }
        else if(v[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        mid=(low+high)/2;
    }

}