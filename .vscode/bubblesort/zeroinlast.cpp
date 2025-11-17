#include<bits/stdc++.h>
using namespace std;
int main(){
 int arr[]={790,8,890,0,0,87,9,0,70};
 int n=9;
 for (int i=0;i<9;i++){
   for(int j=0;j<9;j++){
     if(arr[j]==0){
        swap(arr[j],arr[j+1]);
    }
  }
 }
 for( int i=0;i<9;i++){
    cout<<arr[i]<<endl;
 }
 
    
}