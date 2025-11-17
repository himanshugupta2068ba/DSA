#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={23,345,4534,3323,332};
    //    int min=INT_MIN;
   for(int i=0;i<5;i++){
   int min=i;
   for(int j=i+1;j<5;j++){
    if(a[j]<a[min]){
        min=j;
    }
   }
   swap(a[i],a[min]);
 }
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
}