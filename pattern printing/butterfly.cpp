#include<iostream>
using namespace std;
int main(){
    int n=4,i,j;
   for(i=0;i<n;i++){
    for(j=0;j<i+1;j++){
        cout<<"*";
    }
    // if(i!=n-1){
        for(j=0;j<2*n-(i+2);j++){
            cout<<" ";
        }
        // cout<<"*";
        for(i=0;i<n;i++){
    for(j=0;j<i+1;j++){
        cout<<"*";
    }
        
    cout<<endl;
    }
    } 
    cout<<endl;
   

}
 
