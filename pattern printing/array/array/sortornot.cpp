#include<bits/stdc++.h>
using namespace std;
bool sortornot(int a[], int n){
    int flag =true;
  for(int i=0;i<n-1;i++ ){
    if(a[i]>a[i+1]){
        flag=false;
        break;
    }
  }
  return flag;
}
int main(){
    int arr[5]={124,55357,57879,564,76855,};
    if( sortornot(arr,5)){
        cout<<"sorted";
    }
    else{
        cout<<"not sorted";
    }
}