#include<iostream>
using namespace std;
int sum(int n){
  if(n==0) return 0;
  return n+sum(n-1);
}
// void printa(int i,int n){
//    if(i>n) return;
//    cout<<i<<endl;
//    printa(i+1,n);
// }
int main(){
   int n;
   cin>>n;
    // printa(1,n);
    cout<<endl;
    cout<<"hello";
    cout<<sum(n);
}