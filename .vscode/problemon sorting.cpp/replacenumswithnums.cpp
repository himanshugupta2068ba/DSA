//replace minimum number with 0,1,2,3,... as they are min
#include<bits/stdc++.h>
using namespace std;
int main(){
    // int a[]={434,4,5,344,3};
    // int n=5;
    // vector<int>v(n,0);
    // for(int i=0;i<n;i++){
    //      int min=INT_MAX;
    // int mindex=-1;
    // for(int j=0;j<n;j++){
    //     if(v[j]==1) continue;
    //     else{
    //         if(a[j]<min){
    //             min = a[j];mindex=j;
    //         }
    //     }
    // }
    // a[mindex]=i;
    // v[mindex]=1;
    // }
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }


    //we can also use negative mapping instead of vector
     int a[]={8,4,5,344,3};
    int n=5;
    for(int i=0;i<n;i++){
         int min=INT_MAX;
    int mindex=-1;
    for(int j=0;j<n;j++){
        if(a[j]<=0) continue;
        else{
            if(a[j]<min){
                min = a[j];mindex=j;
            }
        }
    }
    a[mindex]=-i;
    }
    for(int i=0;i<n;i++){
        cout<<-a[i]<<" ";
    }
}