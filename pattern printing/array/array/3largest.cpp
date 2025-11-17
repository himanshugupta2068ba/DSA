#include<bits/stdc++.h>
using namespace std;
int main(){
     int max1=INT_MIN;
    int max2=INT_MIN;
    int max3=INT_MIN;
    int a[]={1,2,4,6,4,78,8,5,9};
    for(int i=0;i<9;i++){
       if(a[i]>=max1){
        max3=max2;
        max2=max1;
        max1=a[i];
       }
       else if(a[i]>=max2){
        max3=max2;
        max2=a[i];
       }
       else if(a[i]>=max3){
        max3=a[i];
       }
    }
    cout<<max1<<" "<<max2<<" "<<max3;

}