#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10];
    int x;
    cout<<"enter number in array";
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    cout<<"enter number x";
    cin>>x;
    int count=0;
    // for(int i=0;i<10;i++){
    //     for(int j=i+1;j<10;j++){
    //         for(int k=j+1;k<10;k++){
    //             if(a[i]+a[j]+a[k]==x){
    //                 count++;
    //                 cout<<a[i]<<" "<<a[j]<<" "<<a[k];
    //             }
    //         }
    //     }
    // }
    sort(a,a+10);
    for(int i=0;i<10;i++){
        int target =x-a[i];
        int left=i+1;
        int right=10-1;
        while(left<right){
            int sum=a[left]+a[right];
            if(sum==target){
                cout<<a[i]<<" "<<a[left]<<" "<<a[right];
                
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
    }
}
