#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={23,345,4534,3323,332};
    //    int min=INT_MIN;
   for(int i=0;i<5;i++){
    int min=INT_MAX;
    while(i<5){
        if(a[i]<min){
            min=a[i];
        } 
        i++;  
      }
      a[i]=min;
    }
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
}