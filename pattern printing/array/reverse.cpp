#include<iostream>
using namespace std;
int main(){
    int temp,a[11]={0,1,2,3,4,5,6,7,8,9,10},i;
    for(i=0;i<5;i++){
         temp=a[i];
        a[i]=a[11-1-i];
        a[11-1-i]=temp;
        // temp=a[i];
    }
    for(i=0;i<11;i++){
        cout<<a[i]<<" ";
    }

}