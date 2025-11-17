#include<bits/stdc++.h>
using namespace std;
int second_largest(int a[],int n){
    int max1=INT_MIN;
    int max2=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>max1){
            max2=max1;
            max1=a[i];
        }
        else if(max2<a[i] and a[i]!=max1){
            max2=a[i];
        }
    }
    return max2;
}
