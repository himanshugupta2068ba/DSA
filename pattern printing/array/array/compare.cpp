#include<iostream>
using namespace std;
int main(){
  int a[5]={1,7,55,3,2};
//for largest finding
 int large=a[0];
  for(int i=0;i<5;i++){
    // int large=a[0];
    if(a[i]>large){
        large=a[i];
    }
  }
  cout<<large<<endl;
  int b[5]={4,5,44,77,1};
  int small=b[0],index=0,i;
  for(i=0;i<5;i++){
    if(b[i]<small){
        small=b[i];
        index=i;
    }
  }
cout<<small<<endl;
cout<<index;
}