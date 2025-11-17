#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={343,35,34,4,2,};
    for(int i=1;i<5;i++){
        int j=i;
        while( j>=1 && a[j]<a[j-1]){
            swap(a[j],a[j-1]);
            j--;
        }
    }
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}